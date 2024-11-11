#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
struct tank {
  int hp, dt, l, r;
  double p;
  inline void read() {
    cin >> hp >> dt >> l >> r >> p;
    p /= 100;
  }
};
int a, b, c, d, i, j, n, m, k;
tank good, bad;
double dp[201][201][31][2];
double g[64], diag[64], sec[64];
int num[64];
inline double sum(int first, int second, int wait, int who) {
  if (first < 0 || second < 0) return 0.0;
  return dp[first][second][wait][who];
}
inline double sum(int x1, int y1, int x2, int y2, int wait, int who) {
  if (x1 > x2 || y1 > y2) return 0.0;
  return sum(x2, y2, wait, who) - sum(x1 - 1, y2, wait, who) -
         sum(x2, y1 - 1, wait, who) + sum(x1 - 1, y1 - 1, wait, who);
}
inline void solve() {
  for (int _n((64) - 1), i(0); i <= _n; i++) {
    if (diag[i] == 0.0) continue;
    g[i] /= diag[i];
    sec[i] /= diag[i];
    diag[i] = 1.0;
    for (int _n((64) - 1), j(0); j <= _n; j++) {
      if (i != j && num[j] == i) {
        double o = sec[j];
        if (num[i] == j) {
          diag[j] -= o * sec[i];
          num[j] = -1;
          sec[j] = 0.0;
        } else {
          num[j] = num[i];
          sec[j] = -o * sec[i];
        }
        g[j] -= o * g[i];
      }
    }
  }
}
int main() {
  good.read();
  bad.read();
  for (int _n((good.hp)), h1(1); h1 <= _n; h1++) {
    for (int _n((bad.hp)), h2(1); h2 <= _n; h2++) {
      memset(num, -1, sizeof(num));
      memset((g), 0, sizeof(g));
      memset((diag), 0, sizeof(diag));
      for (int _n((31) - 1), wait(0); wait <= _n; wait++) {
        for (int _n((2) - 1), who(0); who <= _n; who++) {
          if (!wait && who) continue;
          diag[wait * 2 + who] = 1.0;
          int l, r;
          if (who == 0) {
            int dt = good.dt;
            int nwait, nwho;
            if (wait <= dt) {
              nwait = dt - wait;
              nwho = who ^ 1;
              if (!nwait) nwho = 0;
            } else {
              nwait = wait - dt;
              nwho = who;
            }
            num[wait * 2 + who] = nwait * 2 + nwho;
            sec[wait * 2 + who] = -good.p;
            l = good.l, r = good.r;
            c = r - l + 1;
            d = r - h2 + 1;
            if (d < 0) d = 0;
            if (d > c) d = c;
            if (r >= h2) r = h2 - 1;
            g[wait * 2 + who] =
                ((sum(h1, h2 - r, h1, h2 - l, nwait, nwho) + d) / c) *
                (1.0 - good.p);
          } else {
            int dt = bad.dt;
            int nwait, nwho;
            if (wait <= dt) {
              nwait = dt - wait;
              nwho = who ^ 1;
              if (!nwait) nwho = 0;
            } else {
              nwait = wait - dt;
              nwho = who;
            }
            num[wait * 2 + who] = nwait * 2 + nwho;
            sec[wait * 2 + who] = -bad.p;
            l = bad.l, r = bad.r;
            c = r - l + 1;
            if (r >= h1) r = h1 - 1;
            g[wait * 2 + who] =
                (sum(h1 - r, h2, h1 - l, h2, nwait, nwho) / c) * (1.0 - bad.p);
          }
        }
      }
      solve();
      for (int _n((31) - 1), wait(0); wait <= _n; wait++) {
        for (int _n((2) - 1), who(0); who <= _n; who++) {
          if (!wait && who) continue;
          int v = wait * 2 + who;
          if (diag[v] != 0.0) dp[h1][h2][wait][who] = g[v] / diag[v];
          if (h1 == good.hp && h2 == bad.hp && !wait) {
            printf("%.9lf\n", dp[h1][h2][wait][who]);
            exit(0);
          }
          if (!h1 && !h2)
            ;
          else if (!h2)
            dp[h1][h2][wait][who] += dp[h1 - 1][h2][wait][who];
          else if (!h1)
            dp[h1][h2][wait][who] += dp[h1][h2 - 1][wait][who];
          else
            dp[h1][h2][wait][who] += dp[h1 - 1][h2][wait][who] +
                                     dp[h1][h2 - 1][wait][who] -
                                     dp[h1 - 1][h2 - 1][wait][who];
        }
      }
    }
  }
}
