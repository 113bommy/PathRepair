#include <bits/stdc++.h>
using namespace std;
int arr[500000], n, izq, der, med, cual;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  sort(arr, arr + n);
  der = n >> 1;
  izq = 1;
  while (izq <= der) {
    med = (izq + der) >> 1;
    int cuantos = 0;
    for (int i = 0, j = med + 1; i < med && j < n; i++, j++) {
      while (j < n && arr[j] < (arr[i] << 1)) j++;
      if (j == n) break;
      cuantos++;
    }
    if (cuantos == med) {
      cual = med;
      izq = med + 1;
    } else
      der = med - 1;
  }
  printf("%d", n - cual);
}
