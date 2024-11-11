#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int maxn = 100005;
const int maxm = 1000005;
int n, t[maxn], sum[2][maxm];
double s, x[maxn], v[maxn];
inline void get(int d, double v, double t, int ty) {
  if (d / v - eps <= t) {
    ++sum[ty][0];
    return;
  }
  int left = d, right = 1000000, res = -1;
  while (left <= right) {
    int mid = (left + right) / 2;
    double t1 = (mid - d) / (s - v);
    double t2 = (d - t1 * v) / (s + v);
    if (t1 + t2 <= t) {
      left = mid + 1;
      res = mid;
    } else
      right = mid - 1;
  }
  if (res == -1) return;
  if (ty == 0) {
    ++sum[0][d];
    --sum[0][res + 1];
  } else {
    ++sum[1][1000000 - res];
    --sum[1][1000000 - d + 1];
  }
}
inline bool check(double mid) {
  memset(sum, 0, sizeof sum);
  for (int i = 0; i < n; ++i) {
    if (t[i] == 1)
      get(x[i], v[i], mid, 0);
    else
      get(1000000 - x[i], v[i], mid, 1);
  }
  for (int i = 1; i < maxm; ++i) {
    sum[0][i] += sum[0][i - 1];
    sum[1][i] += sum[1][i - 1];
    if (sum[0][i] > 0 && sum[1][i] > 0) return true;
  }
  return false;
}
int main() {
  scanf("%d%lf", &n, &s);
  for (int i = 0; i < n; ++i) scanf("%lf%lf%d", &x[i], &v[i], &t[i]);
  double left = 0, right = 1000000;
  int cnt = 0;
  while (cnt++ < 40) {
    double mid = (left + right) / 2;
    if (check(mid))
      right = mid;
    else
      left = mid;
  }
  printf("%.12f\n", left);
  return 0;
}
