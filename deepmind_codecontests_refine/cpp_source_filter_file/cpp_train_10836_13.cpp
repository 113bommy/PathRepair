#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
long long a[MAXN];
long long pw[MAXN];
int main() {
  int n;
  pw[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    pw[i] = (pw[i - 1] * 2LL) % MOD;
  }
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
    }
    long long now = a[1] * pw[n - 1] % MOD;
    long long ans = now;
    for (int i = 2; i <= n; i++) {
      now = (now - a[i - 1] * pw[n - i] % MOD + MOD) % MOD;
      now = (now + a[i] * pw[n - i] % MOD) % MOD;
      ans = (ans + now) % MOD;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
