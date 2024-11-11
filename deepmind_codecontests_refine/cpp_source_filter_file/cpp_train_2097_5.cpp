#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e2 + 3;
int m;
long long n, aux[nmax][nmax], d[nmax][nmax], x[nmax][nmax], sol;
void mult1() {
  memset(aux, 0, sizeof(aux));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = 1; k <= m; ++k)
        aux[i][j] = (aux[i][j] + x[i][k] * d[k][j]) % 1000000007;
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) x[i][j] = aux[i][j];
  }
}
void mult2() {
  memset(aux, 0, sizeof(aux));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = 1; k <= m; ++k)
        aux[i][j] = (aux[i][j] + d[i][k] * d[k][j]) % 1000000007;
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) d[i][j] = aux[i][j];
  }
}
void putere() {
  for (int i = 1; i <= m; ++i) x[i][i] = 1;
  while (n) {
    if (n & 1) mult1();
    mult2();
    n >>= 1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  if (n < m) {
    cout << 1;
    return 0;
  }
  if (n == m) {
    cout << 2;
    return 0;
  }
  d[1][1] = 1;
  d[1][m] = 1;
  for (int i = 1; i < m; ++i) d[i + 1][i] = 1;
  n -= m;
  --n;
  putere();
  sol = (2ll * d[1][1]) % 1000000007;
  for (int i = 2; i <= m; ++i) sol = (sol + d[1][i]) % 1000000007;
  cout << sol;
  return 0;
}
