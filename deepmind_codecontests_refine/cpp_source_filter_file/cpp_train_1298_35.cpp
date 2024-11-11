#include <bits/stdc++.h>
using namespace std;
struct node {
  long long h, id, val;
  bool operator<(const node &x) const { return val > x.val; }
};
priority_queue<node> q;
long long n, m, k, p, h[100010], a[100010];
int check(long long H) {
  while (q.size()) q.pop();
  for (int i = 1; i <= n; i++) {
    if (H - m * a[i] >= h[i]) continue;
    q.push((node){H, i, H / a[i]});
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= k; j++) {
      if (q.empty()) return 1;
      node x = q.top(), y;
      q.pop();
      if (x.h - i * a[x.id] < 0) return 0;
      y.h = x.h + p;
      if (y.h - m * a[x.id] >= h[x.id]) continue;
      y.id = x.id;
      y.val = y.h / a[y.id];
      q.push(y);
    }
  }
  return q.empty();
}
long long binary() {
  long long l = 0, r = 5e12 + 1;
  while (l + 1 < r) {
    long long mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  return r;
}
int main() {
  cin >> n >> m >> k >> p;
  for (int i = 1; i <= n; i++) {
    cin >> h[i] >> a[i];
  }
  cout << binary() << endl;
  return 0;
}
