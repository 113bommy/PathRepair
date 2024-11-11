#include <bits/stdc++.h>
using namespace std;
void redirect_input() { freopen("./input.txt", "r", stdin); }
void redirect_output() { freopen("./output.txt", "w", stdout); }
const int inf = 0x3f3f3f3f;
const int maxn = 5e5 + 100;
int in[maxn], out[maxn];
int mark[maxn], vis[maxn] = {0}, vis_cnt = 0;
vector<pair<int, int> > seg;
vector<int> G[maxn];
void dfs(int u) {
  vis[u] = 1;
  vis_cnt++;
  for (int v : G[u])
    if (!vis[v]) dfs(v);
}
void solve() {
  int n, edge_cnt = 0;
  cin >> n;
  for (int i = 0, _iter_max = n; i < _iter_max; i++) mark[i] = i;
  for (int i = 0, _iter_max = n; i < _iter_max; i++) {
    cin >> in[i] >> out[i];
    seg.push_back({in[i], i});
    seg.push_back({out[i], i});
  }
  sort(seg.begin(), seg.end());
  set<pair<int, int> > end_points;
  for (pair<int, int> pii : seg) {
    auto ptr = end_points.find(pii);
    if (ptr != end_points.end()) {
      end_points.erase(ptr);
    } else {
      for (pair<int, int> ii : end_points) {
        if (ii.first > out[pii.second]) break;
        G[ii.second].push_back(pii.second);
        G[pii.second].push_back(ii.second);
        edge_cnt++;
        if (edge_cnt >= n) break;
      }
      end_points.insert({out[pii.second], pii.second});
    }
    if (edge_cnt >= n) break;
  }
  dfs(0);
  cout << ((edge_cnt == n - 1 && vis_cnt == n) ? "YES\n" : "NO\n");
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  solve();
}
