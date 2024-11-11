#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static const int L = 233333;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) {
      return EOF;
    }
  }
  return *sss++;
}
template <class T>
inline bool read(T& x) {
  bool flg = false;
  char c = gc();
  x = 0;
  for (; !isdigit(c); c = gc()) {
    if (c == '-') {
      flg = true;
    } else if (c == EOF) {
      return false;
    }
  }
  for (; isdigit(c); c = gc()) {
    x = (x << 1) + (x << 3) + (c ^ 48);
  }
  if (flg) {
    x = -x;
  }
  return true;
}
const int maxn = 100;
const double eps = 1e-10;
int p[maxn];
int a[maxn];
int b[maxn];
int n, m;
double dp[maxn][maxn];
double ans;
inline double getdp(int a, int b) {
  if (b > m) {
    return ans;
  } else {
    return dp[a][b];
  }
}
inline bool pan() {
  for (int i = n; i; --i) {
    if (i == 1) {
      dp[i][0] = p[i] * (getdp(i + 1, a[i]) + a[i]) / 100. +
                 (100 - p[i]) * (getdp(i + 1, b[i]) + b[i]) / 100.;
    } else {
      for (int j = 0; j <= m; ++j) {
        dp[i][j] =
            min(ans, p[i] * (getdp(i + 1, j + a[i]) + a[i]) / 100. +
                         (100 - p[i]) * (getdp(i + 1, j + b[i]) + b[i]) / 100.);
      }
    }
  }
  return dp[1][0] < ans;
}
int main() {
  read(n), read(m);
  for (int i = 1; i <= n; ++i) {
    read(a[i]), read(b[i]), read(p[i]);
  }
  double l = 0., r = 1e9;
  while (r - l > eps) {
    ans = (l + r) / 2.;
    if (pan()) {
      r = ans;
    } else {
      l = ans;
    }
  }
  printf("%.10f", ans);
  return 0;
}
