#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int T, n, m, u[60], v[60], w[60], a[60], p = 0, b[60], q = 0, fac[100010];
vector<pair<int, int> > E[60];
long long G[60];
map<long long, int> f[60][60];
void qmo(int &x) { x += (x >> 31) & mod; }
int main() {
  scanf("%d%d", &n, &m);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    a[++p] = u[i], b[++q] = v[i], w[i]--;
  }
  sort(a + 1, a + p + 1), p = unique(a + 1, a + p + 1) - a - 1;
  sort(b + 1, b + q + 1), q = unique(b + 1, b + q + 1) - b - 1;
  for (int i = 1; i <= m; i++) {
    u[i] = lower_bound(a + 1, a + p + 1, u[i]) - a - 1;
    v[i] = lower_bound(b + 1, b + q + 1, v[i]) - b - 1;
    E[u[i]].push_back({v[i], w[i]});
  }
  for (int i = p - 1; ~i; i--) {
    G[i] = G[i + 1];
    for (auto j : E[i]) G[i] |= 1ll << j.first;
  }
  f[0][0][0] = 1;
  for (int i = 0; i < p; i++)
    for (int j = 0; j <= i; j++)
      for (auto k : f[i][j]) {
        qmo(f[i + 1][j][k.first & G[i + 1]] += k.second - mod);
        for (auto l : E[i])
          if (((~k.first) >> l.first) & 1) {
            qmo(f[i + 1][j + 1][(k.first | (1 << l.first)) & G[i + 1]] +=
                1ll * k.second * l.second % mod - mod);
          }
      }
  int res = 0;
  for (int i = 0; i <= p; i++)
    res = (res + 1ll * fac[n - i] * f[p][i][0]) % mod;
  printf("%d\n", res);
}
