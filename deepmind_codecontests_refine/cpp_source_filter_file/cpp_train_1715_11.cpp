#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int f[maxn], ans[maxn], p[maxn], top, s[maxn], n, m, x;
struct ask {
  int l, r, id;
} c[maxn];
struct node {
  int l, r;
} a[maxn];
bool operator<(ask a, ask b) { return a.l < b.l; }
inline int gfa(int x) {
  if (f[x] != x) f[x] = gfa(f[x]);
  return f[x];
}
void ins(int i) {
  while (top && a[i].r >= a[s[top]].l)
    a[i].r = max(a[i].r, a[s[top]].r), f[gfa(s[top])] = i, --top;
  if (top != 0)
    p[i] = p[s[top]] + a[s[top]].l - a[i].r;
  else
    p[i] = 0;
  ++top;
  s[top] = i;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].l, &x);
    a[i].r = a[i].l + x;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &c[i].l, &c[i].r), c[i].id = i;
  sort(c + 1, c + m + 1);
  int i = n, j = m;
  for (int i = 1; i <= n; ++i) f[i] = i;
  for (; i && j; --j) {
    while (i && i >= c[j].l) {
      ins(i);
      --i;
    }
    ans[c[j].id] = p[gfa(c[j].l)] - p[gfa(c[j].r)];
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}
