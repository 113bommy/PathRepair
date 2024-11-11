#include <bits/stdc++.h>
using namespace std;
struct trap {
  int l;
  int r;
  int lvl;
  bool operator<(const trap& tp) const {
    if (l != tp.l) return l < tp.l;
    return r < tp.r;
  }
};
int m, n, k, t, ma, mi, mid;
int a[(int)2e5 + 5];
trap b[(int)2e5 + 5];
bool ch(int val) {
  int i = 1, ti = n, l, r;
  while (i <= k) {
    if (b[i].lvl > val) {
      l = b[i].l, r = b[i].r;
      while (i <= k && b[i].l <= r) {
        if (b[i].lvl > val) r = max(r, b[i].r);
        i++;
      }
      ti += r - l + 1 << 1;
    } else
      i++;
  }
  if (ti > t) return false;
  return true;
}
int bs() {
  if (!ch(a[m])) return 0;
  ma = m, mi = 1;
  while (mi < ma) {
    mid = mi + ma >> 1;
    if (ch(a[mid]))
      ma = mid;
    else
      mi = mid + 1;
  }
  return m - mi + 1;
}
int main() {
  int x, y, z;
  scanf("%d%d%d%d", &m, &n, &k, &t);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d%d", &x, &y, &z);
    b[i] = {x, y, z};
  }
  sort(b + 1, b + k + 1);
  printf("%d", bs());
}
