#include <bits/stdc++.h>
using namespace std;
int scan() {
  int res = 0, ch;
  while (!((ch = getchar()) >= '0' && ch <= '9')) {
    if (ch == EOF) return 1 << 30;
  }
  res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch - '0');
  return res;
}
int flag[1010];
struct is {
  int l, r;
} a[52];
int main() {
  int x, y, z, i, t, u, v, w, l, r;
  int ans = 0;
  scanf("%d%d%d%d", &x, &y, &l, &r);
  for (i = 0; i < x; i++) {
    scanf("%d%d", &u, &v);
    for (t = u; t <= v; t++) {
      flag[t]++;
    }
  }
  for (i = 0; i < y; i++) scanf("%d%d", &a[i].l, &a[i].r);
  for (i = l; i <= r; i++) {
    for (t = 0; t < y; t++) {
      int flag1 = 0;
      for (w = a[t].l; w <= a[t].r; w++)
        if (flag[w + i]) {
          flag1 = 1;
          break;
        }
      if (flag1) {
        ans++;
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
