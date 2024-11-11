#include <bits/stdc++.h>
const int N = 1000005;
const long long inf = 9e18;
long long n, l, r, k, L, R, ans;
template <class I>
inline I Max(I p, I q) {
  return p > q ? p : q;
}
template <class I>
inline I Min(I p, I q) {
  return p < q ? p : q;
}
inline void solve(const long long K) {
  const long long k = ::k - K;
  if (n < k / n) {
    if (k < L) return;
    for (register long long i = n; ~i; --i) {
      const long long x = R + i;
      const long long b = Max((k - L - Min(b, L - 1) + x - 1) / x, 0ll),
                      a = k - L - b * x;
      if (i >= K && a >= 0 && a <= i && a < L && i <= R - L + 1 + a)
        ans = Max(ans, i);
    }
    return;
  }
  for (register long long i = 0; i * R <= k; ++i) {
    const long long w = k - i * R - L;
    if (w < 0 || (i == 0 && w > L - 1)) continue;
    const long long b = Min(R, Min((w + R - L + 1) / (i + 1), i ? w / i : inf)),
                    a = w - b * i;
    if (b >= K && a >= 0 && a <= b && a < L && b <= R - L + 1 + a)
      ans = Max(ans, b);
  }
}
int main() {
  scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
  R = n;
  L = r - l + 1, L <= 0 ? L += n : 0, ans = -1;
  solve(0), solve(1), printf("%lld", ans);
  return 0;
}
