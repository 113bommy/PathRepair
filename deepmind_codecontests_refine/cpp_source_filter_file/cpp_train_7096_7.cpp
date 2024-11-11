#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
const long long mod = 1e9 + 7;
struct node {
  int l, r;
} p[2][maxn], p1[maxn];
int ans[maxn];
int fa[maxn];
int finds(int x) {
  if (fa[x] == x) return x;
  return fa[x] = finds(fa[x]);
}
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  int cnt0 = 0, cnt1 = 0;
  for (int i = (1); i <= (m); i++) {
    int t, l, r;
    scanf("%d", &t);
    scanf("%d", &l);
    scanf("%d", &r);
    if (t == 0)
      p[t][++cnt0] = (node){l, r};
    else
      p[t][++cnt1] = (node){l, r};
  }
  for (int i = (1); i <= (cnt1); i++) fa[i] = i;
  for (int i = (1); i <= (cnt1); i++)
    for (int j = (1); j <= (cnt1); j++) {
      if (j == i) continue;
      if ((p[1][i].l >= p[1][j].l && p[1][i].r <= p[1][j].r) ||
          (p[1][i].l <= p[1][j].l && p[1][i].r >= p[1][j].r) ||
          (p[1][i].r >= p[1][j].l && p[1][i].r <= p[1][j].r) ||
          (p[1][i].l >= p[1][j].l && p[1][i].l <= p[1][j].r)) {
        int x = finds(i), y = finds(j);
        if (x != y) fa[x] = y;
      }
    }
  for (int i = (1); i <= (cnt1); i++) p1[i].l = 1e9, p1[i].r = -1e9;
  for (int i = (1); i <= (cnt1); i++) {
    int x = finds(i);
    p1[x].l = min(p1[x].l, p[1][i].l);
    p1[x].r = max(p1[x].r, p[1][i].r);
  }
  for (int i = (1); i <= (cnt1); i++) {
    if (p1[i].l > p1[i].r) continue;
    for (int j = (1); j <= (cnt1); j++)
      if (p[0][j].l >= p1[i].l && p[0][j].r <= p1[i].r) {
        puts("NO");
        return 0;
      }
    for (int o = (p1[i].l); o <= (p1[i].r - 1); o++) ans[o] = 1;
    ans[p1[i].r] = 200002;
  }
  int now = 200000;
  for (int i = (1); i <= (n); i++) {
    if (ans[i]) {
      now = 200000;
      continue;
    }
    ans[i] = now--;
  }
  puts("YES");
  for (int i = (1); i <= (n); i++) printf("%d ", ans[i]);
}
