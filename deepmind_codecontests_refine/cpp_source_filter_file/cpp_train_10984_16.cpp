#include <bits/stdc++.h>
using namespace std;
struct node {
  int to;
  int next;
};
node bian[80010];
int in[400010], out[400010], first[400010], size = 0;
int F[1600010], tim = 0, c[400010], n, m, a, b, p, Ans, num[400010];
long long val[1600010];
void inser(int x, int y) {
  size++;
  bian[size].to = y;
  bian[size].next = first[x];
  first[x] = size;
}
void dfs(int x, int Anc) {
  in[x] = out[x] = ++tim;
  num[tim] = x;
  for (int u = first[x]; u; u = bian[u].next)
    if (bian[u].to != Anc) {
      dfs(bian[u].to, x);
      out[x] = max(out[x], out[bian[u].to]);
    }
}
void pushdown(int Now) {
  F[Now << 1] = F[Now << 1 | 1] = F[Now];
  val[Now << 1] = val[Now << 1 | 1] = (1 << (F[Now] - 1));
  F[Now] = 0;
  return;
}
void build(int Now, int l, int r) {
  if (l == r) {
    val[Now] = (1ll << (c[num[l]] - 1));
    return;
  }
  int Mid = (l + r) >> 1;
  build(Now << 1, l, Mid);
  build(Now << 1 | 1, Mid + 1, r);
  val[Now] = val[Now << 1] | val[Now << 1 | 1];
}
void modify(int Now, int l, int r, int x, int y, int z) {
  if (l >= x && r <= y) {
    F[Now] = z;
    val[Now] = (1ll << (z - 1));
    return;
  }
  if (F[Now] != 0) pushdown(Now);
  int Mid = (l + r) >> 1;
  if (x <= Mid) modify(Now << 1, l, Mid, x, y, z);
  if (y > Mid) modify(Now << 1 | 1, Mid + 1, r, x, y, z);
  val[Now] = val[Now << 1] | val[Now << 1 | 1];
}
long long Ask(int Now, int l, int r, int x, int y) {
  if (l >= x && r <= y) return val[Now];
  if (F[Now] != 0) pushdown(Now);
  int Mid = (l + r) >> 1;
  long long ret = 0;
  if (x <= Mid) ret |= Ask(Now << 1, l, Mid, x, y);
  if (y > Mid) ret |= Ask(Now << 1 | 1, Mid + 1, r, x, y);
  val[Now] = val[Now << 1] | val[Now << 1 | 1];
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    inser(a, b);
    inser(b, a);
  }
  dfs(1, 1);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &p);
    if (p == 1) {
      scanf("%d%d", &a, &b);
      modify(1, 1, n, in[a], out[a], b);
    } else {
      Ans = 0;
      scanf("%d", &a);
      long long w = Ask(1, 1, n, in[a], out[a]);
      while (w > 0) {
        if (w % 2 == 1) Ans++;
        w >>= 1;
      }
      printf("%d\n", Ans);
    }
  }
  return 0;
}
