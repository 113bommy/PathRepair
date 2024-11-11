#include <bits/stdc++.h>
using namespace std;
const int N = 200008;
const long long M = 1ll << 60;
int n, m, st, ans, topo[N], f[N][20], dep[N], cot[N];
int e2[] = {1,     2,     4,     8,      16,     32,    64,
            128,   256,   512,   1024,   2048,   4096,  8192,
            16384, 32768, 65536, 131072, 262144, 524288};
vector<pair<int, int> > e[N];
vector<int> a[N];
long long dis[N];
priority_queue<pair<long long, int> > d;
int lca(int x, int y) {
  if (dep[y] > dep[x]) {
    int z = y;
    y = x;
    x = z;
  }
  for (int k = 18; k >= 0; k--) {
    if (dep[x] - e2[k] >= dep[y]) x = f[x][k];
  }
  if (x == y) return x;
  for (int k = 18; k >= 0; k--) {
    if (f[x][k] != f[y][k]) {
      x = f[x][k];
      y = f[y][k];
    }
  }
  return f[x][0];
}
int dfs(int x) {
  cot[x] = 1;
  for (auto p : a[x]) cot[x] += dfs(p);
  if (x != st && cot[x] > ans) ans = cot[x];
  return cot[x];
}
int read(void) {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int t = 0;
  do {
    t = (t << 1) + (t << 3) + c - 48;
    c = getchar();
  } while (c >= '0' && c <= '9');
  return t;
}
int main(void) {
  int i, j, k, p1, p2, p3;
  pair<long long, int> p, q;
  n = read();
  m = read();
  st = read();
  for (i = 1; i <= m; i++) {
    p1 = read();
    p2 = read();
    p3 = read();
    e[p1].push_back(make_pair(p2, p3));
    e[p2].push_back(make_pair(p1, p3));
  }
  for (i = 1; i <= n; i++) {
    dis[i] = M;
  }
  d.push(make_pair(0, st));
  topo[0] = 0;
  while (!d.empty()) {
    p = d.top();
    d.pop();
    if (dis[p.second] < M) continue;
    dis[p.second] = -p.first;
    topo[++topo[0]] = p.second;
    for (auto w : e[p.second])
      if (dis[w.first] == M)
        d.push(make_pair(-dis[p.second] - w.second, w.first));
  }
  for (j = 0; j <= 18; j++) {
    f[st][j] = st;
  }
  dep[st] = 1;
  for (i = 2; i <= topo[0]; i++) {
    j = 0;
    for (auto p : e[topo[i]])
      if (dis[topo[i]] == dis[p.first] + p.second) {
        j = (j ? lca(j, p.first) : p.first);
      }
    a[j].push_back(topo[i]);
    f[topo[i]][0] = j;
    dep[topo[i]] = dep[j] + 1;
    k = 18;
    for (j = 1; j <= k; j++) f[topo[i]][j] = f[f[topo[i]][j - 1]][j - 1];
  }
  ans = 0;
  dfs(st);
  printf("%d", ans);
  return 0;
}
