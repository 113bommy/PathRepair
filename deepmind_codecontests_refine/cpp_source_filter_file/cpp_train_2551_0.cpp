#include <bits/stdc++.h>
using namespace std;
const long long N = 300005, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
long long n, c[N], val[N], id[N];
vector<long long> gr[N], ans;
pair<long long, long long> node[N];
set<pair<long long, long long> > s[N];
void dfs(long long u, long long p) {
  id[u] = u;
  node[u].first = (node[p].first * 26 + val[u]) % mod1;
  node[u].second = (node[p].second * 26 + val[u]) % mod2;
  for (long long v : gr[u])
    if (v != p) {
      dfs(v, u);
      if (s[id[v]].size() > s[id[u]].size()) id[u] = id[v];
    }
  s[id[u]].insert(node[u]);
  for (long long v : gr[u])
    if (v != p && id[v] != id[u]) {
      for (set<pair<long long, long long> >::iterator i = s[id[v]].begin();
           i != s[id[v]].end(); ++i) {
        s[id[u]].insert(*i);
      }
    }
  ans.push_back(s[id[u]].size() + c[u]);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> c[i];
  for (long long i = 1; i <= n; ++i) {
    char _char;
    cin >> _char;
    val[i] = _char - 'a';
  }
  for (long long i = 1; i < n; ++i) {
    long long u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  node[0].first = node[0].second = 0;
  dfs(1, 0);
  sort(ans.begin(), ans.end());
  cout << ans.back() << "\n";
  long long cnt = 0;
  for (long long i = 0; i < ans.size(); ++i) cnt += (ans[i] == ans.back());
  cout << cnt;
  return 0;
}
