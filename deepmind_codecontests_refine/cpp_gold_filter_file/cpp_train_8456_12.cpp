#include <bits/stdc++.h>
using namespace std;
void merge(vector<long int> &arr, long int l, long int m, long int r) {
  long int i, j, k;
  long int n1 = m - l + 1;
  long int n2 = r - m;
  long int L[n1], R[n2];
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
void mergeSort(vector<long int> &arr, long int l, long int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
int main() {
  long int t;
  cin >> t;
  for (long int i = 0; i < t; i++) {
    long long int n;
    cin >> n;
    long int k = 2;
    double p = 2.0;
    long int ans;
    while (true) {
      ans = (long int)pow(p, (double)k) - 1;
      if (n % ans == 0) {
        cout << n / ans << endl;
        break;
      } else
        k++;
    }
  }
}
