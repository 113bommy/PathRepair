#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
const int MAXN = 1000006;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
namespace ModCalculator {
const int MOD = 998244353;
inline void Inc(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
inline void Dec(int &x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
inline int Add(int x, int y) {
  Inc(x, y);
  return x;
}
inline int Sub(int x, int y) {
  Dec(x, y);
  return x;
}
inline int Mul(int x, int y) { return 1LL * x * y % MOD; }
inline int ksm(int x, int k) {
  int ret = 1;
  for (; k; k >>= 1) {
    if (k & 1) ret = Mul(ret, x);
    x = Mul(x, x);
  }
  return ret;
}
inline int Inv(int x) { return ksm(x, MOD - 2); }
}  // namespace ModCalculator
using namespace ModCalculator;
int n, f[3][MAXN], g[MAXN];
int pw10[10], pw2[MAXN];
void init() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    int x;
    read(x);
    ++f[0][x];
    Inc(f[1][x], x);
    Inc(f[2][x], Mul(x, x));
  }
  for (int i = pw10[0] = 1; i < 6; ++i) {
    pw10[i] = pw10[i - 1] * 10;
  }
  for (int i = pw2[0] = 1; i <= n; ++i) {
    pw2[i] = Add(pw2[i - 1], pw2[i - 1]);
  }
}
void solve() {
  for (int i = 0; i < 6; ++i) {
    for (int j = N - 1; j; --j) {
      if ((j / pw10[i]) % 10 < 9) {
        f[0][j] += f[0][j + pw10[i]];
        Inc(f[1][j], f[1][j + pw10[i]]);
        Inc(f[2][j], f[2][j + pw10[i]]);
      }
    }
  }
  for (int i = 1; i < N; ++i) {
    g[i] = Mul(f[2][i], pw2[f[0][i] - 1]);
    if (f[0][i] > 1) {
      Inc(g[i], Mul(Sub(Mul(f[1][i], f[1][i]), f[2][i]), pw2[f[0][i] - 2]));
    }
  }
  for (int i = 0; i < 6; ++i) {
    for (int j = 1; j < N; ++j) {
      if ((j / pw10[i]) % 10 < 9) {
        Dec(g[j], g[j + pw10[i]]);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < N; ++i) {
    ans ^= 1LL * g[i] * i;
  }
  printf("%lld\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
