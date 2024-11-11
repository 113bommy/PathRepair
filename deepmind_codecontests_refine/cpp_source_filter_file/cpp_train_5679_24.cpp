#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const long long maxn = 3000 + 10, N = 2e5 + 10, SQ = 320, base = 800287,
                mod = 1e9 + 7, INF = 1e18 + 10, lg = 22;
const long double eps = 1e-4;
long long n, m, q, dis[maxn][maxn], res[maxn];
long long V[N], U[N], r[N], s[N], t[N];
vector<long long> query[N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (long long i = 0; i < m; ++i) {
    cin >> V[i] >> U[i];
    V[i]--, U[i]--;
  }
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < n; ++j) {
      dis[i][j] = (i != j ? INF : m);
    }
  }
  for (long long i = 0; i < q; ++i) {
    long long l;
    cin >> l >> r[i] >> s[i] >> t[i];
    l--, r[i]--, s[i]--, t[i]--;
    query[l].push_back(i);
  }
  for (long long idx = m - 1; idx >= 0; --idx) {
    dis[V[idx]][U[idx]] = dis[U[idx]][V[idx]] = idx;
    for (long long i = 0; i < n; ++i) {
      long long val = min(dis[V[idx]][i], dis[U[idx]][i]);
      dis[V[idx]][i] = dis[U[idx]][i] = val;
    }
    for (auto i : query[idx]) {
      if (dis[s[i]][t[i]] > r[i]) {
        res[i] = 0;
      } else {
        res[i] = 1;
      }
    }
  }
  for (long long i = 0; i < q; ++i) {
    cout << (res[i] ? "Yes\n" : "No\n");
  }
}
