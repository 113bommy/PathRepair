#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const long long MOD = 1000000007;
int n;
int l[MAXN];
int r[MAXN];
long long tot, ans;
long long cnt[MAXN];
long long dif[MAXN];
long long sam[MAXN];
long long pre[MAXN];
long long suf[MAXN];
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) (res *= a) %= MOD;
    (a *= a) %= MOD;
    b >>= 1;
  }
  return res;
}
long long calc(long long la, long long ra, long long lb, long long rb) {
  int MIN = max(la, lb), MAX = min(ra, rb);
  return ((ra - la + 1) * (rb - lb + 1) - max(0, MAX - MIN + 1)) % MOD *
         power((ra - la + 1) * (rb - lb + 1) % MOD, MOD - 2) % MOD;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
  tot = 1;
  for (int i = 1; i <= n; i++) {
    cnt[i] = (r[i] - l[i] + 1);
    (tot *= cnt[i]) %= MOD;
  }
  for (int i = 1; i <= n; i++) {
    dif[i] = calc(l[i], r[i], l[i + 1], r[i + 1]);
    sam[i] = (1 - dif[i]) % MOD;
    (ans += dif[i]) %= MOD;
  }
  ans = ans * ans % MOD;
  for (int i = 1; i < n; i++) {
    (ans -= 2 * dif[i] * dif[i + 1]) %= MOD;
    int L = max(max(l[i], l[i + 1]), l[i + 2]),
        R = min(min(l[i], l[i + 1]), l[i + 2]);
    (ans +=
     2 *
     (1 - sam[i] - sam[i + 1] +
      max(0, R - L + 1) *
          power(cnt[i] % MOD * cnt[i + 1] % MOD * cnt[i + 2] % MOD, MOD - 2)) %
     MOD) %= MOD;
  }
  for (int i = 1; i <= n; i++) {
    (ans -= dif[i] * dif[i]) %= MOD;
    (ans += dif[i]) %= MOD;
  }
  printf("%lld\n", (ans + MOD) % MOD);
  return 0;
}
