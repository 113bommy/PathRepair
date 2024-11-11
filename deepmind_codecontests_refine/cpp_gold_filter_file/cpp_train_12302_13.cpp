#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int l[maxn], r[maxn];
int e[maxn], sum[maxn];
int add(int a, int b) { return a + b < mod ? a + b : a + b - mod; }
int sub(int a, int b) { return a < b ? a - b + mod : a - b; }
int mul(int a, int b) { return 1LL * a * b % mod; }
template <typename... T>
int mul(int a, int b, T... c) {
  return mul(mul(a, b), c...);
}
int fpow(int x, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = mul(res, x);
    x = mul(x, x);
    n >>= 1;
  }
  return res;
}
int inv(int x) { return fpow(x, mod - 2); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> l[i];
  for (int i = 1; i <= n; ++i) cin >> r[i], ++r[i];
  if (n == 1) return cout << 1 << endl, 0;
  e[1] = 0;
  for (int i = 2; i <= n; ++i) {
    e[i] = min(r[i], r[i - 1]) - max(l[i], l[i - 1]);
    if (e[i] <= 0)
      e[i] = 0;
    else
      e[i] = mul(e[i], inv(r[i] - l[i]), inv(r[i - 1] - l[i - 1]));
  }
  int ans = 0;
  for (int i = n; i >= 1; --i) {
    sum[i] = add(sum[i + 1], sub(1, e[i]));
    ans = add(ans, sub(1, e[i]));
    ans = add(ans, mul(2, sub(1, e[i]), sum[i + 2]));
    if (i > 2) {
      int tmp =
          min({r[i], r[i - 1], r[i - 2]}) - max({l[i], l[i - 1], l[i - 2]});
      if (tmp <= 0) tmp = 0;
      tmp = mul(tmp, inv(r[i] - l[i]), inv(r[i - 1] - l[i - 1]),
                inv(r[i - 2] - l[i - 2]));
      ans = add(ans, mul(2, add(sub(sub(1, e[i]), e[i - 1]), tmp)));
    }
  }
  ans = add(ans, mul(2, sub(1, e[2])));
  cout << ans << endl;
  return 0;
}
