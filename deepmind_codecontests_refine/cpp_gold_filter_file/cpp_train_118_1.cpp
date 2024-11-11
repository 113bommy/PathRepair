#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 998244353;
int a[N], num[100], b[N][20];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int x = a[i], cnt = 0;
    while (x) b[i][++cnt] = x % 10, x /= 10;
    num[cnt]++;
    b[i][0] = cnt;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int z = 1; z <= 10; z++) {
      long long cmp = 0;
      long long tmp = 1;
      for (int j = 1; j <= b[i][0]; j++) {
        (cmp += tmp * b[i][j] % mod) %= mod;
        if (j <= z)
          (tmp *= 100) %= mod;
        else
          (tmp *= 10) %= mod;
      }
      (ans += cmp * num[z] % mod) %= mod;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int z = 1; z <= 10; z++) {
      long long cmp = 0, tmp = 10;
      for (int j = 1; j <= b[i][0]; j++) {
        (cmp += tmp * b[i][j] % mod) %= mod;
        if (j < z)
          (tmp *= 100) %= mod;
        else
          (tmp *= 10) %= mod;
      }
      (ans += cmp * num[z] % mod) %= mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
