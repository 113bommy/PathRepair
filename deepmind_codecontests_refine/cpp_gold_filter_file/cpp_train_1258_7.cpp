#include <bits/stdc++.h>
using namespace std;
const int N = 4 * 1e5 + 69;
long long b[N], res[N], in[N], out[N];
int p[N][20], h[N], n, q, val[N], edge[N];
vector<pair<int, int> > query[N], a[N];
void update(int first, long long val) {
  while (first <= n) {
    b[first] += val;
    first += first & -first;
  }
}
long long get(int first) {
  long long tmp = 0;
  while (first) {
    tmp += b[first];
    first -= first & -first;
  }
  return tmp;
}
int lca(int u, int v) {
  if (h[u] > h[v]) swap(u, v);
  int d = h[v] - h[u];
  for (int i = 19; i >= 0; i--)
    if ((d >> i) & 1) v = p[v][i];
  if (u == v) return u;
  for (int i = 19; i >= 0; i--)
    if (p[u][i] != p[v][i]) {
      u = p[u][i];
      v = p[v][i];
    }
  return p[u][0];
}
int nex(int u, int d) {
  if (d == -1) return -1;
  for (int i = 19; i >= 0; i--)
    if ((d >> i) & 1) u = p[u][i];
  return u;
}
void dfs1(int u) {
  in[u] = val[u];
  for (auto t : a[u]) {
    int v = t.first, w = t.second;
    if (v == p[u][0]) continue;
    h[v] = h[u] + 1;
    edge[v] = w;
    p[v][0] = u;
    for (int i = 1; i <= 19; i++) p[v][i] = p[p[v][i - 1]][i - 1];
    dfs1(v);
    in[u] += max(0LL, in[v] - 2 * w);
  }
}
void dfs2(int u) {
  for (auto t : a[u]) {
    int v = t.first, w = t.second;
    if (v == p[u][0]) continue;
    out[v] = val[v] + max(0LL, -2 * w + out[u] + in[u] -
                                   max(0LL, in[v] - 2 * w) - val[u]);
    dfs2(v);
  }
}
void calc(int u) {
  for (auto t : query[u]) {
    int v = t.first, id = t.second;
    res[id] += get(h[u]) - get(h[v] - 1) - edge[u] + in[u];
  }
  update(h[u], -edge[u] + in[u]);
  long long pre = 0;
  for (auto t : a[u]) {
    int v = t.first, w = t.second;
    if (v == p[u][0]) continue;
    update(h[u], -max(0LL, in[v] - 2 * w) - pre);
    pre = -max(0LL, in[v] - 2 * w);
    calc(v);
  }
  update(h[u], edge[u] - in[u] - pre);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) cin >> val[i];
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    a[u].push_back(make_pair(v, w));
    a[v].push_back(make_pair(u, w));
  }
  h[1] = 1;
  dfs1(1);
  out[1] = val[1];
  dfs2(1);
  for (int i = 1; i <= q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int p = lca(u, v);
    res[i] = out[p] + in[p] - val[p];
    int k = nex(u, h[u] - h[p] - 1);
    if (k != -1) {
      query[u].push_back(make_pair(k, i));
      res[i] -= max(0LL, in[k] - 2 * edge[k]);
    }
    k = nex(v, h[v] - h[p] - 1);
    if (k != -1) {
      query[v].push_back(make_pair(k, i));
      res[i] -= max(0LL, in[k] - 2 * edge[k]);
    }
  }
  calc(1);
  for (int i = 1; i <= q; i++) printf("%I64d\n", res[i]);
}
