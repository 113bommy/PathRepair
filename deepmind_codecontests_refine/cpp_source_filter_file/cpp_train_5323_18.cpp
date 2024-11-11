#include <bits/stdc++.h>
using namespace std;
int main() {
  long long c;
  cin >> c;
  long long n;
  int no = c % 7;
  n = 0;
  while (7 * n + no != c) n++;
  long long arr[n + 1];
  long long arr1[n + 2];
  long long arr2[n + 3];
  for (long long i = 0; i <= n - 1; i++) arr[i] = 7;
  arr[n] = (no);
  for (long long i = 0; i <= n; i++) {
    arr1[i] = arr[i];
    arr2[i] = arr[i];
  }
  if (no == 4) {
    long long n1 = n + 1;
    sort(arr, arr + n1);
    for (long long i = 0; i < n1; i++) cout << arr[i];
    cout << endl;
  } else if (no == 0) {
    for (long long i = 0; i < n + 1; i++) cout << arr[i];
    cout << endl;
  } else if (no == 1) {
    if (n >= 1) {
      arr[n - 1] = 4;
      arr[n] = 4;
      long long n1 = n + 1;
      sort(arr, arr + n1);
      for (long long i = 0; i < n1; i++) cout << arr[i];
      cout << endl;
    } else
      cout << -1 << endl;
  } else if (no == 2) {
    if (n >= 2) {
      arr1[n - 2] = 4;
      arr1[n - 1] = 4;
      arr1[n] = 4;
      arr1[n + 1] = 4;
      int n1 = n + 2;
      sort(arr1, arr1 + n1);
      for (long long i = 0; i < n1; i++) cout << arr1[i];
      cout << endl;
    } else
      cout << -1 << endl;
  } else if (no == 3) {
    if (n >= 3) {
      arr2[n - 3] = 4;
      arr2[n - 2] = 4;
      arr2[n - 1] = 4;
      arr2[n] = 4;
      arr2[n + 1] = 4;
      arr2[n + 2] = 4;
      int n1 = n + 3;
      sort(arr2, arr2 + n1);
      for (long long i = 0; i < n1; i++) cout << arr2[i];
      cout << endl;
    } else
      cout << -1;
  } else if (no == 5) {
    if (n >= 1) {
      arr1[n - 1] = 4;
      arr1[n] = 4;
      arr1[n + 1] = 4;
      int n1 = n + 2;
      sort(arr1, arr1 + n1);
      for (long long i = 0; i < n1; i++) cout << arr1[i];
      cout << endl;
    } else
      cout << -1;
  } else if (no == 6) {
    if (n >= 2) {
      arr2[n - 2] = 4;
      arr2[n - 1] = 4;
      arr2[n] = 4;
      arr2[n + 1] = 4;
      arr2[n + 2] = 4;
      int n1 = n + 3;
      sort(arr2, arr2 + n1);
      for (long long i = 0; i < n1; i++) cout << arr2[i];
      cout << endl;
    } else
      cout << -1;
  }
}
