#include <bits/stdc++.h>
using namespace std;
const int inf = 0x20202020;
const int mod = 1000000007;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
template <class T>
inline void read(T& x, T& y, T& z, T& q) {
  read(x);
  read(y);
  read(z);
  read(q);
}
const int DX[] = {1, 0, -1, 0}, DY[] = {0, 1, 0, -1};
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 99, M = 111111;
int m, n, t, C, tot;
int l[N], r[N], MA[N * 2];
double res[N], dp[N][N], tmp[N][N];
void work(int x, int y) {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1.0 * (MA[y + 1] - MA[y]) / (r[x] - l[x]);
  int s1 = 0, s2 = 0;
  for (int _ = (1); _ <= (n); ++_)
    if (_ != x) {
      if ((min(r[_], MA[y]) - min(l[_], MA[y])) == (r[_] - l[_])) {
        s1++;
        continue;
      }
      if ((max(r[_], MA[y + 1]) - max(l[_], MA[y + 1])) == (r[_] - l[_])) {
        s2++;
        continue;
      }
      double p1 = 1.0 * (min(r[_], MA[y]) - min(l[_], MA[y])) / (r[_] - l[_]);
      double p3 =
          1.0 * (max(r[_], MA[y + 1]) - max(l[_], MA[y + 1])) / (r[_] - l[_]);
      double p2 = 1 - p1 - p3;
      for (int i = (_); i >= (0); --i)
        for (int j = (_ - i); j >= (0); --j)
          if (dp[i][j]) {
            dp[i + 1][j] += dp[i][j] * p1, dp[i][j + 1] += dp[i][j] * p3,
                dp[i][j] = dp[i][j] * p2;
          }
    }
  if (s1 || s2)
    for (int i = (n); i >= (0); --i)
      for (int j = (n - i); j >= (0); --j)
        dp[i + s1][j + s2] = dp[i][j], dp[i][j] = 0;
  for (int i = (0); i <= (n); ++i)
    for (int j = (0); j <= (n - i); ++j)
      if (i + 1 <= i + (n - i - j))
        res[i + 1] += dp[i][j] / (n - i - j),
            res[i + (n - i - j) + 1] -= dp[i][j] / (n - i - j);
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i)
    scanf("%d%d", &l[i], &r[i]), MA[++tot] = l[i], MA[++tot] = r[i];
  sort(MA + 1, MA + 1 + tot);
  tot = unique(MA + 1, MA + 1 + tot) - MA - 1;
  for (int i = (1); i <= (n); ++i) {
    memset(res, 0, sizeof(res));
    for (int j = (1); j <= (tot - 1); ++j)
      if (l[i] <= MA[j] && MA[j + 1] <= r[i]) work(i, j);
    res[0] = 0;
    for (int i = (1); i <= (n); ++i) printf("%.9lf ", res[i] += res[i - 1]);
    puts("");
  }
  return 0;
}
