#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, count = 0;
  cin >> n >> m;
  int *arr1 = new int[n];
  int *arr2 = new int[m];
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> arr2[i];
  }
  int i = 0, j = 0;
  int a, b;
  a = arr1[0];
  b = arr2[0];
  while (i < n && j < m) {
    if (a == b) {
      count++;
      a = arr1[++i];
      b = arr2[++j];
    } else if (a < b) {
      a += arr1[++i];
    } else if (a > b) {
      b += arr2[++j];
    }
  }
  cout << count;
  return 0;
}
