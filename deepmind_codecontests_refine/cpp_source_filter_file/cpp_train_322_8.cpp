#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T& t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "URDL";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 998244353) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 998244353) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
int fac[5005], inv[5005];
void initfac(int n) {
  fac[0] = inv[0] = 1;
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    fac[i] = (long long)fac[i - 1] * i % 998244353;
    inv[i] = fastPow(fac[i], 998244353 - 2);
  }
}
int C(int n, int m) {
  if (m < 0) return 0;
  if (n < m) return 0;
  return (long long)fac[n] * inv[m] % 998244353 * inv[n - m] % 998244353;
}
int cal(int n, int m, int lim) {
  if (m == 0) {
    return n == 0;
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    int z = (long long)C(m, i) * C(n - i * lim + m - 1, m - 1) % 998244353;
    if (i % 2 == 0)
      addmod(ans, z);
    else
      addmod(ans, 998244353 - z);
  }
  return ans;
}
int dp[5005];
void fmain(int tid) {
  int p, s, r;
  cin >> p >> s >> r;
  initfac(5005 - 1);
  for (int x = r; x <= s; x++) {
    for (int i = 1; x * i <= s && i <= p; i++) {
      int z = (long long)cal(s - i * x, p - i, x) * C(p - 1, i - 1) % 998244353;
      addmod(dp[i], z);
    }
  }
  int all = C(s - r + p - 1, p - 1), ans = 0;
  all = fastPow(all, 998244353 - 2);
  for (int(i) = 1; (i) <= (int)(p); (i)++) {
    addmod(ans, (long long)dp[i] * all % 998244353 * fastPow(i, 998244353 - 2) %
                    998244353);
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
