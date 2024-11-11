#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N = 200010, Mod = 1e9 + 7;
inline int read() {
  int s = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
int H, W, n, Ans, F[N];
struct Node {
  int u, l, r, s, k;
} a[N];
inline bool cp(Node x, Node y) { return x.s == y.s ? x.u > y.u : x.s < y.s; }
set<int> g[N << 2];
map<int, int> Q;
void UpDate(int u, int v, int l, int r, int x, int k, int opt) {
  if (l >= u && r <= v) {
    if (~opt)
      g[x].insert(k);
    else
      g[x].erase(g[x].find(k));
    return;
  }
  int mid = (l + r) / 2;
  if (u <= mid) UpDate(u, v, l, mid, (x << 1), k, opt);
  if (v > mid) UpDate(u, v, mid + 1, r, (x << 1 | 1), k, opt);
}
int Ask(int pos, int l, int r, int x) {
  int tt = 0;
  if ((int)g[x].size()) tt = (*g[x].rbegin());
  if (l == r) return tt;
  int mid = (l + r) / 2;
  if (pos <= mid)
    tt = max(tt, Ask(pos, l, mid, (x << 1)));
  else
    tt = max(tt, Ask(pos, mid + 1, r, (x << 1 | 1)));
  return tt;
}
signed main() {
  H = read(), W = read(), n = read();
  for (register int i = 1; i <= n; i++) {
    int u, l, r, s;
    u = read(), l = read(), r = read(), s = read();
    a[i * 2 - 1].u = a[i * 2].u = u;
    a[i * 2 - 1].l = a[i * 2].l = l;
    a[i * 2 - 1].r = a[i * 2].r = r;
    a[i * 2 - 1].s = u;
    a[i * 2].s = s + u;
    a[i * 2 - 1].k = 1, a[i * 2].k = -1;
    Q[u] = i;
  }
  sort(a + 1, a + 1 + n + n, cp);
  F[0] = 1;
  for (register int i = 1; i <= n + n; i++) {
    if (a[i].s > H) break;
    if (~a[i].k) {
      if (a[i].l == 1) {
        int x = Ask(a[i].r + 1, 1, W, 1);
        F[Q[a[i].u]] = F[Q[x]] * 2 % Mod;
      } else if (a[i].r == W) {
        int x = Ask(a[i].l - 1, 1, W, 1);
        F[Q[a[i].u]] = F[Q[x]] * 2 % Mod;
      } else {
        int x = Ask(a[i].l - 1, 1, W, 1);
        int y = Ask(a[i].r + 1, 1, W, 1);
        F[Q[a[i].u]] = (F[Q[x]] + F[Q[y]]) % Mod;
      }
    }
    UpDate(a[i].l, a[i].r, 1, W, 1, a[i].u, a[i].k);
  }
  for (register int i = 1; i <= W; i++)
    Ans = (Ans + F[Q[Ask(i, 1, W, 1)]]) % Mod;
  printf("%d\n", Ans);
  return 0;
}
