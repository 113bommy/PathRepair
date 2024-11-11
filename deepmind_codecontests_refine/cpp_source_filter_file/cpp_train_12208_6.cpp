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
const long long MOD2 = (long long)1000000007 * (long long)1000000007;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 1000000007) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
long long cal(long long x) { return (x + x + n - 1) * n / 2; }
void fmain(int tid) {
  scanf("%d", &n);
  long long s = 0;
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%lld", &lk);
    s += lk;
  }
  long long x = (s * 2 + n - (long long)n * n) / 2 / n;
  x = max(1LL, x - 100);
  while (cal(x + 1) <= s) {
    x++;
  }
  long long rm = s - cal(x);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    if (rm > 0) {
      rm--;
      printf("%lld ", x + i - 1 + 1);
    } else
      printf("%lld ", x + i - 1);
  }
  puts("");
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
