#include <bits/stdc++.h>
using namespace std;
int large(int arr[], int n) {
  int largest;
  largest = arr[0];
  for (int i = 1; i < n; i++) {
    if (largest < arr[i]) largest = arr[i];
  }
  return largest;
}
int myXOR(int x, int y) { return (x | y) & (~x | ~y); }
bool areEqual(int arr1[], int arr2[], int n, int m) {
  if (n != m) return false;
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
  for (int i = 0; i < n; i++)
    if (arr1[i] != arr2[i]) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  int y = t;
  int ar[t];
  int p = 0;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    int o = 1;
    int arr1[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int e = large(arr, n);
    for (int k = 1; k <= e + e; k++) {
      for (int i = 0; i < n; i++) {
        arr1[i] = myXOR(k, arr[i]);
      }
      if (areEqual(arr, arr1, n, n)) {
        o = -1;
        ar[p] = k;
        p++;
        break;
      }
    }
    if (o != -1) {
      ar[p] = -1;
      p++;
    }
  }
  for (int i = 0; i < y; i++) {
    cout << ar[i] << endl;
  }
}
