#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1];
  int R[n2];
  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
int main() {
  int tests, n, k, ntests;
  cin >> tests;
  for (ntests = 0; ntests < tests; ntests++) {
    int nswaps = 0, i = 0, j = 0, totalA = 0;
    cin >> n >> k;
    int arrA[n], arrB[n];
    for (int i = 0; i < n; i++) {
      cin >> arrA[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> arrB[i];
    }
    mergeSort(arrA, 0, n - 1);
    mergeSort(arrB, 0, n - 1);
    i = 0;
    j = n - 1;
    for (int nswaps = 0; nswaps < k; nswaps++) {
      if (arrA[i] < arrB[j]) {
        arrA[i] = arrB[j];
        i++, j--;
      } else
        nswaps = k;
    }
    for (int i = 0; i <= n; i++) {
      totalA += arrA[i];
    }
    cout << totalA << endl;
  }
}
