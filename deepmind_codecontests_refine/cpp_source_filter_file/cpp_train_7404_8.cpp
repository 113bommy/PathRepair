#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, m;
vector<int> edge[maxn];
int vis[maxn];
vector<pair<int, int> > mid;
int dep[maxn], fa[maxn];
void dfs(int u, vector<int>& need, int pre = 0) {
  vis[u] = 1;
  need.push_back(u);
  dep[u] = dep[pre] + 1;
  for (auto v : edge[u]) {
    if (v != pre) {
      dfs(v, need, u);
      fa[v] = u;
    }
  }
}
int get_diameter(int u) {
  vector<int> need;
  dfs(u, need);
  int st = u, ed = u;
  for (auto i : need) {
    if (dep[i] > dep[st]) st = i;
  }
  need.clear();
  dfs(st, need);
  for (auto i : need) {
    if (dep[i] > dep[ed]) ed = i;
  }
  int midnow = dep[ed] - 1 >> 1;
  int t = ed;
  while (midnow--) t = fa[t];
  mid.push_back(make_pair(dep[ed] - 1, t));
  return dep[ed] - 1;
}
int main() {
  scanf("%d%d", &n, &m);
  int u, v;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) get_diameter(i);
  }
  sort(mid.begin(), mid.end());
  for (int i = 0; i < mid.size() - 1; ++i) {
    edge[mid[i].second].push_back(mid[mid.size() - 1].second);
    edge[mid[mid.size() - 1].second].push_back(mid[i].second);
  }
  cout << get_diameter(1) << endl;
  for (int i = 0; i < mid.size() - 2; ++i) {
    cout << mid[mid.size() - 1].second << " " << mid[i].second << endl;
  }
  return 0;
}
