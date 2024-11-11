#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct aa {
  int id, val, pass;
  friend bool operator<(const aa& a, const aa& b) { return a.pass > b.pass; }
} p[N], bug[N];
int n, m, s, ans[N];
bool cmp(const aa x, const aa y) { return x.val > y.val; }
bool ok(int k) {
  int a = 1, b = 1, sum = s;
  priority_queue<aa> que;
  while (b <= m) {
    while (a <= n)
      if (p[a].val >= bug[b].val)
        que.push(p[a++]);
      else
        break;
    if (que.empty()) return 0;
    aa c = que.top();
    que.pop();
    if (sum < c.pass) return 0;
    sum -= c.pass;
    b += k;
  }
  return 1;
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 1; i <= m; i++) scanf("%d", &bug[i].val), bug[i].id = i;
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].val);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].pass), p[i].id = i;
  sort(p + 1, p + n + 1, cmp);
  sort(bug + 1, bug + m + 1, cmp);
  if (!ok(m + 1)) {
    puts("NO");
    return 0;
  }
  int l = 1, r = m + 1;
  while (l < r) {
    int mid = l + r >> 1;
    if (ok(mid))
      r = mid;
    else
      l = mid + 1;
  }
  puts("YES");
  priority_queue<aa> que;
  int a = 1, b = 1;
  while (b <= m) {
    while (a <= n)
      if (p[a].val >= bug[b].val)
        que.push(p[a++]);
      else
        break;
    aa c = que.top();
    que.pop();
    int t = min(m, b + r);
    for (int i = b; i <= t; i++) ans[bug[i].id] = c.id + 1;
    b += r;
  }
  for (int i = 1; i <= m; i++) cout << ans[i] << " ";
}
