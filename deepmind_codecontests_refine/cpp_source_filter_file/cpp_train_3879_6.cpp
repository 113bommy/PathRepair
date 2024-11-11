#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
using ll = long long;
int n, m, deg[N], rt[N], ridx, in[N], out[N], dptr;
char s[N];
inline int id(int x, int y) { return (x - 1) * m + y; }
vector<int> v[N];
void dfs(int pos) {
  in[pos] = ++dptr;
  for (auto &i : v[pos]) dfs(i);
  out[pos] = dptr;
}
struct Rect {
  int u, d, l, r;
} r[N];
int idxq, idxr;
struct Query {
  int u, d, p, v;
} q[N];
struct TNode {
  int l, r, v;
} t[N << 2];
int lazy[N << 2];
inline int calc(int pos, int l, int r) {
  return !lazy[pos] ? t[pos].v : r - l + 1;
}
inline int lc(int pos) { return pos << 1; }
inline int rc(int pos) { return pos << 1 | 1; }
void build(int pos, int l, int r) {
  t[pos].l = l;
  t[pos].r = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(lc(pos), l, mid);
  build(rc(pos), mid + 1, r);
}
void modify(int pos, int l, int r, int v) {
  if (l == t[pos].l && r == t[pos].r) {
    lazy[pos] += v;
    return;
  }
  int mid = (t[pos].l + t[pos].r) >> 1;
  if (r <= mid)
    modify(lc(pos), l, r, v);
  else if (l > mid)
    modify(rc(pos), l, r, v);
  else
    modify(lc(pos), l, mid, v), modify(rc(pos), mid + 1, r, v);
  t[pos].v = calc(lc(pos), t[pos].l, mid) + calc(rc(pos), mid + 1, t[pos].r);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> (s + (i - 1) * m + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i - 2 >= 1 && s[id(i - 2, j)] == 'U')
        v[id(i, j)].push_back(id(i - 2, j)), ++deg[id(i - 2, j)];
      if (j - 2 >= 1 && s[id(i, j - 2)] == 'L')
        v[id(i, j)].push_back(id(i, j - 2)), ++deg[id(i, j - 2)];
      if (i + 2 <= n && s[id(i + 2, j)] == 'D')
        v[id(i, j)].push_back(id(i + 2, j)), ++deg[id(i + 2, j)];
      if (j + 2 <= m && s[id(i, j + 2)] == 'R')
        v[id(i, j)].push_back(id(i, j + 2)), ++deg[id(i, j + 2)];
    }
  build(1, 1, n * m + 1);
  for (int i = 1; i <= n * m; i++)
    if (!deg[i]) rt[++ridx] = i;
  for (int i = 1; i <= ridx; i++) dfs(rt[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[id(i, j)] == 'U' && s[id(i + 1, j)] == 'D') {
        r[++idxr] = {in[id(i, j)], out[id(i, j)], in[id(i + 1, j)],
                     out[id(i + 1, j)]};
        r[++idxr] = {in[id(i + 1, j)], out[id(i + 1, j)], in[id(i, j)],
                     out[id(i, j)]};
      } else if (s[id(i, j)] == 'L' && s[id(i, j + 1)] == 'R') {
        r[++idxr] = {in[id(i, j)], out[id(i, j)], in[id(i, j + 1)],
                     out[id(i, j + 1)]};
        r[++idxr] = {in[id(i, j + 1)], out[id(i, j + 1)], in[id(i, j)],
                     out[id(i, j)]};
      }
  for (int i = 1; i <= idxr; i++) {
    q[++idxq] = {r[i].u, r[i].d, r[i].l, 1};
    q[++idxq] = {r[i].u, r[i].d, r[i].r + 1, -1};
  }
  sort(q + 1, q + idxq + 1, [](Query a, Query b) { return a.p < b.p; });
  ll ans = 0;
  for (int i = 1; i <= idxq; i++) {
    modify(1, q[i].u, q[i].d, q[i].v);
    if (i != idxq) ans += calc(1, 1, n) * ll(q[i + 1].p - q[i].p);
  }
  cout << ans / 2 << endl;
  return 0;
}
