#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const long long int INFLL = 0x3f3f3f3f3f3f3f3fll;
long long int getint() {
  long long int ret = 0;
  bool f = 0;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f ^= 1;
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return f ? -ret : ret;
}
using namespace std;
const int mod = 1000000007;
const int MAXN = 1000000;
int inv[MAXN + 10], k, fac[MAXN + 10], invfac[MAXN + 10];
int mypow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1, a = (long long int)a * a % mod)
    if (b & 1) ret = (long long int)ret * a % mod;
  return ret;
}
void init() {
  inv[1] = 1;
  fac[0] = fac[1] = 1;
  invfac[0] = invfac[1] = 1;
  for (int i = 2; i <= k; ++i) {
    inv[i] = (long long int)(mod - mod / i) * inv[mod % i] % mod;
    fac[i] = (long long int)i * fac[i - 1] % mod;
    invfac[i] = (long long int)inv[i] * invfac[i - 1] % mod;
  }
}
int solve(int w) {
  int ans = 0, t;
  for (int i = 1; i <= k; ++i) {
    if (i <= w) {
      t = (long long int)fac[k] * invfac[k - i] % mod;
      ans = (ans + (long long int)mypow(k, w - i) * t % mod * t) % mod;
    } else {
      t = (long long int)fac[k - i + w] * invfac[k - i] % mod;
      ans = (ans +
             (long long int)fac[k] * invfac[k - i + w] % mod * t % mod * t) %
            mod;
    }
  }
  return ans;
}
int main() {
  k = getint();
  int w = getint();
  init();
  printf("%d\n",
         (int)(((long long int)solve(w) - solve(w - 1) + mypow(k, w) + mod) %
               mod));
}
