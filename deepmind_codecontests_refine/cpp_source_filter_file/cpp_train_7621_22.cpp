#include <bits/stdc++.h>
class Input {
 private:
  char buf[1000000], *p1, *p2;

 public:
  inline char getc() {
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin);
    return p1 == p2 ? EOF : *(p1++);
  }
  template <typename tp>
  inline Input &operator>>(tp &n) {
    n = 0;
    char c = getc();
    while (!isdigit(c)) c = getc();
    while (isdigit(c)) n = n * 10 + c - 48, c = getc();
    return (*this);
  }
} fin;
const int N = 1e2 + 5, mod = 998244353;
using namespace std;
int n, tot;
int l[N], r[N], o[N], inv[N], f[N][N];
inline void Plus(int &a, int b) { a += b - mod, a += (a >> 31) & mod; }
int qpow(long long b, int t) {
  long long ret = 1;
  for (; t; t >>= 1, b = b * b % mod)
    if (t & 1) ret = ret * b % mod;
  return ret;
}
int binom(int n, int m) {
  if (n < m) return 0;
  int ret = 1;
  for (int i = 1; i <= m; ++i)
    ret = 1ll * ret * (n - i + 1) % mod * inv[i] % mod;
  return ret;
}
int main() {
  fin >> n;
  inv[1] = 1;
  for (int i = 2; i <= n; ++i)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  long long sum = 1;
  for (int i = 1; i <= n; ++i)
    fin >> l[i] >> r[i], ++r[i], o[++tot] = l[i], o[++tot] = r[i],
                                 sum = sum * (r[i] - l[i]) % mod;
  sort(o + 1, o + tot + 1);
  tot = unique(o + 1, o + tot + 1) - o - 1;
  for (int i = 1; i <= tot; ++i)
    l[i] = lower_bound(o + 1, o + tot + 1, l[i]) - o,
    r[i] = lower_bound(o + 1, o + tot + 1, r[i]) - o;
  for (int i = 1; i <= tot; ++i) f[0][i] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = l[i]; j < r[i]; ++j) {
      int len = o[j + 1] - o[j];
      for (int k = i; k; --k) {
        if (l[k] > j || r[k] <= j) break;
        Plus(f[i][j],
             1ll * f[k - 1][j + 1] * binom(len + i - k, i - k + 1) % mod);
      }
    }
    for (int j = tot; j >= 1; --j) Plus(f[i][j], f[i][j + 1]);
  }
  cout << 1ll * f[n][1] * qpow(sum, mod - 2) % mod << endl;
  return 0;
}
