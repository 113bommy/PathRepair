#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353, N = 500005, g = 3, ig = 332748118;
int num[N], rev[N], lim, ilim, len, n;
long long A[N], B[N], fac[N];
long long qpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % MOD;
    x = x * x % MOD, y >>= 1;
  }
  return ans;
}
void NTT(long long* A, int op) {
  for (int i = 0; i < lim; i++)
    if (i < rev[i]) swap(A[i], A[rev[i]]);
  for (int i = 1; i < lim; i <<= 1) {
    long long wn = qpow(~op ? g : ig, (MOD - 1) / (i << 1));
    for (int p = i << 1, j = 0; j < lim; j += p) {
      long long w = 1;
      for (int k = 0; k < i; k++, w = w * wn % MOD) {
        long long u = A[j + k], t = w * A[i + j + k] % MOD;
        A[j + k] = (u + t) % MOD, A[i + j + k] = (u - t + MOD) % MOD;
      }
    }
  }
  if (!~op)
    for (int i = 0; i < lim; i++) {
      A[i] = A[i] * ilim % MOD;
    }
}
vector<long long> poly_mul(vector<long long> a, vector<long long> b) {
  int n = a.size() - 1, m = b.size() - 1, deg = n + m;
  for (lim = 1, len = 0; lim <= deg; lim <<= 1, len++)
    ;
  for (int i = 0; i < lim; i++)
    rev[i] = rev[i >> 1] >> 1 | (i & 1) << (len - 1);
  for (int i = 0; i < lim; i++) {
    A[i] = B[i] = 0;
    if (i <= n) A[i] = a[i];
    if (i <= m) B[i] = b[i];
  }
  ilim = qpow(lim, MOD - 2), NTT(A, 1), NTT(B, 1);
  for (int i = 0; i < lim; i++) A[i] = A[i] * B[i] % MOD;
  return NTT(A, -1), vector<long long>(A, A + 1 + deg);
}
vector<long long> cal(int l, int r) {
  if (l == r) return vector<long long>{1, num[l]};
  int m = (l + r) >> 1;
  return poly_mul(cal(l, m), cal(m + 1, r));
}
int main() {
  cin >> n;
  fac[0] = fac[1] = 1;
  for (int i = 2, u, v; i <= n; num[i]--, i++) {
    cin >> u >> v;
    num[u]++, num[v]++;
    fac[i] = i * fac[i - 1] % MOD;
  }
  vector<long long> F = cal(1, n);
  long long ans = 0, sgn = 1;
  for (int i = 0; i <= n && i < F.size(); i++, sgn *= -1) {
    ans = (ans + MOD + sgn * fac[n - i] * F[i] % MOD) % MOD;
  }
  cout << ans;
  return 0;
}
