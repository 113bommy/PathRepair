#include <bits/stdc++.h>
using namespace std;
int nf, ne, nz, rf, re, rz, df, de;
double f, e, z, ans;
int a[100], N;
double d[40][30][30];
void dp() {
  memset(d, 0, sizeof(d));
  int i, j, k;
  double fire, elec;
  for (j = 0; j <= nf; j++) {
    for (k = 0; k <= ne; k++) {
      double &x = d[0][j][k];
      if (a[0] < 2) {
        fire = f * df;
        elec = e * de;
        for (int ii = 0; ii <= nz; ii++) {
          double rng = (min(double(ii + z * 1.0 / 2), double(f * 1.0 / 2)) -
                        max(double(ii - z * 1.0 / 2), double(-f * 1.0 / 2)));
          if (rng < 0) {
            rng = 0;
          }
          fire += double(a[ii] * df * rng);
          rng = (min(double(ii + z * 1.0 / 2), double(e * 1.0 / 2)) -
                 max(double(ii - z * 1.0 / 2), double(-e * 1.0 / 2)));
          if (rng < 0) {
            rng = 0;
          }
          elec += double(a[ii] * de * rng);
        }
        if (j > 0) {
          x = max(x, fire);
        }
        if (k > 0) {
          x = max(x, elec);
        }
        if (a[0] == 0) {
          if (j > 1) {
            x = max(x, 2 * fire);
          }
          if (j > 0 && k > 0) {
            x = max(x, fire + elec);
          }
          if (k > 1) {
            x = max(x, 2 * elec);
          }
        }
      }
    }
  }
  for (i = 1; i <= nz; i++) {
    for (j = 0; j <= nf; j++) {
      for (k = 0; k <= ne; k++) {
        double &x = d[i][j][k];
        x = d[i - 1][j][k];
        if (a[i] < 2) {
          fire = f * df;
          elec = e * de;
          for (int ii = 0; ii <= nz; ii++) {
            double rng =
                (min(double(ii + z * 1.0 / 2), double(i + f * 1.0 / 2)) -
                 max(double(ii - z * 1.0 / 2), double(i - f * 1.0 / 2)));
            if (rng < 0) {
              rng = 0;
            }
            fire += double(a[ii] * df * rng);
            rng = (min(double(ii + z * 1.0 / 2), double(i + e * 1.0 / 2)) -
                   max(double(ii - z * 1.0 / 2), double(i - e * 1.0 / 2)));
            if (rng < 0) {
              rng = 0;
            }
            elec += double(a[ii] * de * rng);
          }
          if (j > 0) {
            x = max(x, d[i - 1][j - 1][k] + fire);
          }
          if (k > 0) {
            x = max(x, (d[i - 1][j][k - 1] + elec));
          }
          if (a[i] == 0) {
            if (j > 1) {
              x = max(x, d[i - 1][j - 2][k] + 2 * fire);
            }
            if (j > 0 && k > 0) {
              x = max(x, d[i - 1][j - 1][k - 1] + fire + elec);
            }
            if (k > 1) {
              x = max(x, d[i - 1][j][k - 2] + 2 * elec);
            }
          }
        }
      }
    }
  }
  ans = max(ans, d[nz][nf][ne]);
}
int dfs(int pos, int x) {
  if (pos == N) {
    if (x == 0) dp();
    return 0;
  }
  if (x < 0) {
    return 0;
  }
  a[pos] = 0;
  dfs(pos + 1, x);
  a[pos] = 1;
  dfs(pos + 1, x - 1);
  a[pos] = 2;
  dfs(pos + 1, x - 2);
  return 0;
}
int main() {
  int i, j, k, n, m;
  scanf("%d%d%d", &nf, &ne, &nz);
  scanf("%d%d%d", &rf, &re, &rz);
  scanf("%d%d", &df, &de);
  N = (nf + ne + nz + 1) / 2;
  memset(a, 0, sizeof(a));
  ans = 0;
  f = 2 * sqrt(rf * rf - 1);
  e = 2 * sqrt(re * re - 1);
  z = 2 * sqrt(rz * rz - 1);
  dfs(0, nz);
  printf("%lf", ans);
  return 0;
}
