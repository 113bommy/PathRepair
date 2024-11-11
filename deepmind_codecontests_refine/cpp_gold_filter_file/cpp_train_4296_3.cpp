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
int cnt;
bool ck(int n, int k) {
  if (n % 2 == 0) return 0;
  if (k == 0) return (n & (n + 1)) == 0;
  if (k == 1) return (n & (n + 1)) != 0;
  if (n == 9 && k == 2) return 0;
  return k > 0 && k <= (n - 3) / 2;
}
inline void cal(int n, int k, int fa) {
  printf("%d ", fa);
  int x = ++cnt;
  if (n == 1) return;
  for (int l = 1; l < n; l = l << 1 | 1) {
    int r = n - l - 1;
    int z = max(l, r) >= min(l, r) * 2;
    int rk = k - z;
    if (ck(l, 0) && ck(r, rk)) {
      cal(l, 0, x);
      cal(r, rk, x);
      return;
    }
  }
}
void fmain(int tid) {
  scanf("%d%d", &n, &k);
  if (!ck(n, k)) etp();
  puts("YES");
  cal(n, k, 0);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
