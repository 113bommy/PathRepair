#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int rt[maxn], n, m, q, down[maxn], sz[maxn], d[maxn], zj[maxn], cnt;
vector<int> g[maxn];
vector<int> h[maxn];
vector<long long> sum[maxn];
map<int, double> mp[maxn];
void dfs1(int p, int fa) {
  sz[rt[p]]++;
  for (int i = 0; i < g[p].size(); i++) {
    int v = g[p][i];
    if (v == fa) continue;
    rt[v] = rt[p];
    dfs1(v, p);
    down[p] = max(down[p], down[v] + 1);
  }
}
void dfs2(int p, int fa) {
  int mx1 = -1, mx2 = -1;
  d[p] = down[p];
  for (int i = 0; i < g[p].size(); i++) {
    int v = g[p][i];
    if (down[v] > mx1) {
      mx1 = mx2;
      mx1 = down[v];
    } else if (down[v] > mx2)
      mx2 = down[v];
  }
  for (int i = 0; i < g[p].size(); i++) {
    int v = g[p][i], val = down[p], v2 = down[v];
    if (v == fa) continue;
    if (down[v] == mx1)
      down[p] = mx2 + 1;
    else
      down[p] = mx1 + 1;
    down[v] = max(down[v], down[p] + 1);
    dfs2(v, p);
    down[p] = val;
    down[v] = v2;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    if (!rt[i]) {
      rt[i] = ++cnt;
      dfs1(i, 0);
      dfs2(i, 0);
    }
  for (int i = 1; i <= n; i++) {
    zj[rt[i]] = max(zj[rt[i]], d[i]);
    h[rt[i]].push_back(d[i]);
  }
  for (int i = 1; i <= cnt; i++) {
    sort(h[i].begin(), h[i].end());
    sum[i].push_back(h[i][0]);
    for (int j = 1; j < h[i].size(); j++)
      sum[i].push_back(sum[i][j - 1] + h[i][j]);
  }
  for (int i = 1; i <= q; i++) {
    int x, y, u, v;
    scanf("%d%d", &x, &y);
    u = rt[x];
    v = rt[y];
    if (u == v)
      puts("-1");
    else {
      if (sz[u] > sz[v] || (sz[u] == sz[v] && u > v)) swap(u, v);
      if (mp[u].count(v))
        printf("%.9lf\n", mp[u][v]);
      else {
        int maxx = max(zj[u], zj[v]);
        long long res = 0;
        for (int j = 0; j < h[u].size(); j++) {
          int p = h[u][j];
          if (h[v][sz[v] - 1] + p + 1 <= maxx)
            res += (long long)sz[v] * maxx;
          else {
            int nx = upper_bound(h[v].begin(), h[v].end(), maxx - 1 - p) -
                     h[v].begin();
            res += (long long)nx * maxx + (long long)(sz[v] - nx) * (p + 1);
            res += sum[v][sz[v] - 1];
            if (nx) res -= sum[v][nx - 1];
          }
        }
        double out = (double)res / (double)(sz[u] * sz[v]);
        printf("%.9lf\n", out);
        mp[u][v] = out;
      }
    }
  }
  return 0;
}
