#include <bits/stdc++.h>
using namespace std;
int Bsort(int arr[], int n) {
  int i, tmp;
  for (i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  return 0;
}
int fun(int arr[], int n, int t) {
  Bsort(arr, n);
  int i = 0, j, max = 0, curr;
  while (i < n - 1) {
    curr = 0;
    for (j = i + 1; j < n; j++) {
      if (arr[j] - arr[i] <= t) {
        curr = j - i + 1;
      } else
        break;
    }
    if (curr > max) {
      max = curr;
    }
    i++;
  }
  return max;
}
int main() {
  int n, j;
  cin >> n;
  int arr[n];
  for (j = 0; j < n; j++) {
    cin >> arr[j];
  }
  int t;
  cin >> t;
  cout << fun(arr, n, t);
  return 0;
}
