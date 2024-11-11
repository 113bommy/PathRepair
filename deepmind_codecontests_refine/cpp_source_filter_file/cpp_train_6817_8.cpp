#include <bits/stdc++.h>
using namespace std;
long double a[105][105][105];
int main() {
  int R, P, S;
  cin >> R >> P >> S;
  a[R][P][S] = 1;
  for (int r = R; r >= 0; r--) {
    for (int p = P; p >= 0; p--) {
      for (int s = S; s >= 0; s--) {
        if (r == 0 && p == 0) continue;
        if (r == 0 && s == 0) continue;
        if (s == 0 && p == 0) continue;
        long double cur = a[r][p][s];
        int wr = r * s;
        int ws = p * s;
        int wp = r * p;
        int tways = wr + ws + wp;
        if (s > 0) a[r][p][s - 1] += cur * wr * 1.0 / tways;
        if (r > 0) a[r - 1][p][s] += cur * wp * 1.0 / tways;
        if (p > 0) a[r][p - 1][s] += cur * ws * 1.0 / tways;
      }
    }
  }
  long double wrs = 0.0;
  long double wps = 0.0;
  long double wss = 0.0;
  for (int i = 1; i <= R; i++) wrs += a[i][0][0];
  for (int i = 1; i <= P; i++) wps += a[0][i][0];
  for (int i = 1; i <= S; i++) wss += a[0][0][i];
  printf("%.12f %.12f %.12f\n", (double)wrs, (double)wss, (double)wps);
  return 0;
}
