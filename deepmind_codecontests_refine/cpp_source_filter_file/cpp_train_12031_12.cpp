#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > q;
int main() {
  long long ans = 0;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a + b >= c + d) {
      q.push(make_pair(a + b, b));
      q.push(make_pair(c + d, d));
    } else if (a > d)
      ans += a - d;
    else if (b > c)
      ans += b - c;
  }
  int op = 1;
  while (!q.empty()) {
    int s = q.top().first;
    int x = q.top().second;
    ans += s * op;
    ans -= x;
    op ^= 1;
    q.pop();
  }
  printf("%lld\n", ans);
  return 0;
}
