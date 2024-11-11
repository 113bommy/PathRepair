#include <bits/stdc++.h>
using namespace std;
inline int maxi(int a, int b) { return (a > b) ? a : b; }
inline void gtmx(int &a, int b) {
  if (a < b) a = b;
}
int mx[22][200010];
int tab[200010], pwr[22];
int nxt[200010][33];
int tmp[33];
inline int query(int l, int r) {
  int ned = tab[r - l + 1];
  return maxi(mx[ned][l], mx[ned][r - pwr[ned] + 1]);
}
int main(void) {
  pwr[0] = 1;
  for (int i = 1; i <= 21; ++i) {
    pwr[i] = pwr[i - 1] << 1;
  }
  int pnt = 0;
  for (int j = 1; j <= 200000; j++) {
    if (j >= pwr[pnt + 1]) pnt++;
    tab[j] = pnt;
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &mx[0][i]);
  }
  for (int i = 1; i <= 20; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j + pwr[i - 1] > n) {
        mx[i][j] = mx[i - 1][j];
        continue;
      }
      mx[i][j] = maxi(mx[i - 1][j], mx[i - 1][j + pwr[i - 1]]);
    }
  }
  memset(tmp, 255, sizeof(tmp));
  for (int i = n; i; --i) {
    for (int j = 0; j <= 30; ++j) {
      if (mx[0][i] & (1 << j)) tmp[j] = i;
    }
    memcpy(nxt[i], tmp, sizeof(tmp));
  }
  register long long res = 0;
  register int i, j, cur, cx, l, r, md;
  for (i = 1; i <= n; ++i) {
    memcpy(tmp, nxt[i], sizeof(tmp));
    sort(&tmp[0], &tmp[31]);
    tmp[31] = n + 1;
    cur = mx[0][i], cx = i;
    for (j = 0; j <= 30; ++j) {
      if (tmp[j] == tmp[j + 1] || tmp[j] == -1) continue;
      cur |= mx[0][tmp[j]];
      if (query(i, tmp[j]) == cur) continue;
      l = tmp[j], r = tmp[j + 1], md;
      while (l + 1 < r) {
        md = (l + r) >> 1;
        if (query(tmp[j], md) < cur) {
          l = md;
        } else {
          r = md;
        }
      }
      res += (l - tmp[j] + 1);
    }
  }
  printf("%I64d", res);
  return 0;
}
