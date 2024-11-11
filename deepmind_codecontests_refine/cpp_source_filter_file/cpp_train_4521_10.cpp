#include <bits/stdc++.h>
int n, k;
int sts[301][301];
typedef struct {
  double x;
  double y;
} shps;
int ln[301];
shps shp[301][301];
shps nw[301];
double ksol[301];
double EPS = 0.000000001;
double calc(double a, double b, double c) { return a + (b - a) * c; }
double calcx(double a, double b, double c, double d) {
  return (c - a) / (c - d - a + b);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      scanf("%d", &sts[i][j]);
    }
  }
  for (int i = 0; i <= k; i++) {
    ln[i] = 2;
    shp[i][0].x = 0;
    shp[i][1].x = 1;
    shp[i][0].y = 0;
    shp[i][1].y = 0;
  }
  for (int i = 0; i < n; i++) {
    ksol[i] = 0;
    for (int j = 0; j < k; j++) {
      double st = -1;
      double ed = -1;
      for (int t = 0; t < ln[j] - 1; t++) {
        if (calc(sts[i][j], sts[i][j + 1], shp[j][t].x) > shp[j][t].y + EPS) {
          st = shp[j][t].x;
          break;
        } else {
          if (calc(sts[i][j], sts[i][j + 1], shp[j][t + 1].x) >
              shp[j][t + 1].y + EPS) {
            double tx = calcx(calc(sts[i][j], sts[i][j + 1], shp[j][t].x),
                              calc(sts[i][j], sts[i][j + 1], shp[j][t + 1].x),
                              shp[j][t].y, shp[j][t + 1].y);
            st = shp[i][t].x + (shp[j][t + 1].x - shp[j][t].x) * tx;
            break;
          }
        }
      }
      for (int t = ln[j] - 2; t >= 0; t--) {
        if (calc(sts[i][j], sts[i][j + 1], shp[j][t + 1].x) >
            shp[j][t + 1].y + EPS) {
          ed = shp[j][t + 1].x;
          break;
        } else {
          if (calc(sts[i][j], sts[i][j + 1], shp[j][t].x) > shp[j][t].y + EPS) {
            double tx = calcx(calc(sts[i][j], sts[i][j + 1], shp[j][t].x),
                              calc(sts[i][j], sts[i][j + 1], shp[j][t + 1].x),
                              shp[j][t].y, shp[j][t + 1].y);
            ed = shp[j][t].x + (shp[j][t + 1].x - shp[j][t].x) * tx;
            break;
          }
        }
      }
      if (st > -EPS) {
        int nln = 0;
        for (int t = 0; t < ln[j]; t++) {
          if (shp[j][t].x < st - EPS) {
            nw[nln].x = shp[j][t].x;
            nw[nln].y = shp[j][t].y;
            nln++;
          }
        }
        nw[nln].x = st;
        nw[nln].y = calc(sts[i][j], sts[i][j + 1], st);
        nln++;
        nw[nln].x = ed;
        nw[nln].y = calc(sts[i][j], sts[i][j + 1], ed);
        nln++;
        for (int t = 0; t < ln[j]; t++) {
          if (shp[j][t].x > ed + EPS) {
            nw[nln].x = shp[j][t].x;
            nw[nln].y = shp[j][t].y;
            nln++;
          }
        }
        ln[j] = nln;
        for (int t = 0; t < nln; t++) {
          shp[j][t].x = nw[t].x;
          shp[j][t].y = nw[t].y;
        }
      }
      for (int t = 0; t < ln[j] - 1; t++) {
        ksol[i] += (shp[j][t].y + shp[j][t + 1].y) *
                   (shp[j][t + 1].x - shp[j][t].x) / 2;
      }
    }
  }
  printf("%.9f\n", ksol[0]);
  for (int i = 1; i < n; i++) printf("%.9f\n", ksol[i] - ksol[i - 1]);
  return 0;
}
