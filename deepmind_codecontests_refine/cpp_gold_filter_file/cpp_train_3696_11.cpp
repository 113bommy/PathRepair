#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 500;
struct node {
  int kd, x;
} a[N * 2];
bool cmp(node a, node b) { return a.x < b.x; }
pair<int, int> ans[N], f[N * 2];
int e, s, n, m;
deque<int> q[4];
int main() {
  scanf("%d%d%d%d", &e, &s, &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].kd, &a[i].x);
  for (int i = 1; i <= m; i++)
    scanf("%d", &a[i + n].x), a[i + n].kd = -i, ans[i] = make_pair(-1, -1);
  sort(a + 1, a + n + m + 1, cmp);
  int num = n + m;
  for (; num > 0 && a[num].x > e; --num)
    ;
  a[num + 1].x = e;
  a[num + 1].kd = 3;
  f[num + 1] = make_pair(0, 0);
  q[3].push_back(num + 1);
  for (int i = num; i; i--) {
    for (int j = 1; j <= 3; j++)
      while (!q[j].empty() && a[q[j].front()].x > a[i].x + s) q[j].pop_front();
    if (a[i].kd < 0) {
      for (int j = 3; j; j--)
        if (!q[j].empty()) {
          int t = q[j].front(), tmp = s - a[t].x + a[i].x;
          if (j == 3) ans[-a[i].kd] = make_pair(f[t].first, f[t].second);
          if (j == 2)
            ans[-a[i].kd] = make_pair(f[t].first, max(f[t].second - tmp, 0));
          if (j == 1)
            ans[-a[i].kd] = make_pair(max(0, f[t].first - tmp), f[t].second);
          break;
        }
      continue;
    }
    int t = -1, j = 3;
    for (; j >= a[i].kd; j--)
      if (!q[j].empty()) {
        if (t == -1 || a[t].x > a[q[j].back()].x) t = q[j].back();
      }
    if (t == -1)
      for (; j; j--)
        if (!q[j].empty()) {
          t = q[j].front();
          break;
        }
    if (t == -1) break;
    f[i] = f[t];
    int tmp = s - a[t].x + a[i].x;
    if (a[t].kd >= a[i].kd) {
      if (a[i].kd == 1)
        f[i].first += s - tmp;
      else if (a[i].kd == 2)
        f[i].second += s - tmp;
    } else {
      if (a[t].kd == 1)
        f[i].first -= tmp;
      else if (a[t].kd == 2)
        f[i].second -= tmp;
      if (a[i].kd == 2) f[i].second += s;
    }
    q[a[i].kd].push_back(i);
  }
  for (int i = 1; i <= m; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
