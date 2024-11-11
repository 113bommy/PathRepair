#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const long long INFL = (long long)9e18;
const int MAXINT = ((~0) ^ (1 << 31));
const long long MAXLL = ((~0) ^ ((long long)1 << 63));
template <class T>
inline T pow2(T a) {
  return a * a;
}
template <class T>
inline bool mineq(T& a, T b) {
  return (a > b) ? (a = b, true) : false;
}
template <class T>
inline bool maxeq(T& a, T b) {
  return (a < b) ? (a = b, true) : false;
}
const int maxn = 4e5;
long long n, m, v, u, p[maxn], mark[maxn];
vector<pair<long long, long long> > g[maxn];
vector<long long> ans, od;
void dfs(long long w) {
  for (p[w]; p[w] < g[w].size(); p[w]++) {
    if (!mark[g[w][p[w]].second]) {
      mark[g[w][p[w]].second] = 1;
      dfs(g[w][p[w]].first);
    }
  }
  ans.push_back(w);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> v >> u;
    g[v].push_back({u, i});
    g[u].push_back({v, i});
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size() % 2 != 0) od.push_back(i);
  }
  for (int i = 0; i < od.size(); i += 2) {
    g[od[i]].push_back({od[i + 1], m + i});
    g[od[i + 1]].push_back({od[i], m + i});
  }
  if ((m + od.size() / 2) % 2 != 0) g[1].push_back({1, m + od.size()});
  dfs(1);
  cout << ans.size() - 1 << endl;
  for (int i = 0; i < ans.size() - 1; i++) {
    if (i % 2 == 0) {
      cout << ans[i] << " " << ans[i + 1] << endl;
    } else {
      cout << ans[i + 1] << " " << ans[i] << endl;
    }
  }
}
