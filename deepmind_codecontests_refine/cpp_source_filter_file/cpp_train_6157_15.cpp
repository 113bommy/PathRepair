#include <bits/stdc++.h>
using namespace std;
long long sx, sy, fx, fy, cx, cy;
long long dx[] = {0, 0, -1, 1};
long long dy[] = {1, -1, 0, 0};
char s[100005];
long long n, a[100005];
bool check(long long t) {
  long long px = sx + cx * (t / n), py = sy + cy * (t / n);
  for (int i = 0; i < t % n; i++) {
    px += dx[a[i]];
    py += dy[a[i]];
  }
  return abs(px - fx) + abs(py - fy) <= t;
}
long long solve() {
  long long lo = 1, hi = 2 * 1000000009, mid, ans = -1;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (check(mid)) {
      hi = mid - 1;
      ans = mid;
    } else
      lo = mid + 1;
  }
  return ans;
}
int main() {
  scanf("%lld", &sx), scanf("%lld", &sy);
  scanf("%lld", &fx), scanf("%lld", &fy);
  scanf("%lld", &n);
  scanf("%s", s);
  cx = cy = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U')
      a[i] = 0;
    else if (s[i] == 'D')
      a[i] = 1;
    else if (s[i] == 'L')
      a[i] = 2;
    else
      a[i] = 3;
    cx += dx[a[i]];
    cy += dy[a[i]];
  }
  printf("%lld\n", solve());
  return 0;
}
