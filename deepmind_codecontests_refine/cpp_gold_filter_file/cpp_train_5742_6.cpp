#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int vis[maxn], cnt, to[maxn * 2], f[maxn], nex[maxn * 2], res, color[maxn * 2];
int n, k;
void add(int a, int b) {
  cnt++;
  to[cnt] = b;
  nex[cnt] = f[a];
  f[a] = cnt;
}
void dfs(int x, int fa, int r) {
  vis[x] = 1;
  int p = 1;
  if (x == 1) p = 0;
  int f2 = fa % r + 1;
  for (int i = f[x]; i; i = nex[i]) {
    int v = to[i];
    if (vis[v]) continue;
    p++;
    color[i] = f2;
    if (i % 2 == 0) color[i - 1] = f2;
    dfs(v, f2, r);
    f2 = f2 % r + 1;
  }
  if (p > r) res++;
}
int check(int r) {
  res = 0;
  for (int i = 0; i < maxn; i++) vis[i] = 0;
  dfs(1, 0, r);
  if (res <= k)
    return 1;
  else
    return 0;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    add(a, b);
    add(b, a);
  }
  int st = 1, en = n - 1;
  while (st != en) {
    int md = (st + en) / 2;
    if (check(md))
      en = md;
    else
      st = md + 1;
  }
  check(st);
  printf("%d\n", st);
  for (int i = 1; i <= cnt; i += 2) printf("%d ", color[i]);
  printf("\n");
  return 0;
}
