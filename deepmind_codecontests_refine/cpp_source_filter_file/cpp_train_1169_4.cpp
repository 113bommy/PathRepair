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
long long a[200135];
struct lsp {
  long long a[60] = {0};
  const int maxBit = 54;
  bool insert(long long x) {
    for (int i = maxBit; ~i; i--)
      if (x & (1LL << i)) {
        if (a[i] != 0)
          x ^= a[i];
        else {
          for (int(j) = 0; (j) < (int)(i); (j)++)
            if (x & (1 << j)) x ^= a[j];
          for (int j = i + 1; j <= maxBit; j++)
            if (a[j] & (1 << i)) a[j] ^= x;
          a[i] = x;
          return 1;
        }
      }
    return 0;
  }
} sp;
int p[66], Ans;
void calsm() {
  vector<long long> bs;
  for (int(j) = 0; (j) < (int)(sp.maxBit); (j)++)
    if (sp.a[j]) bs.push_back(sp.a[j]);
  assert(bs.size() == k);
  for (int(i) = 0; (i) < (int)(1 << k); (i)++) {
    long long ss = 0;
    for (int(j) = 0; (j) < (int)(k); (j)++)
      if (i & (1 << j)) ss ^= bs[j];
    p[__builtin_popcountll(ss)]++;
  }
  for (int i = 0; i <= m; i++) {
    printf("%lld ", (long long)p[i] * fastPow(2, n - k) % 998244353);
  }
  exit(0);
}
void calbg() {
  vector<int> vp;
  for (int(j) = 0; (j) < (int)(sp.maxBit); (j)++)
    if (sp.a[j]) vp.push_back(j);
  int N = m - k;
  vector<vector<vector<int>>> dp(
      k + 1, vector<vector<int>>(k + 1, vector<int>(1 << N, 0)));
  dp[0][0][0] = 1;
  for (int(i) = 1; (i) <= (int)(k); (i)++) {
    int w = vp[i - 1], cc = 0;
    int zz = 0;
    for (int(j) = 0; (j) < (int)(sp.maxBit); (j)++)
      if (!sp.a[j]) {
        if (sp.a[w] & (1LL << j)) zz += 1 << cc;
        cc++;
      }
    for (int j = 0; j < i; j++) {
      for (int s = 0; s < (1 << N); s++) {
        addmod(dp[i][j][s], dp[i - 1][j][s]);
        addmod(dp[i][j + 1][s ^ zz], dp[i - 1][j][s]);
      }
    }
  }
  for (int j = 0; j <= k; j++) {
    for (int s = 0; s < (1 << N); s++) {
      addmod(p[j + __builtin_popcount(s)], dp[k][j][s]);
    }
  }
  for (int i = 0; i <= m; i++) {
    printf("%lld ", (long long)p[i] * fastPow(2, n - k) % 998244353);
  }
  exit(0);
}
void fmain(int tid) {
  scanf("%d%d", &n, &m);
  for (int(i) = 1; (i) <= (int)(n); (i)++) scanf("%lld", a + i);
  for (int(i) = 1; (i) <= (int)(n); (i)++) k += sp.insert(a[i]);
  if (k <= 20) calsm();
  calbg();
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
