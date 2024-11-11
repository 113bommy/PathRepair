#include <bits/stdc++.h>
void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
    }
  }
}
int main() {
  int T;
  int arr[1005];
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    scanf("%d", &arr[i]);
  }
  bubbleSort(arr, T);
  if (T % 2)
    printf("%d\n", arr[(T - 1) / 2]);
  else
    printf("%d\n", arr[T / 2]);
  return 0;
}
