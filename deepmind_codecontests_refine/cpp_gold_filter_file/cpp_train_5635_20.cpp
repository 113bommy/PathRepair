#include <bits/stdc++.h>
#pragma G++ optimize "O2"
#pragma GCC optimize "O2"
#pragma G++ optimize "O3"
#pragma GCC optimize "O3"
#pragma G++ optimize "Ofast"
#pragma GCC optimize "Ofast"
using namespace std;
long long pow4[33];
long long maxlim[33], maxstep[33];
int mmn = -1;
int t;
int main() {
  pow4[0] = 1;
  for (register int i = 1; i < 33; i++) pow4[i] = pow4[i - 1] * 4;
  maxlim[1] = 1;
  maxstep[1] = 1;
  for (register int i = 2; i < 33; i++) {
    maxlim[i] = maxlim[i - 1] + pow4[i - 1];
    if (maxlim[i] > 1e18 && mmn == -1) mmn = i;
    maxstep[i] = maxstep[i - 1] + (1ll << i) - 1;
  }
  scanf("%d", &t);
  for (register int i = 1; i <= t; i++) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    if (n > mmn) {
      printf("YES %lld\n", n - 1);
      continue;
    }
    if (k > maxlim[n]) {
      printf("NO\n");
      continue;
    }
    long long rec = -1;
    for (register int i = 1; i <= n; i++) {
      if (k >= maxstep[i] && k <= maxlim[i] + maxlim[n - i] * ((1ll << i) - 1) *
                                                  ((1ll << i) - 1)) {
        rec = i;
        break;
      }
    }
    if (rec == -1) {
      printf("NO\n");
      continue;
    }
    printf("YES %lld\n", n - rec);
  }
  return 0;
}
