#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 1000 + 10;
vector<int> g[maxn];
set<pair<int, int> > s;
int cnt[maxn];
int ans[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= n; i++) s.insert({0, -i});
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    cnt[u]++;
    s.erase({cnt[u] - 1, -u});
    s.insert({cnt[u], -u});
    g[v].push_back(u);
  }
  pair<int, int> node;
  int cv;
  for (int i = 0; i < n; i++) {
    node = (*s.begin());
    cv = -node.second;
    ans[cv] = i + 1;
    s.erase(s.begin());
    for (int v : g[cv]) {
      cnt[v]--;
      s.erase({cnt[v] + 1, -v});
      s.insert({cnt[v], -v});
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
