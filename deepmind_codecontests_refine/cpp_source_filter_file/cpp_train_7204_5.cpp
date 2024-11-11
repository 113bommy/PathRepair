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
string direc = "URDL";
const long long MOD2 = (long long)998244353 * (long long)998244353;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 998244353) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
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
long long a[1035][1035], b[1035][1035];
int x[1035], y[1035];
void fmain(int tid) {
  scanf("%d", &k);
  n = 1 << k;
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(n); (j)++) scanf("%lld", &a[i][j]);
  scanf("%d", &m);
  for (int(i) = 0; (i) < (int)(m); (i)++) scanf("%d%d", x + i, y + i);
  for (int i = m - 1; i >= 0; i--) {
    x[i] -= x[0];
    y[i] -= y[0];
  }
  for (int(t) = 0; (t) < (int)(k); (t)++) {
    for (int(i) = 0; (i) < (int)(n); (i)++)
      for (int(j) = 0; (j) < (int)(n); (j)++) b[i][j] = 0;
    for (int(i) = 0; (i) < (int)(n); (i)++)
      for (int(j) = 0; (j) < (int)(n); (j)++)
        for (int(q) = 0; (q) < (int)(m); (q)++) {
          int zx = (i + x[q]) % n;
          int zy = (j + y[q]) % n;
          b[zx][zy] ^= a[i][j];
        }
    for (int(i) = 0; (i) < (int)(n); (i)++)
      for (int(j) = 0; (j) < (int)(n); (j)++) a[i][j] = b[i][j];
    for (int(q) = 0; (q) < (int)(m); (q)++) {
      x[q] = x[q] * 2 % n;
      y[q] = y[q] * 2 % n;
    }
  }
  int ans = 0;
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(n); (j)++) ans += a[i][j] != 0;
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
