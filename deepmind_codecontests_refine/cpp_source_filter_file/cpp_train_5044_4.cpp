#include <bits/stdc++.h>
using namespace std;
const int Maxn = 300003;
int fa[Maxn], d[Maxn], h[Maxn], maxd;
vector<int> G[Maxn];
int find(int x) {
  int ret = x;
  for (; fa[ret] != ret; ret = fa[ret])
    ;
  for (; x != ret;) {
    int temp = x;
    x = fa[x];
    fa[temp] = ret;
  }
  return ret;
}
void merge(int x, int y) {
  int xx = find(x), yy = find(y);
  if (xx == yy) return;
  int temp1 = max((d[xx] + 1) / 2 + (d[yy] + 1) / 2 + 1, d[xx]);
  int temp2 = max((d[yy] + 1) / 2 + (d[xx] + 1) / 2 + 1, d[yy]);
  if (temp1 < temp2) {
    fa[yy] = xx;
    d[xx] = temp1;
  } else {
    fa[xx] = yy;
    d[yy] = temp2;
  }
}
void dfs(int u, int ff) {
  int m1 = 0, m2 = 0, hh = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == ff) continue;
    dfs(v, u);
    hh = max(hh, h[v]);
    if (!m1) {
      m1 = h[v];
      continue;
    }
    if (h[v] >= m1) {
      m2 = m1;
      m1 = h[v];
      continue;
    }
    if (!m2 || h[v] > m2) {
      m2 = h[v];
      continue;
    }
  }
  h[u] = hh + 1;
  d[u] = m1 + m2;
  maxd = max(maxd, d[u]);
}
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
    u = find(u), v = find(v);
    fa[u] = v;
  }
  for (int i = 1; i <= n; i++)
    if (!h[i]) {
      maxd = 0;
      dfs(i, -1);
      d[find(i)] = maxd;
    }
  while (q--) {
    int a, b, c;
    scanf("%d%d", &a, &b);
    if (a == 1) {
      printf("%d\n", d[find(b)]);
    } else {
      scanf("%d", &c);
      merge(b, c);
    }
  }
}
