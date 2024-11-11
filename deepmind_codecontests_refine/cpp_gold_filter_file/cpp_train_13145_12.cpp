#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
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
string direc = "RDLU";
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
int Dx[] = {1, 0, -1, -1, 0, 1};
int Dy[] = {1, 1, 0, -1, -1, 0};
int c[10];
void fmain(int tid) {
  int x, y;
  scanf("%d%d", &x, &y);
  for (int(i) = 0; (i) < (int)(6); (i)++) scanf("%d", c + i);
  if (x == 0 && y == 0) {
    puts("0");
    return;
  }
  long long ans = ((1LL << 60)) * 6;
  for (int(i) = 0; (i) < (int)(6); (i)++)
    for (int j = i + 1; j < 6; j++) {
      int z = Dy[j] * Dx[i] - Dx[j] * Dy[i];
      int Z = x * Dy[j] - y * Dx[j];
      if (z == 0) {
        continue;
      }
      int pa = Z / z, pb;
      if (Dx[j] == 0) {
        pb = (y - Dy[i] * pa) / Dy[j];
      } else {
        pb = (x - Dx[i] * pa) / Dx[j];
      }
      if (pa < 0 || pb < 0) continue;
      mintt(ans, (long long)pa * c[i] + (long long)pb * c[j]);
    }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
