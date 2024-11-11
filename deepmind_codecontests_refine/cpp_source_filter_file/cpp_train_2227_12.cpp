#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
const int inf = 2e9;
int n;
pair<int, int> p[N];
int pre_min[N], aft_min[N], pre_max[N], aft_max[N];
void init() {
  pre_min[1] = pre_max[1] = p[1].second;
  for (int i = 2; i <= n; i++) {
    pre_min[i] = min(pre_min[i - 1], p[i].second);
    pre_max[i] = max(pre_max[i - 1], p[i].second);
  }
  aft_min[n] = aft_max[n] = p[n].second;
  for (int i = n - 1; i >= 1; i--) {
    aft_min[i] = min(aft_min[i + 1], p[i].second);
    aft_max[i] = max(aft_max[i + 1], p[i].second);
  }
}
bool solve(double mid) {
  int j = 1;
  for (int i = 1; i <= n; i++) {
    while (j <= n && 1.0 * (p[j].first - p[i].first) <= 2.0 * mid) j++;
    if (i == 1 && j == n + 1) return 1;
    int maxx = -inf, minn = inf;
    if (i > 1) {
      maxx = max(maxx, pre_max[i - 1]);
      minn = min(minn, pre_min[i - 1]);
    }
    if (j <= n) {
      maxx = max(maxx, aft_max[j]);
      minn = min(minn, aft_min[j]);
    }
    if (1.0 * (maxx - minn) <= 2.0 * mid) return 1;
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i].first = x - y;
    p[i].second = x + y;
  }
  sort(p + 1, p + 1 + n);
  init();
  double L = 0.0, R = inf;
  int cnt = 100;
  while (cnt--) {
    int mid = (L + R) / 2.0;
    if (solve(mid))
      R = mid;
    else
      L = mid;
  }
  printf("%.15f\n", R);
  return 0;
}
