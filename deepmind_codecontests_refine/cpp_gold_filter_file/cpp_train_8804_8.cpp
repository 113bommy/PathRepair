#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y, h;
} a[100010];
bool cmp(point a, point b) {
  if (a.y != b.y) return a.y < b.y;
  return a.x < b.x;
}
int dp[100010];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].h);
    sort(a, a + n, cmp);
    stack<point> p;
    long long ans = 0;
    long long mx = 0;
    for (int i = n - 1; i >= 0; i--) {
      while (1) {
        if (p.empty()) break;
        point f = p.top();
        if (f.y >= a[i].y && f.x < a[i].y) break;
        ans -= f.h;
        p.pop();
      }
      p.push(a[i]);
      ans += a[i].h;
      mx = max(mx, ans);
    }
    printf("%I64d\n", mx);
  }
  return 0;
}
