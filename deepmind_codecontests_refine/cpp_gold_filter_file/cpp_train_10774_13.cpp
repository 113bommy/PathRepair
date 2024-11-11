#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int n;
int a[N];
double b[N], sum[N];
double cal(double x) {
  sum[0] = 0;
  for (int i = 1; i <= n; i++) b[i] = 1.0 * a[i] - x;
  double mneg, mpos;
  mneg = mpos = 0;
  double gtmax = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + b[i];
    gtmax = max(gtmax, abs(b[i]));
    gtmax = max(gtmax, max(abs(sum[i] - mneg), abs(sum[i] - mpos)));
    mneg = min(mneg, sum[i]);
    mpos = max(mpos, sum[i]);
  }
  return gtmax;
}
bool cp(double x, double y) {
  double t = abs(x - y);
  return (t > 0.000000000001);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  double L = -1000001;
  double R = 1000001;
  double ML = (L + L + R) / 3;
  double MR = (L + R + R) / 3;
  while (cp(L, ML) && cp(ML, MR) && cp(MR, R)) {
    double x = cal(ML);
    double y = cal(MR);
    if (x > y)
      L = ML;
    else
      R = MR;
    ML = (L + L + R) / 3;
    MR = (L + R + R) / 3;
  }
  double ans = cal((L + R) / 2);
  printf("%0.7f", ans);
  return 0;
}
