#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 1;
int n, Q, col[N], in[N], out[N], id, lazy[N];
long long a[N], seg[N];
vector<int> g[N];
void DFS(int u, int p) {
  in[u] = id++;
  for (auto v : g[u])
    if (v != p) DFS(v, u);
  out[u] = id - 1;
}
void build(int c, int l, int r) {
  if (l == r) {
    seg[c] = a[l];
    return;
  }
  build(2 * c + 1, l, (l + r) / 2);
  build(2 * c + 2, (l + r) / 2 + 1, r);
  seg[c] = seg[2 * c + 1] | seg[2 * c + 2];
}
void fix(int c, int l, int r) {
  if (lazy[c] == -1) return;
  seg[c] = (1ll << lazy[c]);
  if (l != r) lazy[2 * c + 1] = lazy[2 * c + 2] = lazy[c];
  lazy[c] = -1;
}
void update(int c, int l, int r, int s, int e, int val) {
  fix(c, l, r);
  if (l > e || r < s) return;
  if (l >= s && r <= e) {
    lazy[c] = val;
    fix(c, l, r);
    return;
  }
  update(2 * c + 1, l, (l + r) / 2, s, e, val);
  update(2 * c + 2, (l + r) / 2 + 1, r, s, e, val);
  seg[c] = seg[2 * c + 1] | seg[2 * c + 2];
}
long long get(int c, int l, int r, int s, int e) {
  fix(c, l, r);
  if (l >= s && r <= e) return seg[c];
  if (l > e || r < s) return 0;
  return get(2 * c + 1, l, (l + r) / 2, s, e) |
         get(2 * c + 2, (l + r) / 2 + 1, r, s, e);
}
int main() {
  scanf("%d%d", &n, &Q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", col + i);
  }
  for (int i = 0, u, v; i < n - 1; ++i) {
    scanf("%d%d", &u, &v), --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  DFS(0, -1);
  for (int i = 0; i < n; ++i) {
    a[in[i]] = (1ll << col[i]);
  }
  build(0, 0, n - 1);
  memset(lazy, -1, sizeof lazy);
  while (Q--) {
    int t, v, c;
    scanf("%d%d", &t, &v), --t, --v;
    if (t) {
      printf("%d\n", __builtin_popcountll(get(0, 0, n - 1, in[v], out[v])));
    } else {
      scanf("%d", &c);
      update(0, 0, n - 1, in[v], out[v], c);
    }
  }
}
