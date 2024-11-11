#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double a, d;
  cin >> n >> a >> d;
  double time = 0.;
  for (int tb = 0; tb < (int)n; tb++) {
    double t, v;
    cin >> t >> v;
    double timeaux = v / a;
    double distvelmax = timeaux * v / 2.;
    double res;
    if (distvelmax > d) {
      double a = sqrt(d / distvelmax);
      res = t + timeaux * a;
    } else {
      res = (d - distvelmax) / v + timeaux;
    }
    if (res < time) res = time;
    printf("%.8f\n", res);
    time = res;
  }
}
