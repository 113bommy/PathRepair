#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, x, y, num;
pair<int, int> a[N], b[N], c[N];
double slope(pair<int, int> a, pair<int, int> b) {
  return 1.0 * (b.second - a.second) / (b.first - a.first);
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &x, &y);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  for (int i = 1; i <= m; i++) scanf("%d%d", &b[i].first, &b[i].second);
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  int num = 0;
  for (int i = 1; i <= m; i++) {
    while (num && c[num].first <= b[i].first && c[num].second <= b[i].second)
      num--;
    while (num > 1 && slope(c[num - 1], c[num]) <= slope(c[num], b[i])) num--;
    c[++num] = b[i];
  }
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].first >= c[num].first || a[i].second >= c[1].second) {
      flag = 1;
      continue;
    }
    if (a[i].first < c[1].first && a[i].first < c[1].second) continue;
    if (a[i].first < c[num].first && a[i].first < c[num].second) continue;
    int l = 1, r = num;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (c[mid].first <= a[i].first)
        l = mid;
      else
        r = mid - 1;
    }
    if (c[l].first == a[i].first) {
      if (c[l].second <= a[i].second) flag = 1;
      continue;
    }
    if (slope(c[l], a[i]) >= slope(a[i], c[l + 1])) flag = 1;
  }
  if (flag)
    printf("Max\n");
  else
    printf("Min\n");
  return 0;
}
