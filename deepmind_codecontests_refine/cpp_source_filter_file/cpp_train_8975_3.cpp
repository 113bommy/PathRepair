#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-10;
const double pi = acos(-1.0);
const int maxn = 2e5 + 10;
const long long inf = 0x3f3f3f3f;
vector<int> g[maxn];
bool vis[maxn];
int f[maxn];
int dis[maxn], n, m, s;
void dijkstra() {
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        dis[v] = dis[u] + 1;
        q.push(v);
      } else if (dis[v] == dis[u] + 1)
        f[v] = 1;
    }
  }
}
int a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[v].push_back(u);
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) cin >> a[i];
  s = a[q];
  dijkstra();
  int ans1 = 0, ans2 = 0;
  for (int i = q - 1; i >= 1; --i)
    if (dis[a[i]] == dis[a[i + 1]])
      ans1++;
    else
      ans2 += f[a[i]];
  cout << ans1 << ' ' << ans2 + ans1 << endl;
}
