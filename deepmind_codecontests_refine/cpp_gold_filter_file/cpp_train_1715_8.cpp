#include <bits/stdc++.h>
using namespace std;
int n, q;
int p[200009], l[200009];
int f[200009], g[200009];
int it[8 * 200009];
void input() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i], &l[i]);
  scanf("%d", &q);
}
int chat(int x) {
  int l, r, g, res;
  l = 1;
  r = n;
  res = 0;
  while (l <= r) {
    g = (l + r) / 2;
    if (p[g] <= x) {
      res = g;
      l = g + 1;
    } else
      r = g - 1;
  }
  return res;
}
void update(int x, int l, int r, int u, int v) {
  if (l == u && u == r) {
    it[x] = max(it[x], v);
    return;
  }
  if (u < l || r < u) return;
  update(2 * x, l, (l + r) / 2, u, v);
  update(2 * x + 1, (l + r) / 2 + 1, r, u, v);
  it[x] = max(it[2 * x], it[2 * x + 1]);
}
int get(int x, int l, int r, int u, int v) {
  if (u <= l && r <= v) return it[x];
  if (r < u || v < l) return 0;
  return max(get(2 * x, l, (l + r) / 2, u, v),
             get(2 * x + 1, (l + r) / 2 + 1, r, u, v));
}
void solve() {
  for (int i = n; i >= 1; i--) {
    int j = chat(p[i] + l[i]);
    int s = max(get(1, 1, n, i, j), p[i] + l[i]);
    int k = chat(s) + 1;
    f[i] = f[k] + max(0, p[k] - s);
    update(1, 1, n, i, s);
  }
  for (int i = 1; i <= q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int s = get(1, 1, n, u, chat(p[v] + l[v]));
    int k = chat(s) + 1;
    cout << f[u] - f[k] - max(0, p[k] - s) << endl;
  }
}
int main() {
  input();
  solve();
  return 0;
}
