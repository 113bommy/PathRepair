#include <bits/stdc++.h>
using namespace std;
int x[5555], y[5555], z[5555];
double Dis[5555];
int sqr(int x) { return x * x; }
double dis(int a, int b) {
  return sqrt(sqr(x[a] - x[b]) + sqr(y[a] - y[b]) + sqr(z[a] - z[b]) + 0.0);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &x[i], &y[i], &z[i]);
    Dis[i] = dis(0, i);
  }
  double ans = 1e20;
  for (int i = 1; i < n; i++) {
    for (int j = i + 2; j < n; j++) {
      ans = min(ans, Dis[i] + Dis[j] + dis(i, j));
    }
  }
  printf("%.10lf\n", ans / 2);
  return 0;
}
