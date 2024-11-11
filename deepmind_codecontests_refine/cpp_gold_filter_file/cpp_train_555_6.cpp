#include <bits/stdc++.h>
using namespace std;
int c[100][100], b[100], a[100];
int main() {
  int k;
  cin >> k;
  int t = 0, t1 = 0;
  for (int i = 1; i < 100; i++) {
    a[i] = i * (i - 1) * (i - 2) / 6;
  }
  for (int i = 1; i < 100; i++) {
    if (k >= a[i] && k < a[i + 1]) {
      t = i;
      break;
    }
  }
  for (int i = 1; i <= t; i++) {
    for (int j = 1; j <= t; j++) {
      if (i != j) {
        c[i][j] = 1;
      }
    }
  }
  int n = 0;
  for (int i = 1; i <= 100; i++) b[i] = i * (i - 1) / 2;
  k -= a[t];
  n = t;
  while (k > 0) {
    for (int i = 1; i < 100; i++) {
      if (b[i] <= k && k < b[i + 1]) {
        t1 = i;
        break;
      }
    }
    for (int i = 1; i <= t1; i++) {
      c[n + 1][i] = 1;
      c[i][n + 1] = 1;
    }
    k -= b[t1];
    n++;
  }
  cout << n << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << c[i][j];
    }
    cout << endl;
  }
  return 0;
}
