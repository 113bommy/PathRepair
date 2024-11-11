#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5;
long long dv[10005];
long long cr[MX + 5], ax[MX + 5];
int ncr, na;
int nd;
int main() {
  long long x, k;
  scanf("%I64d %I64d", &x, &k);
  if (k == 0) {
    printf("%I64d", x);
    return 0;
  }
  if (x == 1) {
    printf("1");
    return 0;
  }
  if (k >= MX) {
    for (int i = 1; i <= MX; i++) {
      printf("1 ");
    }
    return 0;
  }
  for (int i = 1; 1LL * i * i <= x; i++) {
    if (x % i == 0) {
      dv[++nd] = i;
      if (i * i != x) {
        dv[++nd] = x / i;
      }
    }
  }
  sort(dv + 1, dv + nd + 1);
  cr[1] = x;
  ncr = 1;
  bool ok = true;
  int step = 0;
  while (ok && step < k) {
    step++;
    ok = false;
    na = 0;
    for (int i = 1; i <= ncr && na < MX; i++) {
      int nr = 0;
      for (int j = 1; j <= nd && dv[j] <= cr[i] && na < MX; j++) {
        if (cr[i] % dv[j] == 0) {
          ax[++na] = dv[j];
          nr++;
        }
      }
      if (nr != 2 && cr[i] != 1) {
        ok = true;
      }
    }
    for (int i = 1; i <= na; i++) {
      cr[i] = ax[i];
    }
    ncr = na;
  }
  if (step == k) {
    for (int i = 1; i <= ncr; i++) {
      printf("%I64d ", cr[i]);
    }
    return 0;
  }
  int need = k - step;
  na = 0;
  for (int i = 1; i <= ncr && na < MX; i++) {
    if (cr[i] == 1) {
      ax[++na] = 1;
    } else {
      for (int j = 1; j <= need && na < MX; j++) {
        ax[++na] = 1;
      }
      ax[++na] = cr[i];
    }
  }
  for (int i = 1; i <= na && i <= MX; i++) {
    printf("%I64d ", ax[i]);
  }
  return 0;
}
