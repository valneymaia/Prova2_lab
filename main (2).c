#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int *vet, int n){
    int i, mudou, fim;
    fim = n-1;
    do{
        mudou = 0;
        for(i = 0; i < fim; i++){
            if(vet[i] > vet[i+1]){
                swap(&vet[i], &vet[i+1]);
                mudou = 1;
            }
        }
        fim--;
    }while(mudou);
}

void selectionSort(int *vet, int n){
    int i, j, menor;
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i; j < n; j++){
            if(vet[j] < vet[menor]){
                menor = j;
            }
        }
        if(i != menor){
            swap(&vet[i], &vet[menor]);
        }
    }
}

void insertionSort(int *vet, int n){
    int i, j, aux;
    int comparisons = 0;
    int swaps = 0;
    for(i = 1; i < n; i++){
        aux = vet[i];
        j = i;
        while(j > 0 && aux < vet[j-1]){
            vet[j] = vet[j-1];
            j--;
            comparisons++;
            swaps++;
        }
        vet[j] = aux;
        swaps++;
    }
    printf("Comparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);
}


void merge(int* vet, int inicio, int meio, int fim){
    printf("merge(v,%d,%d,%d)\n", inicio, meio, fim);
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio +1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*) malloc(tamanho * sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(vet[p1]< vet[p2]){
                    temp[i] = vet[p1];
                    p1++;
                }else{
                    temp[i] = vet[p2];
                    p2++;
                }
                if(p1>meio){
                    fim1 = 1;
                }
                if(p2>fim){
                    fim2 = 1;
                }
            }else{
                if(!fim1){
                    temp[i] = vet[p1];
                    p1++;
                }else{
                    temp[i] = vet[p2];
                    p2++;
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++){
            vet[k] = temp[j];
        }
    }
    free(temp);
}

void mergeSort(int *vet, int inicio, int fim){
    printf("mergeSort(v,%d,%d)\n", inicio, fim);
    int meio;
    if(inicio < fim){
        meio = floor((inicio + fim)/2);
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio+1, fim);
        merge(vet, inicio, meio, fim);
    }
}

int particiona(int *vet, int inicio, int fim, int *comparisons, int *swaps){
    int esq, dir, pivo;
    esq = inicio;
    dir = fim;
    pivo = vet[inicio];
    while(esq < dir){
        while(esq <= fim && vet[esq] <= pivo){
            esq++;
            (*comparisons)++;
        }
        while(dir >= inicio && vet[dir] > pivo){
            dir--;
            (*comparisons)++;
        }
        if(esq < dir){
            swap(&vet[esq], &vet[dir]);
            (*swaps)++;
        }
    }
    swap(&vet[inicio], &vet[dir]);
    (*swaps)++;
    return dir;
}

void quickSort(int *vet, int inicio, int fim, int *comparisons, int *swaps){
    int pivo;
    if(fim > inicio){
        pivo = particiona(vet, inicio, fim, comparisons, swaps);
        quickSort(vet, inicio, pivo-1, comparisons, swaps);
        quickSort(vet, pivo+1, fim, comparisons, swaps);
    }
}

int main()
{
    int v[] = {97, 72, 106, 111, 34, 7};
    int comparisons = 0;
    int swaps = 0;
    //bubblesort(v,7);
    insertionSort(v,6);
    //selectionSort(v,7);
   // mergeSort(v, 0, 6);
//    quickSort(v, 0, 5, &comparisons, &swaps);
    for(int i = 0; i < 6; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
   // printf("Comparisons: %d\n", comparisons);
   // printf("Swaps: %d\n", swaps);

    return 0;
}
