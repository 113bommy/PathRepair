#include <bits/stdc++.h>
using namespace std;
inline int cmp(double a, double b = 0.0) {
  if (fabs(a - b) <= (1e-8)) return 0;
  if (a < b) return -1;
  return 1;
}
int px[101], py[101];
double dist[101];
int n, k, eps;
int ix, iy;
double R;
double prob(double d) {
  if (d <= R) return 1.;
  return exp(1 - d * d / R / R);
}
double pd[102][102];
bool go() {
  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < n + 1; j++) pd[i][j] = 0.;
  pd[0][0] = 1.;
  for (int i = 0; i < n; i++) {
    double p = prob(dist[i]);
    for (int j = 0; j < n + 1; j++) {
      pd[i + 1][j] = (j ? pd[i][j - 1] * p : 0.) + pd[i][j] * (1 - p);
    }
  }
  double a = 0.;
  for (int i = 0; i < k; i++) a += pd[n][i];
  if (cmp(1000. * a, eps) <= 0) return true;
  return false;
}
int main() {
  cin >> n >> k >> eps;
  cin >> ix >> iy;
  for (int i = 0; i < n; i++) cin >> px[i] >> py[i];
  for (int i = 0; i < n; i++) {
    dist[i] =
        sqrt(((px[i] - ix) * (px[i] - ix)) + ((py[i] - iy) * (py[i] - iy)));
  }
  double l = 0., r = 1010 * 1010;
  for (int i = 0; i < 300; i++) {
    R = (l + r) / 2.;
    if (go())
      r = R;
    else
      l = R;
  }
  cout << setprecision(8) << fixed << l << endl;
  return 0;
}
