#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long x, y;
  Point() {}
  Point(long long a, long long b) : x(a), y(b) {}
  Point operator-(Point b) { return Point(x - b.x, y - b.y); }
};
long long cross(Point x, Point y) { return x.x * y.y - x.y * y.x; }
Point st[100005];
int top;
long long calc(Point x, long long k) { return x.x * k + x.y; }
void insert(Point p) {
  while (top > 1 && cross(p - st[top], st[top] - st[top - 1]) >= 0) top--;
  st[++top] = p;
}
int a[100005], b[100005], num[100005];
long long up[100005];
void convex(int n, int m, long long lb, long long rb) {
  long long s = 0;
  for (int i = 1; i <= n; i++) s += a[i];
  top = 0;
  for (int i = n; i >= 0; i--) {
    insert(Point(n - i, s));
    s -= a[i];
  }
  int r = 1;
  for (int i = 1; i <= m; i++) {
    while (r < top && calc(st[r + 1], m - i) <= calc(st[r], m - i)) r++;
    up[i] = max(up[i], lb - calc(st[r], m - i));
  }
  s = 0;
  for (int i = 1; i <= n; i++) s += b[i];
  top = 0;
  for (int i = n; i >= 0; i--) {
    insert(Point(n - i, s));
    s -= b[i];
  }
  r = 1;
  for (int i = 1; i <= m; i++) {
    while (r < top && calc(st[r + 1], m - i) <= calc(st[r], m - i)) r++;
    up[i] = max(up[i], rb - calc(st[r], m - i));
  }
}
bool solve1(int n, long long rb) {
  long long s1 = 0, s2 = 0, maxn = 0;
  int last2 = 0;
  for (int i = 1; i <= n; i++)
    if (num[i] != -1) {
      if (maxn > num[i]) return 0;
      s1 += num[i];
      s2 += (long long)(i - last2 - 1) * (num[i] - maxn);
      if (s1 < up[i]) {
        if (s1 + s2 < up[i]) return 0;
        s2 -= up[i] - s1;
        s1 = up[i];
      }
      last2 = i;
      maxn = num[i];
    } else {
      s1 += maxn;
      if (s1 < up[i]) {
        if (s1 + s2 >= up[i]) {
          s2 -= up[i] - s1;
          s1 = up[i];
        } else {
          long long v = up[i] - s1 - s2, t = (v + i - last2 - 1) / (i - last2);
          maxn += t;
          s1 = up[i];
          s2 = t * (i - last2) - v;
        }
      }
    }
  return s1 <= rb && (s1 + s2 >= rb || num[n] != -1);
}
int solve2(int n, int k, long long rb) {
  long long s1 = 0, s2 = 0, maxn = 0;
  int last2 = 0;
  for (int i = 1; i <= n - k; i++)
    if (num[i] != -1) {
      s1 += num[i];
      s2 += (long long)(i - last2 - 1) * (num[i] - maxn);
      if (s1 < up[i]) {
        s2 -= up[i] - s1;
        s1 = up[i];
      }
      last2 = i;
      maxn = num[i];
    } else {
      s1 += maxn;
      if (s1 < up[i]) {
        if (s1 + s2 >= up[i]) {
          s2 -= up[i] - s1;
          s1 = up[i];
        } else {
          long long v = up[i] - s1 - s2, t = (v + i - last2 - 1) / (i - last2);
          maxn += t;
          s1 = up[i];
          s2 = t * (i - last2) - v;
        }
      }
    }
  long long t = -1;
  for (int i = n - k + 1; i <= n; i++)
    if (num[i] != -1) {
      if (t == -1)
        t = num[i];
      else if (t != num[i])
        return -1;
    }
  if (t == -1) t = (rb - s1) / k;
  long long v = rb - (long long)t * k;
  if (s1 > v || maxn > t) return -1;
  return (s1 + s2 + (long long)(n - k - last2) * (t - maxn) >= v) ? t : -1;
}
int main() {
  memset(num, 255, sizeof(num));
  int n, m;
  scanf("%d%d", &n, &m);
  long long lb = 0, s = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    lb += a[i];
    s += b[i];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  int k;
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    num[m - x + 1] = y;
  }
  long long rb = 0;
  scanf("%lld", &rb);
  if (lb > rb || s < rb) {
    puts("-1 -1");
    return 0;
  }
  convex(n, m, lb, rb);
  if (!solve1(m, rb)) {
    puts("-1 -1");
    return 0;
  }
  int l = 1, r = n;
  while (l < r) {
    int mid = ((l + r) >> 1) + 1;
    if (solve2(m, mid, rb) != -1)
      l = mid;
    else
      r = mid - 1;
  }
  int ans = solve2(m, l, rb);
  printf("%d %d\n", l, ans);
  return 0;
}
