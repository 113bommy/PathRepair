#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E6 + 10;
pair<int, int> a[MAXN];
int que[MAXN];
long long cross(long long x1, long long y1, long long x2, long long y2) {
  return x1 * y2 - x2 * y1;
}
int main() {
  int n, p, q;
  scanf("%d%d%d", &n, &p, &q);
  for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a, a + n);
  n = unique(a, a + n) - a;
  int r = 0;
  que[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (; r >= 0 && cross(a[i].first - a[que[r]].first,
                           a[i].second - a[que[r]].second, 1, 0) < 0 ||
           r >= 1 && cross(a[i].first - a[que[r]].first,
                           a[i].second - a[que[r]].second,
                           a[que[r - 1]].first - a[que[r]].first,
                           a[que[r - 1]].second - a[que[r]].second) <= 0;
         --r)
      ;
    que[++r] = i;
  }
  double ans;
  if (cross(a[que[0]].first, a[que[0]].second, p, q) >= 0)
    ans = q / (double)a[que[0]].second;
  else if (cross(a[que[r]].first, a[que[r]].second, p, q) <= 0)
    ans = p / (double)a[que[r]].first;
  else {
    int i = 1;
    for (; cross(a[que[i]].first, a[que[i]].second, p, q) < 0; ++i)
      ;
    long long x1 = a[que[i - 1]].first, y1 = a[que[i - 1]].second;
    long long x2 = a[que[i]].first, y2 = a[que[i]].second;
    double lemma = (x2 * q - y2 * p) / (double)(p * (y1 - y2) - q * (x1 - x2));
    ans = p / (x2 + lemma * (x1 - x2));
  }
  printf("%.8lf\n", ans);
  return 0;
}
