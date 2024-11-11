#include <bits/stdc++.h>
int maxOnes(int *, int, int, int);
int countOnes(int *, int, int, int);
int maxContinuousSubarray(int *, int);
int main() {
  int n, a[100], i, b[100], count = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i] == 0 ? 1 : -1;
    if (a[i] == 1) count++;
  }
  printf("%d\n", count + maxContinuousSubarray(b, n));
  return 0;
}
int maxOnes(int *arr, int low, int high, int n) {
  if (low == high)
    return countOnes(arr, low, high, n);
  else
    return maxOnes(arr, low, high - 1, n) > maxOnes(arr, low + 1, high, n)
               ? maxOnes(arr, low, high - 1, n)
               : maxOnes(arr, low + 1, high, n);
}
int countOnes(int *arr, int i, int j, int n) {
  int count = 0, k;
  for (k = 0; k < n; k++) {
    if (k >= i && k <= j && *(arr + k) == 0)
      count++;
    else if (*(arr + k) == 1)
      count++;
  }
  return count;
}
int maxContinuousSubarray(int *arr, int n) {
  int max = 0, max_until_now = 0, i;
  for (i = 0; i < n; i++) {
    max_until_now += *(arr + i);
    if (max_until_now > max) max = max_until_now;
    if (max_until_now < 0) max_until_now = 0;
  }
  return max;
}
