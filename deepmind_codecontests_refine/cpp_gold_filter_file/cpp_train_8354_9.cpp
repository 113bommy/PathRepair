#include <bits/stdc++.h>
using namespace std;
int n;
int lx[2007], rx[2007], y[2007];
vector<pair<double, int> > q;
vector<double> p;
double calc(double a) {
  double minn = 1e100;
  double maxx = -1e100;
  for (int i = 1; i <= n; i++) {
    minn = min(minn, lx[i] - y[i] * a);
    maxx = max(maxx, rx[i] - y[i] * a);
  }
  return maxx - minn;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &lx[i], &rx[i], &y[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (y[i] <= y[j]) continue;
      q.emplace_back(((lx[j] - rx[i]) * 1.0 / (y[j] - y[i])), -1);
      q.emplace_back(((rx[j] - lx[i]) * 1.0 / (y[j] - y[i])), 1);
    }
  }
  if (q.empty()) {
    q.emplace_back(0, 0);
  }
  sort(q.begin(), q.end());
  int sum = 0;
  for (auto y : q) {
    if (sum == 0) {
      p.push_back(y.first);
    }
    sum += y.second;
    if (sum == 0) {
      p.push_back(y.first);
    }
  }
  int l = 0, r = p.size() - 1;
  while (l + 7 < r) {
    int midl = (2 * l + r) / 3;
    int midr = (l + 2 * r) / 3;
    double L = calc(p[midl]);
    double R = calc(p[midr]);
    if (L < R) {
      r = midr;
    } else {
      l = midl;
    }
  }
  double ans = 1e100;
  for (int i = l; i <= r; i++) {
    ans = min(ans, calc(p[i]));
  }
  printf("%.12f\n", ans);
  return 0;
}
