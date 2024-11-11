#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2000 + 5, MAX_H = 200 * 1000 + 5, MOD = 1e9 + 7;
int h, w, n, fac[MAX_H], inv[MAX_H], dp[MAX_N];
pair<int, int> a[MAX_N];
void read_input() {
  cin >> h >> w >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i].first >> a[i].second, a[i].first--, a[i].second--;
  sort(a, a + n + 1);
  a[n + 1].first = h - 1;
  a[n + 1].second = w - 1;
}
int pw(int b, int p) {
  int res = 1;
  for (; p; p >>= 1, b = 1LL * b * b % MOD)
    if (p & 1) res = 1LL * res * b % MOD;
  return res;
}
void prep() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < MAX_H; i++) {
    fac[i] = 1LL * fac[i - 1] * i % MOD;
    inv[i] = pw(fac[i], MOD - 2);
  }
}
int nCr(int n, int r) { return 1LL * fac[n] * inv[r] % MOD * inv[n - r] % MOD; }
void solve() {
  dp[0] = 1;
  for (int i = 1; i <= n + 1; i++) {
    dp[i] = nCr(a[i].first + a[i].second, a[i].first);
    for (int j = 1; j < i; j++)
      if (a[j].first <= a[i].first && a[j].second <= a[i].second)
        dp[i] = (dp[i] -
                 1LL * dp[j] *
                     nCr(a[i].first + a[i].second - a[j].first - a[j].second,
                         a[i].first - a[j].first)) %
                MOD;
  }
  cout << (dp[n + 1] + MOD) % MOD;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  read_input();
  prep();
  solve();
}
