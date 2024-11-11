#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool checkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool checkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int MAXN = 1000 + 10;
const int MAXK = 1000000 + 10;
const int MOD = 1000000000 + 7;
int N, M, K;
long long fact[MAXK];
long long sl[1010][1010];
void init() {
  fact[0] = 1;
  for (int i = 1; i < MAXK; i++) {
    fact[i] = (fact[i - 1] * (long long)i) % MOD;
  }
  memset(sl, 0, sizeof(sl));
  for (int i = 1; i < MAXN; i++) sl[i][i] = sl[i][1] = 1;
  for (int i = 2; i < MAXN; i++) {
    for (int j = 2; j < i; j++) {
      sl[i][j] = sl[i - 1][j - 1] + (long long)j * sl[i - 1][j];
      sl[i][j] %= MOD;
    }
  }
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) return x = 1, y = 0, a;
  long long ret = exgcd(b, a % b, x, y), tmp = x;
  x = y;
  y = tmp - (a / b) * y;
  return ret;
}
long long comb(const long long &n, const long long &m) {
  if (n < 0) return 0;
  if (m < 0 || m > n) return 0;
  long long res = fact[n];
  long long tmp_1, tmp;
  exgcd(fact[m], MOD, tmp_1, tmp);
  tmp_1 = (tmp_1 % MOD + MOD) % MOD;
  res = (res * tmp_1) % MOD;
  exgcd(fact[n - m], MOD, tmp_1, tmp);
  tmp_1 = (tmp_1 % MOD + MOD) % MOD;
  res = (res * tmp_1) % MOD;
  return res;
}
long long po(const long long &a, int b) {
  long long rst = 1;
  long long base = a;
  while (b > 0) {
    if (b & 1) {
      rst *= base;
      rst %= MOD;
    }
    b >>= 1;
    base *= base;
    base %= MOD;
  }
  return rst;
}
void solve() {
  long long ans = 0;
  if (M == 1) {
    for (int i = 1; i <= N; i++) {
      long long tmp = comb(K, i) * sl[N][i];
      tmp %= MOD;
      tmp *= fact[i];
      tmp %= MOD;
      ans += tmp;
      ans %= MOD;
    }
    printf("%I64d\n", ans);
    return;
  }
  for (int i = 1; i <= N && i <= K; i++) {
    for (int j = 0; j <= i; j++) {
      long long tmp = comb(K, i) * sl[N][i];
      tmp %= MOD;
      tmp *= fact[i];
      tmp %= MOD;
      tmp *= po(j, N * M - 2 * N);
      tmp %= MOD;
      tmp *= comb(i, j);
      tmp %= MOD;
      tmp *= comb(K - i, i - j);
      tmp %= MOD;
      tmp *= sl[N][i];
      tmp %= MOD;
      tmp *= fact[i];
      tmp %= MOD;
      ans += tmp;
      ans %= MOD;
    }
  }
  printf("%I64d\n", ans);
  return;
}
int main() {
  init();
  while (scanf("%d%d%d", &N, &M, &K) != EOF) {
    solve();
  }
  return 0;
}
