#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
int A[300003], pref[300003];
int sum(int a, int b) { return (pref[b] - pref[a - 1]) % MOD; }
int pwr(int a, int b) {
  if (b == 0)
    return 1;
  else if (b == 2)
    return (1LL * a * a) % MOD;
  else if (b & 1)
    return (1LL * pwr(a, b - 1) * a) % MOD;
  else
    return pwr(pwr(a, b / 2), 2);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  sort(A + 1, A + 1 + n);
  for (int i = 1; i <= n; i++) pref[i] = (pref[i - 1] + A[i]) % MOD;
  for (int k = 1; k <= n; k++) {
    int sz = n - k;
    int res = 0;
    int hit = 1;
    for (int j = sz; j - k + 1 > 0; j -= k) {
      res += (1LL * hit * sum(j - k + 1, j)) % MOD;
      res %= MOD;
      hit++;
    }
    if (sz % k) {
      res += (1LL * hit * sum(1, 1 + (sz % k) - 1)) % MOD;
      res %= MOD;
    }
    res = (res % MOD + MOD) % MOD;
    res = (1LL * res * pwr(n, MOD - 2)) % MOD;
    printf("%d%c", res, (k == n) ? '\n' : ' ');
  }
}
