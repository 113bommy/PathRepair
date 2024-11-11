#include <bits/stdc++.h>
using namespace std;
namespace IO {
char in[1 << 24];
char const *o;
void init_in() {
  o = in;
  in[fread(in, 1, sizeof(in) - 4, stdin)] = 0;
}
int rd() {
  unsigned u = 0, s = 0;
  while (*o && *o <= 32) ++o;
  if (*o == '-')
    s = ~s, ++o;
  else if (*o == '+')
    ++o;
  while (*o >= '0' && *o <= '9') u = (u << 3) + (u << 1) + (*o++ - '0');
  return static_cast<int>((u ^ s) + !!s);
}
char *rdstr(char *s) {
  while (*o && *o <= 32) ++o;
  while (*o > 32) *s++ = *o++;
  return s;
}
}  // namespace IO
template <typename T>
void chkmax(T &a, const T &b) {
  a = max(a, b);
}
template <typename T>
void chkmin(T &a, const T &b) {
  a = min(a, b);
}
pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
using IO::rd;
const int N = 14, S = 1 << N;
int a[N];
int n;
const long long mod = 1e9 + 7;
long long b[N][N];
long long h[N][S], pr[S];
inline void reduce(long long &x) {
  if (x >= mod) x -= mod;
}
inline long long g(int s, int t) {
  long long ret = 1;
  for (int i = 0; i < n; ++i) {
    if (s & (1 << i)) ret = ret * h[i][t] % mod;
  }
  return ret;
}
int Q_pow(long long x, int y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret;
}
inline int inv(int x) { return Q_pow(x, mod - 2); }
void solve() {
  n = rd();
  int m = 1 << n;
  for (int i = 0; i < n; ++i) a[i] = rd();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j) {
      long long x = inv(a[i] + a[j]);
      b[i][j] = a[i] * x % mod;
      b[j][i] = a[j] * x % mod;
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      h[i][j] = 1;
      for (int k = 0; k < n; ++k) {
        if (k != i && j & (1 << k)) h[i][j] = h[i][j] * b[i][k] % mod;
      }
    }
  int mask = m - 1;
  for (int i = 1; i < m; ++i) {
    pr[i] = 1;
    for (int j = (i - 1) & i; j; j = (j - 1) & i) {
      reduce(pr[i] += mod - (g(j, i ^ j) * pr[j] % mod));
    }
  }
  long long ans = 0;
  for (int i = 1; i < m; ++i) {
    ans += pr[i] * g(i, mask ^ i) % mod * __builtin_popcount(i) % mod;
  }
  cout << ans % mod << '\n';
}
int main() {
  IO::init_in();
  solve();
  return 0;
}
