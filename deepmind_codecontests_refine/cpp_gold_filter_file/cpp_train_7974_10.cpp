#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long p) {
  long long ret = 1;
  while (p > 0) {
    if (p & 1) {
      ret *= a;
    }
    a *= a;
    p >>= 1;
  }
  return ret;
}
int main() {
  long long n, m;
  cin >> n >> m;
  long long a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  long long ans = n * m;
  long long w = 0, b = 0;
  long long row[n][2];
  for (int i = 0; i < n; i++) {
    w = 0;
    b = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0)
        w++;
      else
        b++;
    }
    row[i][0] = w;
    row[i][1] = b;
  }
  long long col[m][2];
  for (int j = 0; j < m; j++) {
    w = 0;
    b = 0;
    for (int i = 0; i < n; i++) {
      if (a[i][j] == 0)
        w++;
      else
        b++;
    }
    col[j][0] = w;
    col[j][1] = b;
  }
  for (int i = 0; i < n; i++) {
    if (row[i][0] > 1) {
      ans = ans + power(2, row[i][0]) - row[i][0] - 1;
    }
    if (row[i][1] > 1) {
      ans = ans + power(2, row[i][1]) - row[i][1] - 1;
    }
  }
  for (int i = 0; i < m; i++) {
    if (col[i][0] > 1) {
      ans = ans + power(2, col[i][0]) - col[i][0] - 1;
    }
    if (col[i][1] > 1) {
      ans = ans + power(2, col[i][1]) - col[i][1] - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
