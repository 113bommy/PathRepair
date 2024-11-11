#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int main() {
  int n, m, c1, c2, v;
  scanf("%d%d%d%d%d", &n, &m, &c1, &c2, &v);
  for (int i = 1; i <= c1; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= c2; i++) {
    scanf("%d", &b[i]);
  }
  int q;
  a[0] = -2e8, a[c1 + 1] = 2e8;
  b[0] = -2e8, b[c2 + 1] = 2e8;
  scanf("%d", &q);
  while (q--) {
    int x, y, xx, yy;
    int ans1 = 0, ans2 = 0, ans = 1e9;
    scanf("%d%d%d%d", &x, &y, &xx, &yy);
    if (x == xx) {
      cout << abs(yy - y) << endl;
      continue;
    }
    int s = *lower_bound(a + 0, a + c1 + 2, y);
    ans1 += abs(s - y);
    ans1 += abs(xx - x);
    ans1 += abs(s - yy);
    s = *(upper_bound(a + 0, a + c1 + 2, y) - 1);
    ans2 += abs(s - y);
    ans2 += abs(xx - x);
    ans2 += abs(s - yy);
    ans = min(ans1, ans2);
    s = *lower_bound(b + 0, b + c2 + 2, y);
    ans2 = 0;
    ans2 += abs(s - y);
    ans2 += abs(xx - x) % v ? abs(xx - x) / v + 1 : abs(xx - x) / v;
    ans2 += abs(s - yy);
    ans = min(ans, ans2);
    s = *(upper_bound(b + 0, b + c2 + 2, y) - 1);
    ans2 = 0;
    ans2 += abs(s - y);
    ans2 += abs(xx - x) % v ? abs(xx - x) / v + 1 : abs(xx - x) / v;
    ans2 += abs(s - yy);
    ans = min(ans, ans2);
    printf("%d\n", ans);
  }
  return 0;
}
