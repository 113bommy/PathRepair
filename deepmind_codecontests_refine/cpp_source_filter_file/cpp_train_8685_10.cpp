#include <bits/stdc++.h>
using namespace std;
const int N = 111;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int a[N], b[N];
int c[N][N];
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    a[1] = 1;
  } else if (n == 2) {
    a[1] = 3, a[2] = 4;
  } else {
    for (int i = 1; i <= n; ++i) a[i] = 1;
    if (n & 1) {
      a[1] = 2;
      a[n] = (n + 1) / 2;
    } else {
      a[n] = (n - 2) / 2;
    }
  }
  if (m == 1) {
    b[1] = 1;
  } else if (m == 2) {
    b[1] = 3, b[2] = 4;
  } else {
    for (int i = 1; i <= m; ++i) b[i] = 1;
    if (m & 1) {
      b[1] = 2;
      b[m] = (m + 1) / 2;
    } else {
      a[m] = (m - 2) / 2;
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) c[i][j] = a[i] * b[j];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < m; ++j) {
      cout << c[i][j] << ' ';
    }
    cout << c[i][m] << endl;
  }
  return 0;
}
