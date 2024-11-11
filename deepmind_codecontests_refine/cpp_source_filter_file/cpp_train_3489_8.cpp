#include <bits/stdc++.h>
using namespace std;
long long x[100005];
long long y[100005];
double dis[100005];
double diss[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &x[i], &y[i]);
  }
  double minn = 1e9 + 5;
  long long xx, yy, xy;
  for (int i = 2; i <= n; i++) {
    dis[i] =
        sqrt((x[i] - x[1]) * (x[i] - x[1]) + (y[i] - y[1]) * (y[i] - y[1]));
    if (dis[i] < minn) {
      minn = dis[i];
      xx = x[i];
      yy = y[i];
      xy = i;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (i == xy) {
      diss[i] = 0;
      continue;
    }
    double h1 = (y[i] - yy) * 1.0 / (x[i] - xx),
           h2 = (y[i] - y[1]) * 1.0 / (x[i] - x[1]);
    if (h1 == h2)
      diss[i] = 0;
    else {
      diss[i] =
          sqrt((x[i] - x[1]) * (x[i] - x[1]) + (y[i] - y[1]) * (y[i] - y[1])) +
          sqrt((x[i] - xx) * (x[i] - xx) + (y[i] - yy) * (y[i] - yy));
    }
  }
  minn = 1e18 + 5;
  double mini = 0;
  for (int i = 1; i <= n; i++) {
    if (diss[i] < minn && diss[i] != 0) {
      minn = diss[i];
      mini = i;
    }
  }
  cout << 1 << " " << xy << " " << mini << endl;
  return 0;
}
