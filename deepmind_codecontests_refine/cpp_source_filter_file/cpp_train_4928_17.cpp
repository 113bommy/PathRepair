#include <bits/stdc++.h>
void swap(long long *a, long long *b) {
  long long temp = *a;
  *a = *b;
  *b = temp;
}
long long part(long long *arr, long long l, long long r) {
  long long idx = rand() % (r - l) + l, i = l - 1, j, piv;
  swap(&arr[idx], &arr[r]);
  piv = arr[r];
  for (j = l; j < r; j++) {
    if (arr[j] > piv) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[r]);
  return i + 1;
}
void qs(long long *arr, long long l, long long r) {
  if (l < r) {
    long long piv = part(arr, l, r);
    qs(arr, l, piv - 1);
    qs(arr, piv + 1, r);
  }
}
int main() {
  long long t, i, a, b, *arr, *left, *right;
  scanf("%lld %lld %lld", &t, &a, &b);
  arr = (long long *)malloc(t * sizeof(long long));
  for (i = 0; i < t; i++) {
    scanf("%lld", &arr[i]);
  }
  qs(arr, 0, t - 1);
  printf("%lld\n", arr[a - 1] - arr[b - 1]);
  return 0;
}
