#include <bits/stdc++.h>
using namespace std;
int n, k, cant[4000100], otran;
int arr[1000100];
int comp(int n) {
  int aux = 0, mask = 1;
  while (mask <= n) {
    if ((n & mask) == 0) {
      aux += mask;
    }
    mask <<= 1;
  }
  return aux;
}
int main() {
  int i = 0, pot = 1, cont = 0;
  while (pot < 4000100) {
    for (; i < pot; i++) {
      cant[i] = (pot)-1;
    }
    pot <<= 1;
    cont++;
  }
  scanf("%d", &n);
  otran = n;
  long long suma = 0;
  int aux = 0;
  while (n > 0) {
    aux = comp(n);
    suma += (long long)cant[n] * (long long)(n - aux + 1);
    for (int i = n, j = aux; i > j; i--, j++) {
      arr[i] = j;
      arr[j] = i;
    }
    n = aux - 1;
  }
  printf("%I64d\n", suma);
  printf("%d", arr[0]);
  for (int i = 1; i <= otran; i++) {
    printf(" %d", arr[i]);
  }
}
