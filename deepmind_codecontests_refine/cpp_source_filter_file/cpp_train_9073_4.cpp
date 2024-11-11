#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = 100005;
pair<int, int> a[N];
int st[N * 2][20], n, m;
double dis[N], deg[N];
pair<double, double> b[N * 2];
bool check(double mid) {
  for (int i = (int)(1); i <= (int)(n); i++) {
    double ang = acos(mid / dis[i]);
    b[i] = pair<double, double>(deg[i] - ang, deg[i] + ang);
    if (b[i].first < 0) b[i].first += 2 * pi, b[i].second += 2 * pi;
  }
  sort(b + 1, b + n + 1);
  int top = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    for (; top && b[top].second >= b[i].second; --top)
      ;
    b[++top] = b[i];
  }
  for (; b[top].second >= b[1].second + 2 * pi; --top)
    ;
  for (int i = (int)(1); i <= (int)(top); i++) b[i + top] = b[i];
  for (int i = (int)(top + 1); i <= (int)(top * 2); i++)
    b[i].first += 2 * pi, b[i].second += 2 * pi;
  int posi = 1;
  for (int i = (int)(1); i <= (int)(top); i++) {
    for (; posi < 2 * top && b[i].second >= b[posi].first + 1e-9; ++posi)
      ;
    st[i][0] = posi;
    st[i + top][0] = min(posi + top, 2 * top);
  }
  for (int i = (int)(1); i <= (int)(18); i++)
    for (int j = (int)(1); j <= (int)(top * 2); j++)
      st[j][i] = st[st[j][i - 1]][i - 1];
  for (int i = (int)(1); i <= (int)(top); i++) {
    int now = 0, posi = i;
    for (int j = (int)(18); j >= (int)(0); j--)
      if (st[posi][j] < i + top) posi = st[posi][j], now += 1 << j;
    if (now + 1 <= m) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%d%d", &a[i].first, &a[i].second);
  sort(a + 1, a + n + 1);
  n = unique(a + 1, a + n + 1) - a - 1;
  double l = 0, r = 1e10;
  for (int i = (int)(1); i <= (int)(n); i++) {
    dis[i] =
        sqrt(1ll * a[i].first * a[i].first + 1ll * a[i].second * a[i].second);
    deg[i] = atan2(a[i].second, a[i].first);
    r = min(r, dis[i]);
  }
  for (int T = (int)(1); T <= (int)(50); T++) {
    double mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.10lf\n", (l + r) / 2);
}
