#include <bits/stdc++.h>
using namespace std;
const int N = 1600;
const int N2 = N + N;
const int md = 998244353;
vector<array<int, 2> > vc;
vector<int> g[N2];
int nm[N], a[N][N], n, cmps, pre[N], siz[N2], edg[N], id[N];
int dp[N2][N];
bool ok[N2];
bool cmp(array<int, 2> _x, array<int, 2> _y) {
  return (a[_x[0]][_x[1]] < a[_y[0]][_y[1]]);
}
int get(int x) { return (pre[x] == x ? x : pre[x] = get(pre[x])); }
int sum(int x, int y) {
  x += y;
  if (x >= md) x -= md;
  return x;
}
void SUM(int &x, int y) {
  x += y;
  if (x >= md) x -= md;
}
int mult(int x, int y) { return (1ll * x * y) % md; }
void dfs(int v, int p) {
  siz[v] = bool(v < n);
  for (int u : g[v]) {
    if (u == p) continue;
    dfs(u, v);
    siz[v] += siz[u];
  }
  fill(dp[v], dp[v] + siz[v] + 1, 0);
  dp[v][0] = 1;
  int cur = 0;
  for (int u : g[v]) {
    if (u == p) continue;
    cur += siz[u];
    for (int old = cur; old >= 0; old--) {
      dp[v][old] = 0;
      for (int sz = 1; sz <= siz[u]; sz++) {
        if (old - sz < 0) continue;
        SUM(dp[v][old], mult(dp[v][old - sz], dp[u][sz]));
      }
    }
  }
  if (ok[v]) SUM(dp[v][1], 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) vc.push_back({i, j});
  sort(vc.begin(), vc.end(), cmp);
  for (int i = 0; i < n; i++) {
    pre[i] = i;
    ok[i] = 1;
    siz[i] = 1;
    edg[i] = 0;
    id[i] = i;
  }
  cmps = n;
  for (array<int, 2> cr : vc) {
    int x = cr[0], y = cr[1];
    int xx = get(x), yy = get(y);
    if (xx == yy) {
      edg[xx]++;
      if (edg[xx] == (siz[xx] * (siz[xx] - 1)) / 2) ok[id[xx]] = 1;
    } else {
      pre[xx] = pre[yy];
      siz[yy] += siz[xx];
      g[cmps].push_back(id[xx]);
      g[cmps].push_back(id[yy]);
      id[yy] = cmps;
      edg[yy] += edg[xx] + 1;
      if (edg[yy] == (siz[yy] * (siz[yy] - 1)) / 2) ok[id[yy]] = 1;
      cmps++;
    }
  }
  dfs(cmps - 1, -1);
  for (int i = 1; i <= n; i++) cout << dp[cmps - 1][i] << " ";
  return 0;
}
