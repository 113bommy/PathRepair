#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000000;
int main() {
  int a[110];
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long f[110];
  f[0] = f[1] = 1;
  for (int i = 2; i <= 100; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % mod;
  }
  int cd, x, y;
  while (m--) {
    scanf("%d%d%d", &cd, &x, &y);
    if (cd == 1)
      a[x] = y;
    else if (cd == 2) {
      long long ans = 0;
      for (int i = 0; i <= y - x; i++) {
        ans = (ans + f[i] * a[i + x]) % mod;
      }
      cout << ans << endl;
    } else {
      int z;
      scanf("%d", &z);
      for (int i = x; i <= y; i++) a[i] += z;
    }
  }
  return 0;
}
