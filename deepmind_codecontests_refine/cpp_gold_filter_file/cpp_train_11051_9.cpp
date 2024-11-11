#include <bits/stdc++.h>
int main() {
  long long int n, m, i, boy[100000], girl[100000],
      bmax = INT_MIN, bmax2 = INT_MIN, gmin = INT_MAX, bsum = 0, gsum = 0, ans;
  scanf("%I64d %I64d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &boy[i]);
    if (boy[i] > bmax) {
      bmax2 = bmax;
      bmax = boy[i];
    } else if (bmax2 < boy[i]) {
      bmax2 = boy[i];
    }
    bsum += boy[i];
  }
  for (i = 1; i <= m; i++) {
    scanf("%I64d", &girl[i]);
    if (girl[i] < gmin) gmin = girl[i];
    gsum += girl[i];
  }
  if (gmin < bmax) {
    printf("-1\n");
  } else {
    ans = bsum * m;
    ans += gsum;
    ans -= bmax * m;
    if (bmax < gmin) {
      ans += (bmax - bmax2);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
