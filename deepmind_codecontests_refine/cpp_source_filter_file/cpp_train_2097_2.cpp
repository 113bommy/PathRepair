#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
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
const int N = 10010;
long long res[N], base[N], _c[N], _md[N];
vector<long long> Md;
void mul(long long *a, long long *b, int k) {
  for (int i = 0; i < k + k; i++) _c[i] = 0;
  for (int i = 0; i < k; i++)
    if (a[i])
      for (int j = 0; j < k; j++) _c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
  for (int i = k + k - 1; i >= k; i--)
    if (_c[i])
      for (int j = 0; j < ((int)(Md).size()); j++)
        _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % mod;
  for (int i = 0; i < k; i++) a[i] = _c[i];
}
int solve(long long n, vector<int> a, vector<int> b) {
  long long ans = 0, pnt = 0;
  int k = ((int)(a).size());
  assert(((int)(a).size()) == ((int)(b).size()));
  for (int i = 0; i < k; i++) _md[k - 1 - i] = -a[i];
  _md[k] = 1;
  Md.clear();
  for (int i = 0; i < k; i++)
    if (_md[i] != 0) Md.push_back(i);
  for (int i = 0; i < k; i++) res[i] = base[i] = 0;
  res[0] = 1;
  while ((1ll << pnt) <= n) pnt++;
  for (int p = pnt; p >= 0; p--) {
    mul(res, res, k);
    if ((n >> p) & 1) {
      for (int i = k - 1; i >= 0; i--) res[i + 1] = res[i];
      res[0] = 0;
      for (int j = 0; j < ((int)(Md).size()); j++)
        res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % mod;
    }
  }
  for (int i = 0; i < k; i++) ans = (ans + res[i] * b[i]) % mod;
  if (ans < 0) ans += mod;
  return ans;
}
vector<int> BM(vector<int> s) {
  vector<int> C(1, 1), B(1, 1);
  int L = 0, m = 1, b = 1;
  for (int n = 0; n < ((int)(s).size()); n++) {
    long long d = 0;
    for (int i = 0; i < L + 1; i++) d = (d + (long long)C[i] * s[n - i]) % mod;
    if (d == 0)
      ++m;
    else if (2 * L <= n) {
      vector<int> T = C;
      long long c = mod - d * powmod(b, mod - 2) % mod;
      while (((int)(C).size()) < ((int)(B).size()) + m) C.push_back(0);
      for (int i = 0; i < ((int)(B).size()); i++)
        C[i + m] = (C[i + m] + c * B[i]) % mod;
      L = n + 1 - L;
      B = T;
      b = d;
      m = 1;
    } else {
      long long c = mod - d * powmod(b, mod - 2) % mod;
      while (((int)(C).size()) < ((int)(B).size()) + m) C.push_back(0);
      for (int i = 0; i < ((int)(B).size()); i++)
        C[i + m] = (C[i + m] + c * B[i]) % mod;
      ++m;
    }
  }
  return C;
}
int gao(vector<int> a, long long n) {
  vector<int> c = BM(a);
  c.erase(c.begin());
  for (int i = 0; i < ((int)(c).size()); i++) c[i] = (mod - c[i]) % mod;
  return solve(n, c, vector<int>(a.begin(), a.begin() + ((int)(c).size())));
}
};  // namespace linear_seq
long long f[205];
int main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= m; i++) f[i] = 1;
  for (int i = m; i <= 200; i++) f[i] = (f[i - 1] + f[i - m]) % mod;
  vector<int> v;
  n++;
  for (int i = 1; i <= 10; i++) v.push_back(f[i]);
  printf("%lld\n", linear_seq::gao(v, n - 1) % mod);
}
