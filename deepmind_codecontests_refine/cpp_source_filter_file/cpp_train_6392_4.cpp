#include <bits/stdc++.h>
using namespace std;
double dis[100005];
double f[100005];
int main() {
  double r;
  long long m;
  long long tmp;
  double s;
  while (scanf("%I64d%lf", &m, &r) != EOF) {
    f[1] = 0;
    double ans = 0;
    long long day = m * m;
    double s = sqrt(2 * r * r);
    dis[1] = 2 * r;
    dis[2] = 2 * r + s;
    dis[3] = 2 * r + 2 * s;
    for (int i = 4; i <= m; i++) {
      dis[i] = dis[i - 1] + 2 * r;
    }
    for (int i = 1; i <= m; i++) {
      f[1] += dis[i];
    }
    for (int i = 2; i <= m / 2; i++) {
      f[i] = f[i - 1] - dis[m - i + 2] + dis[i];
    }
    if (m & 1) {
      for (int i = 2; i <= (m + 1) / 2; i++) ans += dis[i];
      ans *= 2;
      ans += dis[m / 2 + 1];
    }
    for (int i = 1; i <= m / 2; i++) {
      ans += f[i] * 2;
    }
    printf("%.10lf\n", ans / day);
  }
  return 0;
}
