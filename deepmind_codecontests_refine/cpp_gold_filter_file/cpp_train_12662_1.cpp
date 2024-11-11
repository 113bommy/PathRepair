#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const long long INF = 1e9 + 10;
const int MOD = 1e9 + 7;
int n;
long long dp[2][1 << 20];
int main() {
  int fac[MAXN], f0[75], f1[75], cnt[75];
  int a[MAXN], b[75], prime[22];
  bool isprime[2000];
  memset(cnt, 0, sizeof(cnt));
  memset(b, 0, sizeof(b));
  memset(isprime, 0, sizeof(isprime));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  isprime[1] = 1;
  int t = 0;
  for (int i = 2; i < 75; i++) {
    if (!isprime[i]) {
      prime[t++] = i;
      for (int j = i + i; j < 75; j += i) isprime[j] = 1;
    }
  }
  for (int i = 2; i < 75; i++) {
    int m = i;
    int num;
    for (int j = 0; j < t; j++) {
      num = 0;
      while (m % prime[j] == 0) {
        m /= prime[j];
        num++;
      }
      if (num & 1) b[i] ^= (1 << j);
    }
  }
  fac[0] = 1;
  for (int i = 1; i < MAXN; i++) fac[i] = fac[i - 1] * 2 % MOD;
  for (int i = 1; i < 75; i++) {
    if (cnt[i] == 0) {
      f0[i] = 1;
      f1[i] = 0;
    } else
      f1[i] = f0[i] = fac[cnt[i] - 1];
  }
  dp[0][0] = 1;
  for (int i = 1; i <= 70; i++) {
    int p = i % 2;
    memset(dp[p], 0, sizeof(dp[p]));
    for (int j = 0; j < (1 << 20); j++) {
      dp[p][j] += dp[1 - p][j] * f0[i];
      dp[p][j] %= MOD;
      dp[p][j ^ b[i]] += dp[1 - p][j] * f1[i];
      dp[p][j ^ b[i]] %= MOD;
    }
  }
  cout << dp[0][0] - 1 << endl;
}
