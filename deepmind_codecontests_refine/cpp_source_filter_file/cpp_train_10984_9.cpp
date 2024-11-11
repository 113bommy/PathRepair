#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
long long msk[N], seg[4 * N], lazy[4 * N];
int in[N], lol, out[N];
vector<long long> v;
vector<vector<int>> g;
void dfs(int u, int p) {
  in[u] = lol++;
  v.push_back(msk[u]);
  for (int i = 0; i < g[u].size(); i++) {
    int a = g[u][i];
    if (a == p) continue;
    dfs(a, u);
  }
  out[u] = lol - 1;
}
void fix(int c, int l, int r) {
  if (!lazy[c]) return;
  seg[c] = lazy[c];
  if (l != r) {
    lazy[2 * c + 1] = lazy[c];
    lazy[2 * c + 2] = lazy[c];
  }
  lazy[c] = 0;
}
void update(int c, int l, int r, int s, int e, long long to) {
  fix(c, l, r);
  if (l > e || r < s) return;
  if (l >= s && r <= e) {
    lazy[c] = to;
    fix(c, l, r);
    return;
  }
  update(2 * c + 1, l, (l + r) / 2, s, e, to);
  update(2 * c + 2, (l + r) / 2 + 1, r, s, e, to);
  seg[c] = seg[2 * c + 1] | seg[2 * c + 2];
}
long long get(int c, int l, int r, int s, int e) {
  fix(c, l, r);
  if (l > e || r < s) return 0;
  if (l >= s && r <= e) return seg[c];
  return get(2 * c + 1, l, (l + r) / 2, s, e) |
         get(2 * c + 2, (l + r) / 2 + 1, r, s, e);
}
void build(int c, int l, int r) {
  if (l == r) {
    seg[c] = v[l];
    return;
  }
  build(2 * c + 1, l, (l + r) / 2);
  build(2 * c + 2, (l + r) / 2 + 1, r);
  seg[c] = seg[2 * c + 1] | seg[2 * c + 2];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    msk[i] = 1LL << a;
  }
  g.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    g[--l].push_back(--r);
    g[r].push_back(l);
  }
  dfs(0, -1);
  build(0, 0, v.size() - 1);
  while (m--) {
    int a, b, c;
    scanf("%d%d", &a, &b);
    --b;
    if (a - 1) {
      long long ans = get(0, 0, v.size() - 1, in[b], out[b]);
      printf("%lld\n", __builtin_popcountll(ans));
      continue;
    }
    scanf("%d", &c);
    update(0, 0, v.size() - 1, in[b], out[b], 1LL << c);
  }
}
