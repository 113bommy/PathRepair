#include <bits/stdc++.h>
using namespace std;
int n;
struct dot {
  int x, y;
  bool operator<(const dot &a) const { return x != a.x ? x < a.x : y < a.y; }
} dots[10005];
set<dot> ans;
void solve(int l, int r) {
  if (l == r) return;
  solve(l, ((l + r) >> 1));
  solve(((l + r) >> 1) + 1, r);
  for (int i = l; i <= r; i++)
    ans.insert((dot){dots[((l + r) >> 1)].x, dots[i].y});
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d %d", &dots[i].x, &dots[i].y);
  sort(dots + 1, dots + 1 + n, [](dot a, dot b) { return a.x < b.x; });
  for (int i = 1; i <= n; i++) ans.insert(dots[i]);
  solve(1, n);
  printf("%d\n", ans.size());
  for (dot t : ans) printf("%d %d\n", t.x, t.y);
}
