#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int mod = 998244353;
int n, fact[maxn], arr[maxn], dp[maxn], ans;
int add(int a, int b) {
  int c = a + b;
  if (c >= mod)
    c -= mod;
  else if (c < 0)
    c += mod;
  return c;
}
int mul(int a, int b) {
  int c = 1LL * a * b % mod;
  return c;
}
int pwr(int a, int b) {
  if (!b) return 1;
  int res = pwr(a, b >> 1);
  res = mul(res, res);
  if (b & 1) res = mul(res, a);
  return res;
}
int inv(int p) { return pwr(p, mod - 2); }
int C(int n, int k) {
  int ans = fact[n];
  ans = mul(ans, inv(fact[k]));
  ans = mul(ans, inv(fact[n - k]));
  return ans;
}
int main() {
  cin >> n;
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (i - j + 1 < arr[j] + 1 || arr[j] <= 0) continue;
      ans = add(ans, C(i - j - 1, arr[j] - 1) * (dp[j - 1] + 1));
    }
    dp[i] = ans;
  }
  cout << ans;
  return 0;
}
