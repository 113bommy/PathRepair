#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dblcmp(double d) {
  if (fabs(d) < eps) return 0;
  return d > eps ? 1 : -1;
}
const long long p1 = 97;
const long long rp1 = -6656041676080766047LL;
const long long q1 = 113;
const long long rq1 = -7999030616033345391LL;
char dp[10][515][515];
long long calc(int n, int m, char s[][515]) {
  int i, j;
  long long hh = 0;
  long long pp = 1;
  for (i = 0; i < n; i++) {
    long long qq = 1;
    for (j = 0; j < m; j++) {
      hh += s[i][j] * pp * qq;
      qq *= q1;
    }
    pp *= p1;
  }
  return hh;
}
char s[1111][1111];
long long h[1111][1111];
long long rp[111111];
long long rq[111111];
struct strhash {
  int n, m;
  strhash() {}
  strhash(int _n, int _m, char _s[][1111]) {
    memcpy(s, _s, sizeof(s));
    n = _n;
    m = _m;
    long long pp = 1;
    h[0][0] = 0;
    int i, j;
    for (i = 0; i < n; i++) {
      long long qq = 1;
      for (j = 0; j < m; j++) {
        h[i + 1][j + 1] =
            s[i][j] * pp * qq + h[i + 1][j] + h[i][j + 1] - h[i][j];
        qq *= q1;
      }
      pp *= p1;
    }
    rp[0] = rq[0] = 1;
    for (i = 0; i < 11111; i++) {
      rp[i + 1] = rp[i] * rp1;
      rq[i + 1] = rq[i] * rq1;
    }
  }
  long long calchash(int xa, int ya, int xb, int yb) {
    return (h[xb][yb] - h[xa][yb] - h[xb][ya] + h[xa][ya]) * rp[xa] * rq[ya];
  }
};
int main() {
  int i, j, k, x, y, ms;
  set<long long> st;
  for (ms = 1; ms <= 15; ms++) {
    memset((dp), 0, sizeof(dp));
    dp[0][0][0] = '.';
    for (k = 1; k <= 9; k++) {
      int l = 1 << k;
      int dx[] = {0, l / 2, l / 2, 0};
      int dy[] = {0, 0, l / 2, l / 2};
      for (int u = 0; u < 4; u++) {
        for (i = dx[u]; i < l / 2 + dx[u]; i++) {
          for (j = dy[u]; j < l / 2 + dy[u]; j++) {
            if (ms & (1 << u))
              dp[k][i][j] = '*';
            else
              dp[k][i][j] = dp[k - 1][i - dx[u]][j - dy[u]];
          }
        }
      }
      if (k >= 2) {
        st.insert(calc(l, l, dp[k]));
      }
    }
  }
  int n, m, p;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  strhash hs(n, m, s);
  int ans = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      for (p = 4;; p *= 2) {
        if (i + p <= n && j + p <= m) {
          if (st.find(hs.calchash(i, j, i + p, j + p)) != st.end()) ans++;
        } else
          break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
