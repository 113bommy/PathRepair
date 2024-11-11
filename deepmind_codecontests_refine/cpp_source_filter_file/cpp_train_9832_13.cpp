#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1000 * 100 + 100, K = 20;
long long n, m, mark[maxn], t, q, par[maxn][K], mx[maxn][K], sum[maxn], p[maxn],
    cnt, h[maxn];
vector<pair<long long, long long> > v[maxn];
pair<int, pair<int, int> > e[maxn];
int find(int x) {
  if (p[x] == x) return x;
  return p[x] = find(p[x]);
}
void merge(int x, int y) { p[find(x)] = find(y); }
void dfs(int x, int parent, int d) {
  mark[x] = t;
  par[x][0] = parent;
  mx[x][0] = d;
  for (int i = 1; i < K; i++) {
    par[x][i] = par[par[x][i - 1]][i - 1];
    mx[x][i] = max(mx[par[x][i - 1]][i - 1], mx[x][i - 1]);
  }
  for (int i = 0; i < v[x].size(); i++) {
    int next = v[x][i].first, w = v[x][i].second;
    if (!mark[next]) {
      sum[t] += w;
      h[next] = h[x] + 1;
      dfs(next, x, w);
    }
  }
}
int LCA(int x, int y) {
  if (h[x] < h[y]) swap(x, y);
  long long d = h[x] - h[y];
  long long MX = 0;
  for (int i = 0; i < K; i++) {
    if (d & (1 << i)) {
      MX = max(MX, mx[x][i]);
      x = par[x][i];
    }
  }
  for (int i = K - 1; i >= 0; i--) {
    if (par[x][i] != par[y][i]) {
      MX = max(MX, mx[x][i]);
      MX = max(MX, mx[y][i]);
      x = par[x][i];
      y = par[y][i];
    }
  }
  if (x != y) MX = max(MX, max(par[x][0], par[y][0]));
  return MX;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    e[i] = make_pair(w, make_pair(x, y));
  }
  for (int i = 1; i <= n; i++) p[i] = i;
  sort(e, e + m);
  cnt = n;
  for (int i = 0; i < m; i++) {
    long long w = e[i].first, x = e[i].second.first, y = e[i].second.second;
    long long px = find(x), py = find(y);
    if (px == py) continue;
    merge(x, y);
    cnt--;
    v[x].push_back(make_pair(y, w));
    v[y].push_back(make_pair(x, w));
  }
  for (int i = 1; i <= n; i++) {
    find(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) {
      t++;
      dfs(i, 0, 0);
    }
  }
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (cnt > 2 || (cnt == 2 && p[x] == p[y]))
      cout << -1 << endl;
    else if (cnt == 2)
      cout << sum[1] + sum[2] << endl;
    else if (cnt == 1)
      cout << sum[1] - LCA(x, y) << endl;
  }
  return 0;
}
