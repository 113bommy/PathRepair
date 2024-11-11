#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[j] > a[j + 1]) {
        k = a[j];
        a[j] = a[j + 1];
        a[j + 1] = k;
      }
    }
  }
  k = 0;
  for (i = 0; i < n; i++) {
    if (a[i - 1] == a[i]) {
      a[i] = 0;
      a[i - 1] = 0;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[j] > a[j + 1]) {
        k = a[j];
        a[j] = a[j + 1];
        a[j + 1] = k;
      }
    }
  }
  k = 0;
  for (i = 0; i < n; i = i + 2) {
    k = k + ((a[i + 1]) - a[i]);
  }
  cout << k;
  return 0;
}
