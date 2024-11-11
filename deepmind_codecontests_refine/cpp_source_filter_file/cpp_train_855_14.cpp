#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const int G = 3;
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
namespace NTT {
long long wn[maxn << 2], rev[maxn << 2];
int init(int n_) {
  int step = 0;
  int n = 1;
  for (; n < n_; n <<= 1) ++step;
  for (int i = (1); i <= (n - 1); i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (step - 1));
  int g = qpow(G, (mod - 1) / n);
  wn[0] = 1;
  for (int i = 1; i <= n; ++i) wn[i] = wn[i - 1] * g % mod;
  return n;
}
void NTT(long long a[], int n, int f) {
  for (int i = (0); i <= (n - 1); i++)
    if (i < rev[i]) std::swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += (k << 1)) {
      int t = n / (k << 1);
      for (int j = (0); j <= (k - 1); j++) {
        long long w = f == 1 ? wn[t * j] : wn[n - t * j];
        long long x = a[i + j];
        long long y = a[i + j + k] * w % mod;
        a[i + j] = (x + y) % mod;
        a[i + j + k] = (x - y + mod) % mod;
      }
    }
  }
  if (f == -1) {
    long long ninv = qpow(n, mod - 2);
    for (int i = (0); i <= (n - 1); i++) a[i] = a[i] * ninv % mod;
  }
}
void mul(long long a[], long long b[], int len) {
  NTT(a, len, 1);
  NTT(b, len, 1);
  for (int i = (0); i <= (len - 1); i++) a[i] = a[i] * b[i] % mod;
  NTT(a, len, -1);
}
}  // namespace NTT
long long jc[maxn], inv[maxn];
void cinit(int n) {
  jc[0] = inv[0] = 1;
  for (int i = (1); i <= (n); i++) jc[i] = jc[i - 1] * i % mod;
  inv[n] = qpow(jc[n], mod - 2);
  for (int i = (n - 1); i >= (1); i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
long long C(int n, int m) { return jc[n] * inv[m] % mod * inv[n - m] % mod; }
long long sb[maxn << 1], sr[maxn << 1];
void stirling_second(int n) {
  int len = NTT::init(2 * n + 2);
  for (int i = 1; i <= n; i++) sr[i] = qpow(i, n) * inv[i] % mod;
  for (int i = 0; i <= n; i++) {
    if (i & 1)
      sb[i] = mod - inv[i];
    else
      sb[i] = inv[i];
  }
  NTT::NTT(sr, len, 1);
  NTT::NTT(sb, len, 1);
  for (int i = 0; i < len; i++) sr[i] = sr[i] * sb[i] % mod;
  NTT::NTT(sr, len, -1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  cinit(n);
  if (k > n - 1) {
    cout << 0 << '\n';
    return 0;
  }
  if (k == 0) {
    cout << jc[n] << '\n';
    return 0;
  }
  long long num = n - k;
  long long ans = C(n, num);
  stirling_second(n);
  ans = ans * sr[num] % mod;
  ans = ans * jc[num] % mod;
  ans = ans * 2 % mod;
  cout << ans << '\n';
  return 0;
}
