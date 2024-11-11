#include <bits/stdc++.h>
using namespace std;
const int N = 100003, M = 56, mod = 1e9 + 7;
template <typename T>
void rd(T &x) {
  int ch = getchar();
  x = 0;
  for (; ch < '0' || ch > '9'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
void qmo(int &x) { x += x >> 31 & mod; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, k, fac[N], u[M], v[M], w[M], ans;
vector<int> v1, v2;
vector<pair<int, int> > E[M];
unordered_map<long long, int> f[M][M];
long long U[M];
int main() {
  rd(n);
  rd(k);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = (long long)fac[i - 1] * i % mod;
  for (int i = 0; i < k; ++i) {
    rd(u[i]);
    rd(v[i]);
    rd(w[i]);
    --w[i];
    v1.emplace_back(u[i]);
    v2.emplace_back(v[i]);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  v1.erase(unique(v1.begin(), v1.end()), v1.end());
  v2.erase(unique(v2.begin(), v2.end()), v2.end());
  for (int i = 0; i < k; ++i) {
    u[i] = lower_bound(v1.begin(), v1.end(), u[i]) - v1.begin();
    v[i] = lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin();
    E[u[i]].emplace_back(v[i], w[i]);
  }
  m = v1.size();
  shuffle(E, E + m, rng);
  for (int i = m - 1; ~i; --i) {
    U[i] = U[i + 1];
    for (pair<int, int> _ : E[i]) U[i] |= 1ll << _.first;
  }
  f[0][0][0] = 1;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j <= i; ++j)
      for (pair<long long, int> k : f[i][j]) {
        qmo(f[i + 1][j][k.first & U[i + 1]] += k.second - mod);
        for (pair<int, int> x : E[i])
          if (!(k.first >> x.first & 1)) {
            int &res = f[i + 1][j + 1][(k.first | 1ll << x.first) & U[i + 1]];
            res = (res + (long long)x.second * k.second) % mod;
          }
      }
  for (int i = 0; i <= m; ++i)
    ans = (ans + (long long)f[m][i][0] * fac[n - i]) % mod;
  printf("%d\n", ans);
}
