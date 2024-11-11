#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long _, n;
namespace linear_seq {
const long long N = 10010;
long long res[N], base[N], _c[N], _md[N];
vector<long long> Md;
void mul(long long *a, long long *b, long long k) {
  for (long long i = 0; i < k + k; i++) _c[i] = 0;
  for (long long i = 0; i < k; i++)
    if (a[i])
      for (long long j = 0; j < k; j++)
        _c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
  for (long long i = k + k - 1; i >= k; i--)
    if (_c[i])
      for (long long j = 0; j < ((long long)(Md).size()); j++)
        _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % mod;
  for (long long i = 0; i < k; i++) a[i] = _c[i];
}
long long solve(long long n, vector<long long> a, vector<long long> b) {
  long long ans = 0, pnt = 0;
  long long k = ((long long)(a).size());
  assert(((long long)(a).size()) == ((long long)(b).size()));
  for (long long i = 0; i < k; i++) _md[k - 1 - i] = -a[i];
  _md[k] = 1;
  Md.clear();
  for (long long i = 0; i < k; i++)
    if (_md[i] != 0) Md.push_back(i);
  for (long long i = 0; i < k; i++) res[i] = base[i] = 0;
  res[0] = 1;
  while ((1ll << pnt) <= n) pnt++;
  for (long long p = pnt; p >= 0; p--) {
    mul(res, res, k);
    if ((n >> p) & 1) {
      for (long long i = k - 1; i >= 0; i--) res[i + 1] = res[i];
      res[0] = 0;
      for (long long j = 0; j < ((long long)(Md).size()); j++)
        res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % mod;
    }
  }
  for (long long i = 0; i < k; i++) ans = (ans + res[i] * b[i]) % mod;
  if (ans < 0) ans += mod;
  return ans;
}
vector<long long> BM(vector<long long> s) {
  vector<long long> C(1, 1), B(1, 1);
  long long L = 0, m = 1, b = 1;
  for (long long n = 0; n < ((long long)(s).size()); n++) {
    long long d = 0;
    for (long long i = 0; i < L + 1; i++)
      d = (d + (long long)C[i] * s[n - i]) % mod;
    if (d == 0)
      ++m;
    else if (2 * L <= n) {
      vector<long long> T = C;
      long long c = mod - d * powmod(b, mod - 2) % mod;
      while (((long long)(C).size()) < ((long long)(B).size()) + m)
        C.push_back(0);
      for (long long i = 0; i < ((long long)(B).size()); i++)
        C[i + m] = (C[i + m] + c * B[i]) % mod;
      L = n + 1 - L;
      B = T;
      b = d;
      m = 1;
    } else {
      long long c = mod - d * powmod(b, mod - 2) % mod;
      while (((long long)(C).size()) < ((long long)(B).size()) + m)
        C.push_back(0);
      for (long long i = 0; i < ((long long)(B).size()); i++)
        C[i + m] = (C[i + m] + c * B[i]) % mod;
      ++m;
    }
  }
  return C;
}
long long gao(vector<long long> a, long long n) {
  vector<long long> c = BM(a);
  c.erase(c.begin());
  for (long long i = 0; i < ((long long)(c).size()); i++)
    c[i] = (mod - c[i]) % mod;
  return solve(
      n, c, vector<long long>(a.begin(), a.begin() + ((long long)(c).size())));
}
};  // namespace linear_seq
int main() {
  long long f1 = 1, f2 = 2, sum = 1, n, k;
  cin >> n >> k;
  vector<long long> ve;
  ve.push_back(1);
  sum += powmod(2, k + 1);
  ve.push_back(sum % mod);
  for (int i = 3; i < 500; ++i) {
    long long f3 = (f1 + f2) % mod;
    sum = (sum + f3 * powmod(i, k)) % mod;
    ve.push_back(sum);
    f1 = f2;
    f2 = f3;
  }
  printf("%lld\n", linear_seq::gao(ve, n - 1));
  return 0;
}
