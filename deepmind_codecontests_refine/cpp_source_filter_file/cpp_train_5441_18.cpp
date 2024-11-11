#include <bits/stdc++.h>
using namespace std;
char ss[500010];
int p[300010][2], n;
int mxx, mnx, mxy, mny, mxz, mnz;
int upd(int &mx, int &mn, int v, int x) {
  if (mn > v + x || v - x > mx) return 0;
  mx = min(mx, v + x);
  mn = max(mn, v - x);
  return 1;
}
int f(int x) {
  mxx = mxy = mxz = 1001001001;
  mny = -1001001001;
  mnx = mnz = 0;
  for (int i = 0; i < n; i++) {
    if (!upd(mxx, mnx, p[i][0], x)) return 0;
    if (!upd(mxy, mny, p[i][0] - p[i][1], x)) return 0;
    if (!upd(mxz, mnz, p[i][1], x)) return 0;
  }
  if (mny > mxx - mnz || mxy < mnx - mxz) return 0;
  return 1;
}
void put(int xs, int zs) {
  for (int i = 0; i < max(xs, zs); i++) {
    if (i < xs) putchar('N');
    if (i < zs) putchar('B');
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", ss);
    for (int j = 0; ss[j]; j++) {
      p[i][ss[j] == 'B']++;
    }
  }
  int lo = -1, hi = 501001001;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (f(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  f(hi);
  printf("%d\n", hi);
  int xs = mxx, zs = mxz;
  for (int i = 0; i <= zs; i++) {
    if (mny <= xs - i && xs - i <= mxy) {
      put(xs, i);
      return 0;
    }
  }
  for (int i = 0; i <= xs; i++) {
    if (mny <= i - zs && i - zs <= mxy) {
      put(i, zs);
      return 0;
    }
  }
  return 0;
}
