#include <bits/stdc++.h>
using namespace std;
set<int> st[100001];
int gett(int ii, int lim, int su) {
  int now = 0, jari = 65536;
  while (jari > 0) {
    if (su & jari) {
      int ss = now;
      int ee = min(now + jari - 1, lim);
      if (ss > ee || st[ii].lower_bound(ss) == st[ii].upper_bound(ee)) {
        now += jari;
      }
    } else {
      int ss = now + jari;
      int ee = min(now + jari + jari - 1, lim);
      if (ss <= ee && st[ii].lower_bound(ss) != st[ii].upper_bound(ee)) {
        now += jari;
      }
    }
    jari /= 2;
  }
  return now;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int mode, aa, bb, cc;
    scanf("%d", &mode);
    if (mode == 1) {
      scanf("%d", &aa);
      for (int j = 1; j * j <= aa; j++) {
        if (aa % j == 0) {
          st[j].insert(aa);
          if (j * j < aa) {
            st[aa / j].insert(aa);
          }
        }
      }
    } else {
      scanf("%d%d%d", &aa, &bb, &cc);
      if (aa % bb == 0) {
        if (st[bb].upper_bound(cc - aa) == st[bb].begin()) {
          printf("-1\n");
        } else {
          printf("%d\n", gett(bb, cc - aa, aa));
        }
      } else {
        printf("-1\n");
      }
    }
  }
}
