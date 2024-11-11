#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000005;
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
vector<int> adj[N];
int d[N], c[N], p[N];
void dfs(int v) {
  for (auto& x : adj[v]) {
    if (d[x] == 0) {
      p[x] = v;
      d[x] = d[v] + 1;
      ++c[v];
      dfs(x);
    }
  }
}
vector<int> asd;
vector<pair<int, int> > ans;
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) adj[i].clear();
  ans.clear();
  asd.clear();
  for (int i = 1; i <= m; ++i) {
    int v, u;
    cin >> v >> u;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i) d[i] = c[i] = p[i] = 0;
  d[1] = 1;
  dfs(1);
  int sz = 0;
  for (int i = 1; i <= n; ++i)
    if (c[i] == 0) asd.push_back(i);
  while (sz < (n + 1) / 2) {
    if (asd.size() < 2) {
      int i = asd[0];
      cout << "PATH\n";
      cout << d[i] << '\n';
      while (i != 0) {
        cout << i << ' ';
        i = p[i];
      }
      cout << '\n';
      return;
    }
    int v1 = asd.back();
    asd.pop_back();
    int v2 = asd.back();
    asd.pop_back();
    if (--c[p[v1]] == 0) asd.push_back(v1);
    if (--c[p[v2]] == 0) asd.push_back(v2);
    ans.push_back({v1, v2});
    sz += 2;
  }
  cout << "PAIRING\n";
  cout << ans.size() << '\n';
  for (auto& x : ans) {
    cout << x.first << ' ' << x.second << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
