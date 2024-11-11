#include <bits/stdc++.h>
using namespace std;
void Merge(int arr1[], int arr2[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  int L1[n1], L2[n1];
  int R1[n2], R2[n1];
  for (int i = 0; i < n1; i++) {
    L1[i] = arr1[i + l];
    L2[i] = arr2[i + l];
  }
  for (int i = 0; i < n2; i++) {
    R1[i] = arr1[m + i + 1];
    R2[i] = arr2[m + i + 1];
  }
  int L = 0;
  int R = 0;
  int k = l;
  while (L < n1 && R < n2) {
    if (L1[L] < R1[R]) {
      arr1[k] = L1[L];
      arr2[k] = L2[L];
      L++;
    } else {
      arr1[k] = R1[R];
      arr2[k] = R2[R];
      R++;
    }
    k++;
  }
  while (L < n1) {
    arr1[k] = L1[L];
    arr2[k] = L2[L];
    L++;
    k++;
  }
  while (R < n2) {
    arr1[k] = R1[R];
    arr2[k] = R2[R];
    R++;
    k++;
  }
}
void mergeSort(int arr1[], int arr2[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr1, arr2, l, m);
    mergeSort(arr1, arr2, m + 1, r);
    Merge(arr1, arr2, l, m, r);
  }
}
int reduce(int arr1[], int m) {
  int value = 0;
  for (int i = 0; i < m; i++) {
    value += arr1[i];
    if (value > 0) {
      return i;
    }
  }
  return m;
}
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n - 1][m];
  int index[n - 1][m];
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      index[i][j] = j + 1;
    }
  }
  for (int i = 0; i < m; i++) {
    int values[n];
    for (int j = 0; j < n; j++) {
      cin >> values[j];
    }
    for (int j = 0; j < n - 1; j++) {
      arr[j][i] = values[n - 1] - values[j];
    }
  }
  int max = 0;
  int max_index = 0;
  for (int i = 0; i < n - 1; i++) {
    mergeSort(arr[i], index[i], 0, m - 1);
    int k = reduce(arr[i], m);
    if (k > max) {
      max = k;
      max_index = i;
    }
  }
  cout << m - max << endl;
  for (int i = max; i < m - 1; i++) {
    cout << index[max_index][i] << " ";
  }
  if (m - max > 0) {
    cout << index[max_index][m - 1];
  }
}
