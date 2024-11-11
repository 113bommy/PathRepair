#include <bits/stdc++.h>
using namespace std;
int n, m, mn[500010], mx[500010], a[500010], f[500010], g[500010], v[500010];
int lowbit(int x) { return x & (-x); }
void ins(int x) {
  int i;
  for (i = x; i <= n; i += lowbit(i)) f[i]++;
}
int query(int x) {
  int i, xlh = 0;
  for (i = x; i; i -= lowbit(i)) xlh += f[i];
  return xlh;
}
void xiu(int x, int w) {
  int i;
  for (i = x; i <= n; i += lowbit(i)) g[i] += w;
}
int cha(int x) {
  int i, xlh = 0;
  for (i = x; i; i -= lowbit(i)) xlh += g[i];
  return xlh;
}
int main() {
  int i, x;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) mn[i] = mx[i] = i;
  for (i = 1; i <= m; i++) {
    scanf("%d", &x);
    if (!v[x]) {
      v[x] = i;
      mn[x] = 1;
      mx[x] = max(mx[x], query(n) - query(x) + x);
      ins(x);
      xiu(i, 1);
    } else {
      ;
      mx[x] = max(mx[x], cha(m) - cha(v[x]) + 1);
      mn[x] = 1;
      xiu(v[x], -1);
      xiu(i, 1);
      v[x] = i;
    }
  }
  for (i = 1; i <= n; i++) {
    if (!v[i]) mx[i] = max(mx[i], query(n) - query(i) + i);
    if (v[i]) {
      mx[i] = max(mx[i], cha(m) - cha(v[i]) + 1);
    }
    printf("%d %d\n", mn[i], mx[i]);
  }
}
