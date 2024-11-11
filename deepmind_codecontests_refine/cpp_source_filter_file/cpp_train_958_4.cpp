#include <bits/stdc++.h>
using namespace std;
int comparar(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int main() {
  char num1[12];
  int tamanho, i;
  int contador;
  char fim[12];
  int tamanho2;
  while (cin >> num1 >> fim) {
    contador = 0;
    int resp = 0;
    int verdade = 1;
    tamanho = strlen(num1);
    int array[tamanho];
    tamanho2 = strlen(fim);
    if (tamanho != tamanho2) {
      cout << "WRONG_ANSWER" << endl;
    } else {
      for (i = 0; i < tamanho; i++) {
        array[i] = num1[i] - 48;
      }
      qsort(array, tamanho, sizeof(int), comparar);
      for (i = 0; i < tamanho; i++) {
        if (!array[i]) {
          contador++;
        }
      }
      if (contador) {
        if (array[contador] != fim[resp] - 48) {
          verdade = 0;
        }
        resp++;
        for (i = 0; i < contador; i++) {
          if (fim[resp] != '0' && strlen(fim) > 1) {
            verdade = 0;
          }
          resp++;
        }
        for (i = contador + 1; i < tamanho; i++) {
          if (fim[resp] - 48 != array[i]) {
            verdade = 0;
          }
          resp++;
        }
      } else {
        for (i = 0; i < tamanho; i++) {
          if (fim[i] - 48 != array[i]) {
            verdade = 0;
          }
        }
      }
      if (tamanho == 1 && tamanho2 == 1 && num1[0] == '0' && fim[0]) {
        verdade = 1;
      }
      if (verdade) {
        cout << "OK" << endl;
      } else {
        cout << "WRONG_ANSWER" << endl;
      }
    }
  }
  return 0;
}
