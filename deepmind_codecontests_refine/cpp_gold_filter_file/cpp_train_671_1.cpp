#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e5 + 10, MOD = 1e9 + 7;
int N, K;
int fact[NMAX], invfact[NMAX], sum[NMAX], nums[NMAX];
char number[NMAX];
int FastExpo(int base, int exp = MOD - 2) {
  int ret = 1;
  while (exp) {
    if (exp & 1) ret = (1LL * ret * base) % MOD;
    base = (1LL * base * base) % MOD;
    exp >>= 1;
  }
  return ret;
}
inline int C(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  return ((1LL * fact[n] * invfact[n - k]) % MOD * invfact[k]) % MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  int i, j;
  cin >> N >> K >> (number + 1);
  if (K == 0) {
    int res = 0;
    for (i = 1; i <= N; ++i) res = (1LL * res * 10 + number[i] - '0') % MOD;
    cout << res << '\n';
    return 0;
  }
  fact[0] = fact[1] = invfact[0] = invfact[1] = 1;
  for (i = 2; i < NMAX; ++i) {
    fact[i] = (1LL * fact[i - 1] * i) % MOD;
    invfact[i] = (1LL * invfact[i - 1] * FastExpo(i)) % MOD;
  }
  for (i = 2; i < N; ++i) sum[1] += number[i] -= '0';
  number[1] -= '0';
  number[N] -= '0';
  int current_sum = sum[1], last = 0;
  for (i = 2; i < N; ++i) {
    current_sum -= number[i];
    last = (1LL * FastExpo(10, i - 2) * number[N - i + 1] + last) % MOD;
    sum[i] = sum[i - 1] - last;
    if (sum[i] < 0) sum[i] += MOD;
    sum[i] = (1LL * sum[i] * 10 + current_sum) % MOD;
  }
  int result = 0;
  for (i = 1; i < N; ++i)
    result = (result + 1LL * sum[i] * C(N - i - 2, K - 2)) % MOD;
  last = 0;
  for (i = 1; i <= N; ++i) {
    last = (1LL * last * 10 + number[i]) % MOD;
    result = (result + 1LL * last * C(N - i - 1, K - 1)) % MOD;
  }
  last = 0;
  for (i = 1; i <= N; ++i) {
    last = (1LL * FastExpo(10, i - 1) * number[N - i + 1] + last) % MOD;
    result = (result + 1LL * last * C(N - i - 1, K - 1)) % MOD;
  }
  cout << result << '\n';
  return 0;
}
