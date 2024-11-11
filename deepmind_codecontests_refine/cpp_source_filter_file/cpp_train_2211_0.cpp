#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> e[100000];
long long dp0[100000], dp1[100000];
long long res = 0;
void dfs(long long u, long long p) {
  long long c = u == 0 ? e[u].size() : e[u].size() - 1;
  vector<long long> a, b;
  for (long long v : e[u])
    if (v != p) {
      dfs(v, u);
      dp0[u] = max(dp0[u], max(dp0[v], c + dp1[v]));
      dp1[u] = max(dp1[u], dp0[v]);
      a.push_back(dp0[v]);
      b.push_back(max(dp0[v], dp1[v] + 1));
    }
  if (u == 0 && c == 1) res = max(res, max(dp1[u] + 1, dp0[u]));
  if (c >= 2) {
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    res = max(res, a[0] + a[1] + 1);
    res = max(res, (long long)e[u].size() - 2 + b[0] + b[1]);
  }
}
int32_t main() {
  cin >> n;
  for (long long i = 1; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  dfs(0, -1);
  cout << res << "\n";
}
