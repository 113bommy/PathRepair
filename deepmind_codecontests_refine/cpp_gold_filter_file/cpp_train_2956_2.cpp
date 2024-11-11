#include <bits/stdc++.h>
int binary_search(int arr[], int l, int h, int num) {
  int mid = (h + l) / 2;
  if (l == h) return mid;
  if (num >= arr[mid] && num < arr[mid + 1]) {
    return mid;
  }
  if (num == arr[mid + 1]) return (mid + 1);
  if (num > arr[mid + 1]) {
    l = mid + 1;
    binary_search(arr, l, h, num);
  }
  if (num < arr[mid]) {
    h = mid - 1;
    binary_search(arr, l, h, num);
  }
}
int main() {
  int n, m, a, b, i, j = 1, k;
  scanf("%d %d", &n, &m);
  int c[m], arr[n];
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    arr[i] = j;
    j += a * b;
  }
  for (i = 0; i < m; i++) {
    scanf("%d", &j);
    k = binary_search(arr, 0, n - 1, j);
    c[i] = k + 1;
  }
  for (i = 0; i < m; i++) {
    printf("%d\n", c[i]);
  }
  return 0;
}
