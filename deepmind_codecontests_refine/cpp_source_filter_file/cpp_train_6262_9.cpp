#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int N = 5000 + 5;
vector<long long> fac(N);
vector<long long> ifac(N);
void init() {
  fac[0] = 1;
  ifac[0] = 1;
  ifac[1] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i - 1] * i;
  }
  for (int i = 2; i < N; ++i) {
    ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
  }
  for (int i = 1; i < N; ++i) {
    ifac[i] = ifac[i] * ifac[i - 1] % MOD;
  }
}
long long dp[N][N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cot(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cot[a[i]]++;
  }
  vector<int> b;
  for (int i = 1; i <= n; ++i) {
    if (cot[i]) {
      b.push_back(cot[i]);
    }
  }
  int m = b.size();
  dp[0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * b[i - 1] % MOD) % MOD;
    }
  }
  auto Comb = [](int x) -> long long { return 1ll * x * (x - 1) / 2 % MOD; };
  long long ans = 0;
  for (int i = 1; i <= m; ++i)
    if (b[i - 1] >= 2) {
      long long add = 0;
      for (int j = 0; j < i; ++j) {
        add = (add + dp[i - 1][j] * fac[n - j - 2] % MOD) % MOD;
      }
      ans = (ans + add * Comb(b[i - 1]) % MOD * 2) % MOD;
    }
  cout << ans * ifac[n] % MOD << endl;
  return 0;
}
