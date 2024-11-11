#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
const int MOD = 998244353;
int arr[MAXN], dp[MAXN];
ll q_pow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    dp[i] = ((dp[i - 1] * 100) % MOD * q_pow(arr[i], MOD - 2)) % MOD + 1;
  }
  cout << dp[n] - 1 << '\n';
  return 0;
}
