#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n, x, y, z, rt, rt1, tot, a[N], last[N * 2], nex[N * 2], to[N * 2];
bool bz;
void add(int x, int y) {
  to[++tot] = y;
  nex[tot] = last[x];
  last[x] = tot;
}
void dg(int x, int y, int cl, int l) {
  if (l > z) z = l, rt1 = x;
  for (int i = last[x]; i; i = nex[i])
    if (to[i] ^ y)
      dg(to[i], x, !a[to[i]] ? cl : a[to[i]], l + (a[to[i]] != cl && a[to[i]]));
}
int main() {
  scanf("%d", &t);
  while (t--) {
    tot = 0, bz = 0, z = -1;
    for (int i = 1; i <= n; i++) last[i] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i]) bz = 1, rt = i;
    }
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &x, &y);
      add(x, y), add(y, x);
    }
    if (!bz) {
      printf("1");
      continue;
    }
    dg(rt, 0, a[rt], 0);
    dg(rt1, 0, a[rt1], 0);
    printf("%d\n", (z + 1) / 2 + 1);
  }
  return 0;
}
