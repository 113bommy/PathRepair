#include <bits/stdc++.h>
using namespace std;
const int P = 1e9;
int cnt, tree[10000000][2], f[10000000], fa[10000000], a[10000], m, n, ans;
int add(int x, int y) {
  tree[x][y] = ++cnt;
  fa[cnt] = x;
  int now = cnt, ss = 0, s = 0, ff;
  for (int i = 1; i <= 4; i++) {
    ff = fa[now];
    if (tree[ff][1] == now)
      s = 1;
    else
      s = 0;
    ss += s << (i - 1);
    if (i != 4 || ((ss != 3) && (ss != 5) && (ss != 14) && (ss != 15)))
      f[cnt] = (0ll + f[cnt] + f[ff]) % P;
    now = fa[now];
    if (now == 0) break;
  }
  ans = (0ll + ans + f[cnt]) % P;
  return 0;
}
int insert(int x) {
  a[++m] = 0;
  for (int i = 1; i <= m; i++) {
    if (!tree[a[i]][x]) add(a[i], x);
    a[i] = tree[a[i]][x];
  }
  return 0;
}
int main() {
  int x;
  f[0] = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    insert(x);
    printf("%d\n", ans);
  }
}
