#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
using ll = long long;
struct Point {
  ll x, y;
} p[N];
int n, a, b, c, d, idx, top;
ll dp[N];
int main() {
  ios::sync_with_stdio(false);
  scanf("%d%d/%d%d/%d", &n, &a, &b, &c, &d);
  for (int i = 1; i <= n; i++) {
    ll t1, t2;
    scanf("%lld%lld", &t1, &t2);
    ++idx;
    p[idx] = {t2 * b - t1 * a, t1 * c - t2 * d};
    if (p[idx].x <= 0 || p[idx].y <= 0) --idx;
  }
  sort(p + 1, p + idx + 1,
       [](Point a, Point b) { return a.x < b.x || (a.x == b.x && a.y > b.y); });
  for (int i = 1; i <= idx; i++) {
    int l = 1, r = top, ans = top + 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (p[i].y <= dp[mid])
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    if (ans == top + 1) ++top;
    dp[ans] = p[i].y;
  }
  cout << top << endl;
  return 0;
}
