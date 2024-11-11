#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000009;
const int MAXK = 100000;
int n, a, b, k;
char s[MAXK];
int power(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) {
      ans = (long long)ans * a % MOD;
    }
    a = (long long)a * a % MOD, n >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d%d%d%d", &n, &a, &b, &k);
  scanf("%s", s);
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    if (s[i] == '+') {
      int r = (long long)power(a, MOD - 1 - k) * power(b, k) % MOD;
      int x = (long long)power(a, n - i) * power(b, i) % MOD;
      if (r == 1) {
        ans = (ans + x * (n / k + 1ll)) % MOD;
        continue;
      }
      ans = (ans + x * (1ll - power(r, n / k + 1) + MOD) % MOD *
                       power(1 - r + MOD, MOD - 2)) %
            MOD;
    } else {
      int r = (long long)power(a, MOD - 1 - k) * power(b, k) % MOD;
      int x = (MOD - 1ll) * power(a, n - i) % MOD * power(b, i) % MOD;
      ans = (ans + x * (1ll - power(r, n / k + 1) + MOD) % MOD *
                       power(1 - r + MOD, MOD - 2)) %
            MOD;
      if (r == 1) {
        ans = (ans + x * (n / k + 1ll)) % MOD;
        continue;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
