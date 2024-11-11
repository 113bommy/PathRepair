#include <bits/stdc++.h>
const double pi = acos(-1.0);
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
using namespace std;
pair<pair<int, int>, int> d[1000001];
int n, k, h;
bool ok(double t, bool F) {
  int num = 1;
  for (int i = 1; i <= n; i++) {
    if (!((double)num * h > t * d[i].first.second)) {
      ++num;
      if (F) printf("%d ", d[i].second);
      if (num > k) return true;
    }
  }
  return false;
}
int main() {
  scanf("%d%d%d", &n, &k, &h);
  scanf("\n");
  int a = 0;
  for (int i = 0; i <= n; i++) ++a;
  for (int i = 1; i <= n; i++) scanf("%d", &d[i].first);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i].first.second);
  for (int i = 1; i <= n; i++) d[i].second = i;
  sort(d + 1, d + n + 1);
  double l = 0, r = 1e9;
  for (int i = 1; i <= 40; i++) {
    double m = (l + r) / 2;
    if (ok(m, false))
      r = m;
    else
      l = m;
  }
  ok(r, true);
  puts("");
}
