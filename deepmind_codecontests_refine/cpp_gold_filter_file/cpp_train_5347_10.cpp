#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long N, M, K;
long long stup[110][110];
long long fakt[110];
long long dp[110][110 * 110];
long long bio[110][110 * 110];
long long pot(long long x, long long n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  long long tmp = pot(x, n / 2);
  tmp %= MOD;
  tmp *= tmp;
  tmp %= MOD;
  if (n % 2 == 1) tmp *= x;
  tmp %= MOD;
  return tmp;
}
long long rek(long long tr, long long rest) {
  if (tr == N) {
    if (rest == 0) return 1;
    return 0;
  }
  long long &rez = dp[tr][rest];
  if (bio[tr][rest]) return rez;
  bio[tr][rest] = 1;
  rez = rek(tr + 1, rest);
  rez %= MOD;
  for (int i = 1; i <= min(rest, N); i++) {
    rez += stup[tr][i] * rek(tr + 1, rest - i);
    rez %= MOD;
  }
  return rez;
}
int main() {
  scanf("%I64d%I64d%I64d", &N, &M, &K);
  fakt[1] = 1;
  for (int i = 2; i < 110; i++) {
    fakt[i] = fakt[i - 1] * i;
    fakt[i] %= MOD;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N; j++) {
      long long baza = fakt[N] * pot((fakt[j] * fakt[N - j]) % MOD, MOD - 2);
      baza %= MOD;
      stup[i][j] = pot(baza, (M - i - 1) / N + 1);
      stup[i][j] %= MOD;
      if (stup[i][j] == 0) stup[i][j] = 1;
    }
  }
  printf("%I64d\n", rek(0, K) % MOD);
  return 0;
}
