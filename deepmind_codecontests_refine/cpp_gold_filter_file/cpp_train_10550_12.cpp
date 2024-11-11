#include <bits/stdc++.h>
using namespace std;
int binary_search(int *arr, int key, int l, int r) {
  int mid = (r + l) / 2;
  if (l <= r) {
    if (key == arr[mid]) return mid;
    if (key < arr[mid]) return binary_search(arr, key, l, mid - 1);
    if (key > arr[mid]) return binary_search(arr, key, mid + 1, r);
  }
  return mid;
}
int binary(int *arr, int key, int l, int r) {
  int mid = (r + l) / 2;
  if (l <= r) {
    if (key == arr[mid]) return 1;
    if (key < arr[mid]) return binary(arr, key, l, mid - 1);
    if (key > arr[mid]) return binary(arr, key, mid + 1, r);
  }
  return 0;
}
int n, arr[44800], l, r, x, y;
int main() {
  for (int i = 0; arr[i - 1] < 1000000000; i++) arr[i] = (i + 1) * (i + 2) / 2;
  l = 0;
  r = 44750;
  scanf("%d", &n);
  if (n == 1) {
    cout << "NO" << endl;
    return 0;
  }
  x = binary_search(arr, n, l, r);
  y = x / 2;
  while (x >= y) {
    if (binary(arr, n - arr[x], l, r)) {
      cout << "YES" << endl;
      return 0;
    }
    x--;
  }
  cout << "NO" << endl;
}
