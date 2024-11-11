#include <bits/stdc++.h>
using namespace std;
double getTime(int a, int d, int t, int v) {
  double t1 = v / (double)a;
  double x1 = (a * t1 * t1) / 2.0;
  if (x1 < d)
    t1 += (d - x1) / (double)v;
  else
    t1 = sqrt((2 * d) / (double)a);
  return t1 + t;
}
int main() {
  int n, a, d;
  cin >> n >> a >> d;
  double prevTime = 0.0;
  for (int i = 0; i < n; i++) {
    int t, v;
    cin >> t >> v;
    double time = getTime(a, d, t, v);
    if (!i || prevTime < time) prevTime = time;
    printf("%.6f\n", prevTime);
  }
  return 0;
}
