#include <bits/stdc++.h>
const int mxn = 100000 + 10;
using namespace std;
int x, y;
int X[128], Y[128];
int vis[128][128];
double dp[128][128];
int K;
int id, n;
double eps;
double P(double D, double R) {
  if (D <= R || fabs(D - R) < 1e-7) return 1;
  double xx = 1.0 - ((D * D) / (R * R));
  return pow(M_E, xx);
}
double R;
double solve(int p, int k) {
  if (p == n) return k >= K;
  double &d = dp[p][k];
  int &v = vis[p][k];
  if (v == id) return d;
  v = id;
  d = 0;
  double D = hypot(X[p] - x, Y[p] - y);
  double pp = P(D, R);
  d += pp * solve(p + 1, k + 1);
  d += (1.0 - pp) * solve(p + 1, k);
  return d;
}
int main() {
  int ee;
  scanf("%d", &n);
  scanf("%d", &K);
  scanf("%d", &ee);
  scanf("%d", &x);
  scanf("%d", &y);
  eps = ee / 1000.0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &X[i]);
    scanf("%d", &Y[i]);
  }
  double low = 0, high = 1e9;
  while (fabs(low - high) > 1e-6) {
    double mid = (low + high) / 2.0;
    ++id;
    R = mid;
    double failprob = 1.0 - solve(0, 0);
    if (failprob <= eps || fabs(failprob - eps) < 1e-7)
      high = mid;
    else
      low = mid;
  }
  printf("%.20lf\n", low);
}
