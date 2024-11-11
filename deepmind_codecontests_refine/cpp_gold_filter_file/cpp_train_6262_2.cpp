#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
struct Mod {
  const long long M;
  Mod(long long M) : M(M) {}
  long long qadd(long long a, long long b) const {
    return a += b, a < M ? a : a - M;
  }
  long long add(long long a, long long b) const { return qadd((a + b) % M, M); }
  long long mul(long long a, long long b) const { return add(a * b, 0); }
};
struct Factorial : Mod {
  vector<long long> fac, ifac;
  Factorial(int N, long long M) : fac(N, 1), ifac(N, 1), Mod(M) {
    for (int i = 2; i < N; ++i)
      fac[i] = mul(fac[i - 1], i), ifac[i] = mul(M - M / i, ifac[M % i]);
    for (int i = 2; i < N; ++i) ifac[i] = mul(ifac[i], ifac[i - 1]);
  }
} f(N, 998244353);
int n, ans, cnt[N], dp[N];
int main() {
  scanf("%d", &n);
  for (int i = 0, t; i < n; ++i) scanf("%d", &t), ++cnt[t];
  for (int i = dp[0] = 1, tot = 0; i <= n; ++i)
    if (cnt[i])
      for (int j = tot++, t = f.mul(f.mul(cnt[i], cnt[i] - 1), f.ifac[n]); ~j;
           --j)
        ans = f.qadd(ans, f.mul(f.mul(t, f.fac[n - j - 2]), dp[j])),
        dp[j + 1] = f.qadd(dp[j + 1], f.mul(cnt[i], dp[j]));
  printf("%d", ans);
}
