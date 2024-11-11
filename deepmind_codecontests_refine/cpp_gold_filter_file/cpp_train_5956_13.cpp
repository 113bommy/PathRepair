#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int add(int a, int b) { return a + b - mod * (a + b >= mod); }
int mul(int a, int b) { return int(1ll * a * b % mod); }
int power(int a, int x) {
  if (x == 0) {
    return 1;
  }
  return mul(power(mul(a, a), x >> 1), (x & 1 ? a : 1));
}
int divide(int a, int b) { return mul(a, power(b, mod - 2)); }
int sub(int a, int b) { return a - b + mod * (a < b); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  int t = 0;
  for (int i = 0; i < n; ++i) {
    if (h[i] != h[(i + 1) % n]) {
      ++t;
    }
  }
  if (t == 0) {
    cout << 0;
    return 0;
  }
  vector<int> f(n + 1), invf(n + 1);
  f[0] = invf[0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = mul(f[i - 1], i);
    invf[i] = divide(1, f[i]);
  }
  auto C = [&](int n, int k) { return mul(f[n], mul(invf[k], invf[n - k])); };
  int ans = 0;
  for (int i = 1; i <= t; ++i) {
    int cur = C(t, i);
    if (i & 1) {
      cur = mul(cur, power(2, i - 1));
    } else {
      cur = divide(mul(cur, sub(power(2, i), C(i, i / 2))), 2);
    }
    cur = mul(cur, power(k - 2, t - i));
    ans = add(ans, cur);
  }
  ans = mul(ans, power(k, n - t));
  cout << ans;
  return 0;
}
