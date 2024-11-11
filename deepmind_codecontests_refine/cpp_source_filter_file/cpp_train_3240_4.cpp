#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
const int MOD = 998244353;
int pow_mod(int b, int p) {
  int ret = 1;
  while (p) {
    if (p & 1) ret = 1LL * ret * b % MOD;
    b = 1LL * b * b % MOD;
    p >>= 1;
  }
  return ret;
}
inline int add(int a, int b) { return (a + b) % MOD; }
inline int mul(int a, int b) { return 1LL * a * b % MOD; }
inline int sub(int a, int b) { return add(a, (MOD - b) % MOD); }
inline int inv(int x) { return pow_mod(x, MOD - 2); }
vector<int> v1[2 * MAXN + 5], v2[2 * MAXN + 5];
int x[MAXN + 5], y[MAXN + 5], n;
int dx[2 * MAXN + 5], dy[2 * MAXN + 5], xcnt, ycnt;
int tag[2 * MAXN + 5];
int func(int t) {
  xcnt = ycnt = 0;
  for (int i = 1; i <= n; i++) {
    dx[++xcnt] = x[i] + t + 1, dx[++xcnt] = x[i] - t;
    dy[++ycnt] = y[i] + t + 1, dy[++ycnt] = y[i] - t;
  }
  sort(dx + 1, dx + xcnt + 1), xcnt = unique(dx + 1, dx + xcnt + 1) - dx - 1;
  sort(dy + 1, dy + ycnt + 1), ycnt = unique(dy + 1, dy + ycnt + 1) - dy - 1;
  for (int i = 1; i <= xcnt; i++) v1[i].clear(), v2[i].clear();
  for (int i = 1; i <= n; i++) {
    int l = lower_bound(dx + 1, dx + xcnt + 1, x[i] - t) - dx;
    int r = lower_bound(dx + 1, dx + xcnt + 1, x[i] + t + 1) - dx;
    v1[l].push_back(i), v2[r].push_back(i);
  }
  int ans = 0;
  for (int i = 1; i <= xcnt; i++) {
    int tmp = 0;
    for (int j = 1; j <= ycnt; j++) {
      if (tmp) ans = add(ans, mul(dy[j] - dy[j - 1], dx[i] - dx[i - 1]));
      tmp += tag[j];
    }
    for (int j = 0; j < v1[i].size(); j++) {
      int p = v1[i][j];
      int u = lower_bound(dy + 1, dy + ycnt + 1, y[p] - t) - dy;
      int d = lower_bound(dy + 1, dy + ycnt + 1, y[p] + t + 1) - dy;
      tag[u]++, tag[d]--;
    }
    for (int j = 0; j < v2[i].size(); j++) {
      int p = v2[i][j];
      int u = lower_bound(dy + 1, dy + ycnt + 1, y[p] - t) - dy;
      int d = lower_bound(dy + 1, dy + ycnt + 1, y[p] + t + 1) - dy;
      tag[u]--, tag[d]++;
    }
  }
  return ans;
}
struct point {
  int x, y;
  point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
void func3(point p1, point p2, point p3, int &a, int &b, int &c) {
  int d = 0;
  a = b = c = 0;
  d = mul(p1.y, mul(inv(p1.x - p2.x), inv(p1.x - p3.x)));
  a = add(a, d), b = sub(b, mul(add(p2.x, p3.x), d)),
  c = add(c, mul(mul(p2.x, p3.x), d));
  d = mul(p2.y, mul(inv(p2.x - p1.x), inv(p2.x - p3.x)));
  a = add(a, d), b = sub(b, mul(add(p1.x, p3.x), d)),
  c = add(c, mul(mul(p1.x, p3.x), d));
  d = mul(p3.y, mul(inv(p3.x - p2.x), inv(p3.x - p1.x)));
  a = add(a, d), b = sub(b, mul(add(p1.x, p2.x), d)),
  c = add(c, mul(mul(p1.x, p2.x), d));
}
int s0(int x) { return x; }
int s1(int x) { return mul(x, mul(x + 1, inv(2))); }
int s2(int x) { return mul(x, mul(x + 1, mul(mul(2, x) + 1, inv(6)))); }
int func2(int l, int r) {
  if (r - l + 1 >= 3) {
    int a, b, c;
    func3(point(l, func(l)), point(l + 1, func(l + 1)),
          point(l + 2, func(l + 2)), a, b, c);
    a = mul(a, sub(s2(r), s2(l - 1)));
    b = mul(b, sub(s1(r), s1(l - 1)));
    c = mul(c, sub(s0(r), s0(l - 1)));
    return (add(add(a, b), c) + MOD) % MOD;
  } else if (r - l + 1 == 1)
    return func(l);
  else if (r - l + 1 == 2)
    return func(l) + func(r);
}
int a[MAXN * MAXN + 5], cnt;
int main() {
  int t;
  scanf("%d%d", &n, &t);
  for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      int p = max((abs(x[i] - x[j]) - 1) >> 1, (abs(y[i] - y[j]) - 1) >> 1);
      if (p <= t) a[++cnt] = p;
    }
  a[++cnt] = t;
  sort(a + 5, a + cnt + 1), cnt = unique(a + 1, a + cnt + 1) - a - 1;
  int ans = mul(t + 1, func(t)), lst = 0;
  for (int i = 1; i <= cnt; i++)
    ans = sub(ans, func2(lst, a[i])), lst = a[i] + 1;
  printf("%d\n", ans);
}
