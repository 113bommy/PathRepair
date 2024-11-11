#include <bits/stdc++.h>
using namespace std;
const int N = 105;
using ll = long long;
int n, m, P, f[N * N];
char s[N][N];
inline int id(int x, int y) { return (x - 1) * (m + 1) + y; }
int getf(int v) { return f[v] == v ? v : f[v] = getf(f[v]); }
inline void merge(int x, int y) {
  x = getf(x);
  y = getf(y);
  f[x] = y;
}
ll qpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % P;
    a = a * a % P;
    b >>= 1;
  }
  return ret;
}
int idx[N * N];
struct Matrix {
  ll a[N * 5][N * 5];
  int n;
  inline void add(int x, int y) {
    if (x == y) return;
    a[x][x]++;
    a[y][y]++;
    a[x][y]--;
    a[y][x]--;
  }
  ll solve() {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) a[i][j] = (a[i][j] + P) % P;
    ll ret = 1;
    for (int i = 1; i < n; i++) {
      int pos = i;
      while (pos < n && !a[pos][i]) ++pos;
      if (pos >= n) continue;
      if (pos != i) ret = P - ret, swap(a[pos], a[i]);
      ll inv = qpow(a[i][i], P - 2);
      for (int j = i + 1; j < n; j++) {
        ll tmp = inv * a[j][i] % P;
        for (int k = i; k < n; k++)
          a[j][k] = (a[j][k] - a[i][k] * tmp % P + P) % P;
      }
    }
    for (int i = 1; i < n; i++) ret = ret * a[i][i] % P;
    return ret;
  }
} g[2];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> P;
  for (int i = 1; i <= n; i++) cin >> (s[i] + 1);
  for (int i = 1; i <= (n + 1) * (m + 1); i++) f[i] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '/')
        merge(id(i + 1, j), id(i, j + 1));
      else if (s[i][j] == '\\')
        merge(id(i, j), id(i + 1, j + 1));
  for (int i = 1; i <= n + 1; i++)
    for (int j = 1; j <= m + 1; j++)
      if (getf(id(i, j)) == id(i, j)) idx[id(i, j)] = ++g[(i + j) & 1].n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '*')
        g[(i + j) & 1].add(idx[getf(id(i, j))], idx[getf(id(i + 1, j + 1))]),
            g[(i + j + 1) & 1].add(idx[getf(id(i + 1, j))],
                                   idx[getf(id(i, j + 1))]);
  cout << (g[0].solve() + g[1].solve()) % P << endl;
  return 0;
}
