#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
int T, n;
long long f[MAXN];
signed main() {
  f[0] = f[1] = f[2] = 0;
  for (int i = 3; i <= MAXN - 5; i++) {
    if (i % 3 == 0)
      f[i] = f[i - 1] + f[i - 2] * 2 + 4;
    else
      f[i] = f[i - 1] + f[i - 2] * 2;
    f[i] %= 1000000007;
  }
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%lld\n", f[n]);
  }
  return 0;
}
