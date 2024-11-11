#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, sum = 0;
  char x = getchar();
  for (; (x < '0' || x > '9'); x = getchar())
    if (x == '-') f = -1;
  for (; x >= '0' && x <= '9'; x = getchar()) sum = sum * 10 + x - '0';
  return f * sum;
}
int T, n;
int GCD, x_, y_, num;
int a[200005], f[200005], g[200005], id[200005], sum[200005], ans[200005];
multiset<int> cc;
map<int, bool> vis;
inline bool comp(int x, int y) { return f[x] == f[y] ? x < y : f[x] < f[y]; }
inline int ex_gcd(int a, int b, int &x, int &y) {
  if (!b) return x = 1, y = 0, a;
  int d = ex_gcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
inline int calc_(int x) {
  if (vis.count(g[x])) return 0;
  int l = 2, r = num, mid, ans = 1;
  while (l <= r) {
    mid = l + r >> 1;
    bool t = 0;
    int c = (g[x] + 1) % num;
    auto it = cc.lower_bound(c);
    if (it != cc.end()) t = *it >= c && *it <= g[x] + mid - 1;
    if (g[x] + mid - 1 >= num) {
      it = cc.begin();
      if (it != cc.end() && *it + num <= g[x] + mid - 1) t = 1;
    }
    if (t)
      r = mid - 1;
    else
      ans = mid, l = mid + 1;
  }
  return ans;
}
int main() {
  T = read(), n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    sum[0] = (sum[0] + a[i]) % T;
    if (i > 1) sum[i] = (sum[i - 1] + a[i]) % T;
  }
  GCD = ex_gcd(sum[0], T, x_, y_);
  num = T / GCD;
  if (x_ < 0) x_ += ((-x_ - 1) / num + 1) * num;
  if (x_ > 0) x_ -= (x_ - 1) / num * num;
  for (int i = 1; i <= n; ++i) {
    f[i] = sum[i];
    f[i] = min(f[i], (sum[i] + ((T - sum[i] - 1) / GCD + 1) * GCD) % T);
  }
  for (int i = 1; i <= n; ++i) id[i] = i;
  sort(id + 1, id + n + 1, comp);
  for (int l = 1, r; l <= n; l = r + 1) {
    r = l;
    while (r < n && f[id[l]] == f[id[r + 1]]) ++r;
    int cnt = r - l + 1;
    for (int i = 1; i <= cnt; ++i) {
      int x = id[i + l - 1];
      int c = sum[x] - sum[id[l]];
      if (c >= 0)
        g[i] = 1ll * c / GCD * x_ % num;
      else
        g[i] = 1ll * (c + T) / GCD * x_ % num;
      cc.insert(g[i]);
    }
    for (int i = 1; i <= cnt; ++i) {
      cc.erase(cc.lower_bound(g[i]));
      ans[id[i]] = calc_(i);
      cc.insert(g[i]);
      vis[g[i]] = 1;
    }
    cc.clear(), vis.clear();
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  puts("");
}
