#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  point() {}
  point(long long _x, long long _y) : x(_x), y(_y) {}
  bool operator<(const point &b) const { return y < b.y; }
} a[100010];
int n;
long long ma[100010][2];
long long mi[100010][2];
bool check(long long mid) {
  int l = 1, r = 0;
  for (int i = 1; i <= n; i++) {
    while (l <= r && a[l].y < a[i].y) l++;
    while (r + 1 <= n && a[r + 1].y - a[i].y <= mid) r++;
    long long MA = max(ma[l - 1][0], ma[r + 1][1]);
    long long MI = min(mi[l - 1][0], mi[r + 1][1]);
    if (MA - MI <= mid) return 1;
  }
  return 0;
}
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      a[i] = point((long long)x - y, (long long)x + y);
    }
    sort(a + 1, a + 1 + n);
    ma[0][0] = -1LL << 60;
    for (int i = 1; i <= n; i++) ma[i][0] = max(ma[i - 1][0], a[i].x);
    ma[n + 1][1] = -1LL << 60;
    for (int i = n; i >= 1; i--) ma[i][1] = max(ma[i + 1][0], a[i].x);
    mi[0][0] = 1LL << 60;
    for (int i = 1; i <= n; i++) mi[i][0] = min(mi[i - 1][0], a[i].x);
    mi[n + 1][1] = 1LL << 60;
    for (int i = n; i >= 1; i--) mi[i][1] = min(mi[i + 1][0], a[i].x);
    long long l = 0, r = 4000000000LL;
    while (l < r) {
      long long mid = (l + r) / 2;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    if (l % 2 == 0)
      printf("%I64d\n", l / 2);
    else
      printf("%I64d.5\n", l / 2);
  }
}
