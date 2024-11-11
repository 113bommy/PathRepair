#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 998244353;
inline int mul(int a, int b) { return (long long)a * b % mod; }
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int qpow(int x, int n) {
  int res = 1;
  while (n > 0) {
    if (n & 1) res = mul(res, x);
    x = mul(x, x);
    n >>= 1;
  }
  return res;
}
int n, k, h[N], f[N], invf[N];
int C(int n, int m) { return mul(mul(f[n], invf[m]), invf[n - m]); }
int main() {
  f[0] = invf[0] = 1;
  for (int i = (1); i < (N); i++)
    f[i] = mul(f[i - 1], i), invf[i] = qpow(f[i], mod - 2);
  cin >> n >> k;
  for (int i = (0); i < (n); i++) cin >> h[i];
  if (k == 1) {
    cout << 1;
    return 0;
  }
  int cnt = 0;
  for (int i = (0); i < (n); i++)
    if (h[i] != h[(i + 1) % n]) cnt++;
  int ans = 0, inv = qpow(2, mod - 2);
  for (int i = 1; i <= cnt; i++) {
    int now = mul(C(cnt, i), qpow(k - 2, cnt - i)), ss = 0;
    if (i % 2 == 0) {
      ss = mul(inv, add(qpow(2, i), mod - C(i, i / 2)));
    } else
      ss = qpow(2, i - 1);
    now = mul(now, ss);
    ans = add(ans, now);
  }
  ans = mul(ans, qpow(k, n - cnt));
  cout << ans << "\n";
  return 0;
}
