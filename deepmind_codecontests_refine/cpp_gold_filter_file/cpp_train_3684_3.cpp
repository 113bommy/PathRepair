#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 10;
const int inf = 1e9 + 7;
int n;
int p[maxn];
bool mark[maxn];
vector<int> bois;
int a[maxn][maxn];
int dis[maxn][maxn];
long long ans[maxn];
void in();
void solve();
long long get();
void add(int u);
void dijk(int u);
void out();
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  in();
  solve();
  out();
}
void in() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) cin >> p[i];
}
void solve() {
  reverse(p, p + n);
  memset(dis, inf, sizeof dis);
  for (int i = 0; i < n; i++) {
    add(p[i] - 1);
    ans[i] = get();
  }
  reverse(ans, ans + n);
}
long long get() {
  long long ret = 0;
  for (auto u : bois)
    for (auto v : bois) ret += dis[u][v];
  return ret;
}
void add(int u) {
  for (int U : bois)
    for (int V : bois) dis[U][u] = min(dis[U][u], dis[U][V] + a[V][u]);
  bois.push_back(u);
  dijk(u);
  for (int U : bois)
    for (int V : bois) dis[U][V] = min(dis[U][V], dis[U][u] + dis[u][V]);
}
void dijk(int u) {
  dis[u][u] = 0;
  for (auto i : bois) mark[i] = 0;
  for (int i = 0; i < bois.size(); i++) {
    int x = -1;
    for (auto j : bois) {
      if (!mark[j]) {
        if (x == -1)
          x = j;
        else if (dis[u][x] > dis[u][j])
          x = j;
      }
    }
    mark[x] = 1;
    for (auto j : bois) dis[u][j] = min(dis[u][j], dis[u][x] + a[x][j]);
  }
}
void out() {
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}
