#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
struct Circle {
  int x, r;
  Circle(int x, int r) : x(x), r(r) {}
  bool operator<(const Circle& rhs) const { return x + r > rhs.x + rhs.r; }
};
priority_queue<Circle> q;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1, x, r; i <= n; i++) {
    scanf("%d%d", &x, &r);
    q.push(Circle(x, r));
  }
  int now = -INF, ans = 0;
  while (!q.empty()) {
    Circle c = q.top();
    q.pop();
    if (c.x - c.r < now) {
      continue;
    }
    ans++;
    now = c.x + c.r;
  }
  printf("%d\n", ans);
  return 0;
}
