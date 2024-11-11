#include <bits/stdc++.h>
using namespace std;
const int N = 300100;
set<int> S[N];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    vec[N];
vector<int> g[N];
int fa[N], fat[N], tag[N], sz[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void dfs(int x) {
  for (int i : g[x])
    if (i != fat[x]) {
      fat[i] = x;
      sz[x]++;
      dfs(i);
    }
}
int n, m;
void U(int x, int y) {
  fa[y] = x;
  if (vec[x].size() < vec[y].size()) {
    swap(vec[x], vec[y]);
    swap(tag[x], tag[y]);
  }
  --sz[x];
  sz[x] += sz[y];
  while (!vec[y].empty()) {
    auto i = vec[y].top();
    vec[y].pop();
    i.first += tag[y] - tag[x];
    vec[x].push(i);
  }
}
int q[N], cnt;
long long ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x == y) continue;
    vec[x].emplace(z, y);
  }
  for (int i = 2; i <= n; i++)
    if (!sz[i]) q[++cnt] = i;
  for (; cnt;) {
    int u = find(q[cnt--]);
    if (vec[u].empty()) {
      cout << -1 << endl;
      return 0;
    }
    int v = vec[u].top().second, w = vec[u].top().first + tag[u];
    ans += w;
    vec[u].pop();
    tag[u] -= w;
    v = find(v);
    while (u != v) {
      int t = find(fat[u]);
      U(t, u);
      u = find(u);
    }
    if (u != 1 && !sz[u]) q[++cnt] = u;
  }
  cout << ans << endl;
  return 0;
}
