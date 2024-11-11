#include <bits/stdc++.h>
using namespace std;
const long long base = 1e9 + 7;
const long long mod = base * base * 2;
const int N = 1e6 + 4;
long long m;
struct matrix {
  long long val[105][105];
  matrix() { memset(val, 0, sizeof(0)); }
  matrix operator*(const matrix& x) {
    matrix res;
    for (int u = 0; u <= m - 1; u++)
      for (int v = 0; v <= m - 1; v++) {
        for (int i = 0; i <= m - 1; i++) {
          res.val[u][v] += val[u][i] * x.val[i][v];
          if (res.val[u][v] >= mod) res.val[u][v] -= mod;
        }
        res.val[u][v] %= base;
      }
    return res;
  }
};
matrix mu(matrix a, long long n) {
  matrix res;
  for (int i = 0; i <= m - 1; i++) res.val[i][i] = 1;
  while (n > 0) {
    if (n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}
long long n, l, c[N], v[N], x, ans;
matrix f, g;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> l >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    x = x % m;
    g.val[0][x]++;
  }
  memset(c, 0, sizeof(c));
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] = v[i] % m;
    c[v[i]]++;
  }
  for (int i = 0; i <= m - 1; i++)
    for (int j = 0; j <= m - 1; j++) f.val[i][(i + j) % m] = c[j];
  memset(c, 0, sizeof(c));
  for (int i = 1; i <= n; i++) {
    cin >> x;
    c[(x + v[i]) % m]++;
  }
  f = mu(f, l - 2);
  g = g * f;
  for (int i = 0; i <= m - 1; i++)
    if (c[i]) ans = (ans + g.val[0][(m - i) % m] * c[i] % base) % base;
  cout << ans;
}
