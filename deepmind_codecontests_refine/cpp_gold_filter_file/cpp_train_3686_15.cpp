#include <bits/stdc++.h>
using namespace std;
const int sq = 317;
const int N = (int)1e5 + 5;
int n, l, m, di[N], d[N], up[N][20], tin[N], tout[N], timer;
vector<int> g[N];
int q[(int)1e7], qb, qe;
void Dfs(int v, int k, int p = 1) {
  tin[v] = ++timer;
  d[v] = di[v] = k;
  up[v][0] = p;
  for (int i = 1; i <= l; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }
  for (auto to : g[v]) {
    if (to != p) {
      Dfs(to, k + 1, v);
    }
  }
  tout[v] = ++timer;
}
bool Upper(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }
int LCA(int a, int b) {
  if (Upper(a, b)) {
    return a;
  }
  if (Upper(b, a)) {
    return b;
  }
  for (int i = l; i >= 0; i--) {
    if (!Upper(up[a][i], b)) {
      a = up[a][i];
    }
  }
  return up[a][0];
}
void Update() {
  while (qb < qe) {
    int v = q[qb];
    qb++;
    for (auto to : g[v]) {
      if (di[to] > di[v] + 1) {
        di[to] = di[v] + 1;
        q[qe] = to;
        qe++;
      }
    }
  }
  qb = qe = 0;
}
int Get(int a) {
  int ans = di[a];
  for (int i = qb; i < qe; i++) {
    int dis = d[a] + d[q[i]] - 2 * d[LCA(a, q[i])];
    ans = min(ans, dis);
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  while ((1 << l) <= n) {
    l++;
  }
  Dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    int type, x;
    scanf("%d%d", &type, &x);
    if (i / sq != (i - 1) / sq) {
      Update();
    }
    if (type == 1) {
      q[qe] = x;
      qe++;
      di[x] = 0;
    } else {
      printf("%d\n", Get(x));
    }
  }
  return 0;
}
