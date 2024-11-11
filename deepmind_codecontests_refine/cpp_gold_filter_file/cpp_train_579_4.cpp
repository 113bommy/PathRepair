#include <bits/stdc++.h>
using namespace std;
const int maxn = 100500;
const int inf = 1e9;
struct node {
  long long x, y;
};
int n, ans = inf, f[maxn];
long long A, B, h, w, a[maxn];
bool cmp(long long x, long long y) { return x > y; }
queue<node> q, q2;
void solve(long long x, long long y) {
  for (int i = 2; i <= x; i++) f[i] = 0;
  f[1] = 1;
  while (!q.empty()) q.pop();
  q.push((node){1, 1});
  for (int i = 1; i <= min(n, 34); i++) {
    while (!q.empty()) {
      node u = q.front();
      q.pop();
      if (u.x >= x && u.y >= y) {
        ans = min(ans, i - 1);
        return;
      }
      node v = (node){min(u.x * a[i], x), u.y};
      if (v.y > f[v.x]) f[v.x] = v.y, q2.push(v);
      v = (node){u.x, min(u.y * a[i], y)};
      if (v.y > f[v.x]) f[v.x] = v.y, q2.push(v);
    }
    while (!q2.empty()) q.push(q2.front()), q2.pop();
  }
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    if (u.x >= x && u.y >= y) {
      ans = min(ans, min(n, 34));
      return;
    }
  }
}
int main() {
  scanf("%lld%lld%lld%lld%d", &A, &B, &h, &w, &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + 1 + n, cmp);
  long long x = (A + h - 1) / h, y = (B + w - 1) / w;
  solve(x, y);
  x = (A + w - 1) / w, y = (B + h - 1) / h;
  solve(x, y);
  if (ans == inf)
    puts("-1");
  else
    printf("%d\n", ans);
  return 0;
}
