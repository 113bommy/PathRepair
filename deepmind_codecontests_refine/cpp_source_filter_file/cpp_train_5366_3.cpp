#include <bits/stdc++.h>
using namespace std;
multiset<pair<int, int> > s1;
struct Point {
  int x, y;
  void scan() { scanf("%d%d", &x, &y); }
} p[2001];
int cmp(Point p1, Point p2) { return p1.y < p2.y; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) p[i].scan();
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      if (i == j) continue;
      pair<int, int> pr = make_pair<int, int>(p[i].x + p[j].x, p[i].y + p[j].y);
      ans += s1.count(pr);
      s1.insert(pr);
    }
  printf("%I64d\n", ans);
}
