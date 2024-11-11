#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 111;
int N;
long long M;
int K;
long long powmod(long long base, long long pow) {
  if (pow == 0) return 1;
  long long k = powmod(base, pow / 2);
  (k *= k) %= MOD;
  if (pow & 1) {
    (k *= base) %= MOD;
  }
  return k;
}
int cnts[MAXN];
long long dp[MAXN][MAXN * MAXN];
long long choose[MAXN];
long long powmods[MAXN][2];
long long getdp(int n, int k) {
  if (n == N) {
    if (k == 0)
      return 1;
    else
      return 0;
  }
  long long &ret = dp[n][k];
  if (ret) return ret - 1;
  for (int i = 0; i <= N; ++i) {
    if (i > k) break;
    long long nxt = getdp(n + 1, k - i);
    long long ways = powmods[i][cnts[n]];
    (ways *= nxt) %= MOD;
    (ret += ways) %= MOD;
  }
  return ret++;
}
int main() {
  cin >> N >> M >> K;
  choose[0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = i; j >= 0; --j) {
      (choose[j + 1] += choose[j]) %= MOD;
    }
  }
  long long div = M / N;
  int rem = M % N;
  for (int i = 0; i < N; ++i) {
    if (i < rem) cnts[i] = 1;
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j <= N; ++j) {
      powmods[j][i] = powmod(choose[j], div + i);
    }
  }
  long long ans = getdp(0, K);
  cout << ans << "\n";
  return 0;
}
