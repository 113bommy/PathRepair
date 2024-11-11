#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 10, MAX = 1e6 + 1e4, MOD = 1e9 + 7, MAXL = 25;
void OUT(long double o, int x) {
  cout << fixed << setprecision(x) << o;
  return;
}
long long dp[MAXL][MAX], h[MAX];
void upd(int v, int p) {
  dp[0][v] = p;
  h[v] = h[p] + 1;
  for (int i = 1; i <= 20; i++) dp[i][v] = dp[i - 1][dp[i - 1][v]];
}
long long g(int v, int x) {
  for (int i = 0; i <= 20; i++)
    if (x & (1 << i)) v = dp[i][v];
  return v;
}
pair<long long, long long> lca(int v, int u) {
  long long x = 0;
  if (h[v] > h[u]) swap(v, u);
  x = h[u] - h[v];
  u = g(u, h[u] - h[v]);
  if (u == v) return {x, 1};
  for (int i = 20; i >= 0; i--) {
    if (dp[i][v] != dp[i][u]) {
      x += (1 << (i + 1));
      v = dp[i][v];
      u = dp[i][u];
    }
  }
  return {x + 2, 0};
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q, t = 2, n = 4;
  pair<long long, long long> m = {1, 0};
  cin >> q;
  for (int j = 1; j <= 4; j++) upd(j, 1);
  while (q--) {
    long long x;
    cin >> x;
    upd(n + 1, x);
    upd(n + 2, x);
    n += 2;
    if (t % 2 == 0) {
      pair<long long, long long> y = lca(m.first, n);
      if (y.first > t / 2) {
        if (y.second)
          m.second = g(n, h[n] - h[m.first] - 1);
        else
          m.second = dp[0][m.first];
        t++;
      }
    } else {
      pair<pair<long long, long long>, long long> y = {lca(m.first, n),
                                                       m.first};
      pair<pair<long long, long long>, long long> z = {lca(m.second, n),
                                                       m.second};
      if (y.first.first > z.first.first) swap(y, z);
      if (y.first.first > t / 2) {
        m = {y.second, 0};
        t++;
      }
    }
    cout << t << "\n";
  }
  return 0;
}
