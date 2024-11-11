#include <bits/stdc++.h>
using namespace std;
int n;
struct point {
  long long x, y;
};
long long check(point &p1, point &p2, point &p3, point &p4) {
  long long x1 = p2.x - p1.x, y1 = p2.y - p1.y;
  long long x2 = p4.x - p3.y, y2 = p4.y - p3.y;
  return x1 * y2 - x2 * y1;
}
point a[1000010], st[1000010];
int top;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", &a[i].x, &a[i].y);
    a[i].x = a[i].x;
    a[i].y = a[i].y - a[i].x * a[i].x;
  }
  auto cmp = [&](const point &a, const point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  };
  sort(a, a + n, cmp);
  for (int i = n - 1; i > -1; --i) {
    a[i].x = a[i].x - a[0].x;
    a[i].y = a[i].y - a[0].y;
  }
  top = 0;
  for (int i = 0; i < n; ++i) {
    while (top > 1 && check(st[top - 2], st[top - 1], st[top - 2], a[i]) >= 0) {
      top--;
    }
    st[top++] = a[i];
  }
  int ans = 0;
  for (int i = 1; i < top; ++i) {
    if (st[i].x != st[i - 1].x) {
      ++ans;
    }
  }
  cout << ans << endl;
}
