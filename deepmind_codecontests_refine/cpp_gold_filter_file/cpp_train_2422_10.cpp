#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int n, m, h[105];
pair<int, int> b[N], a[N << 2];
int main() {
  scanf("%d%d", &n, &m);
  for (auto i = 0; i < n; i++) {
    int x, h, l, r;
    scanf("%d%d%d%d", &x, &h, &l, &r);
    a[4 * i] = pair<int, int>(x - h, 101 - l);
    a[4 * i + 1] = pair<int, int>(x, -(101 - l));
    a[4 * i + 2] = pair<int, int>(x + 1, 101 - r);
    a[4 * i + 3] = pair<int, int>(x + h + 1, -(101 - r));
  }
  sort(a, a + 4 * n);
  for (auto i = 1; i <= m; i++) scanf("%d%d", &b[i].first, &b[i].second);
  sort(b + 1, b + m + 1);
  double ans = 0;
  for (int i = 1, j = 0; i <= m; i++) {
    while (j < 4 * n && a[j].first <= b[i].first) {
      int v = abs(a[j].second) - 1, sign = (a[j].second < 0) ? -1 : 1;
      h[v] += sign;
      j++;
    }
    double pro = 1;
    for (auto k = 0; k <= 100; k++)
      if (h[k]) pro *= pow((k + .0) / 100, h[k]);
    ans += pro * b[i].second;
  }
  printf("%.6f", ans);
}
