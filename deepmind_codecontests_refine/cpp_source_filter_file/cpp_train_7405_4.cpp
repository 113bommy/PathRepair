#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
string s;
long long N;
const long long MAX_N = 1e5, ALP = 'z' - 'a' + 1;
long long cnt[ALP * 2];
long long ctoi(char c) {
  if ('A' <= c && c <= 'Z') {
    return c - 'A';
  } else {
    return ALP + c - 'a';
  }
}
long long fact[MAX_N + 1], ifact[MAX_N + 1];
long long minv(long long n) {
  long long m = MOD - 2;
  long long ret = 1;
  while (m) {
    if (m & 1) {
      ret *= n;
      ret %= MOD;
    }
    n *= n;
    n %= MOD;
    m >>= 1;
  }
  return ret;
}
long long cmb(long long n, long long m) {
  return fact[n] * ifact[m] % MOD * ifact[n - m] % MOD;
}
long long dp[MAX_N + 1];
long long ans[ALP * 2][ALP * 2];
void add(long long &x, long long y) {
  x += y;
  if (x >= MOD) {
    x -= MOD;
  }
}
void sub(long long &x, long long y) {
  x -= y;
  if (x < 0) {
    x += MOD;
  }
}
int main() {
  cin >> s;
  fact[0] = 1;
  N = (long long)s.size();
  for (long long i = (0); i < (N); i++) {
    fact[i + 1] = (i + 1) * fact[i] % MOD;
  }
  ifact[N] = minv(fact[N]);
  for (long long i = N - 1; i >= 0; i--) {
    ifact[i] = (i + 1) * ifact[i + 1] % MOD;
  }
  long long acif = 1;
  for (auto c : s) {
    cnt[ctoi(c)]++;
  }
  for (long long i = (0); i < (ALP * 2); i++) {
    acif *= ifact[cnt[i]];
    acif %= MOD;
  }
  dp[0] = 1;
  for (long long c = (0); c < (ALP * 2); c++) {
    if (cnt[c] == 0) continue;
    for (long long i = N; i >= cnt[c]; i--) {
      add(dp[i], dp[i - cnt[c]]);
    }
  }
  for (long long i = (0); i < (ALP * 2); i++) {
    ans[i][i] = dp[N / 2];
  }
  for (long long i = (0); i < (ALP * 2); i++) {
    if (cnt[i] == 0) continue;
    for (long long c = (cnt[i]); c < (N + 1); c++) {
      sub(dp[c], dp[c - cnt[i]]);
    }
    for (long long j = (i + 1); j < (ALP * 2); j++) {
      if (cnt[j] == 0) continue;
      for (long long c = (cnt[j]); c < (N + 1); c++) {
        sub(dp[c], dp[c - cnt[j]]);
      }
      ans[i][j] = ans[j][i] = dp[N / 2] * 2 % MOD;
      for (long long c = N; c >= cnt[j]; c--) {
        add(dp[c], dp[c - cnt[j]]);
      }
    }
    for (long long c = N; c >= cnt[i]; c--) {
      add(dp[c], dp[c - cnt[i]]);
    }
  }
  long long q;
  cin >> q;
  long long w = fact[N / 2] * fact[N / 2] % MOD * acif % MOD;
  for (long long i = (0); i < (q); i++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << ans[ctoi(s[x])][ctoi(s[y])] * w << endl;
  }
}
