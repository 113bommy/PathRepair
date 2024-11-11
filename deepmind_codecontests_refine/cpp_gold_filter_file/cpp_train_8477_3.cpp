#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x, y;
  friend bool operator<(const node &a, const node &b) { return a.x < b.x; }
} p[100010];
pair<long long, int> mx, tmp;
long long crs(node a, node b, node c) {
  return 1ll * (b.x - a.x) * (c.y - a.y) - 1ll * (c.x - a.x) * (b.y - a.y);
}
struct convex {
  node p[400], stk[400];
  int top, sz, now, x;
  void built() {
    top = 0;
    now = 1;
    for (int i = 1; i <= sz; i++) {
      while (top > 1 && crs(stk[top - 1], p[i], stk[top]) <= 0) top--;
      stk[++top] = p[i];
    }
  }
  long long getans(node a, int x) { return a.y + x * a.x; }
  pair<long long, int> query() {
    while (now <= top && getans(stk[now], x) < getans(stk[now + 1], x)) now++;
    return make_pair(getans(stk[now], x), stk[now].x);
  }
} q[400];
int now = 1, n, s, tot;
long long w;
int main() {
  scanf("%d%I64d", &n, &w);
  for (int i = 1; i <= n; i++) scanf("%I64d%I64d", &p[i].y, &p[i].x);
  for (int i = 1; i <= n; i++) tot = max(1ll * tot, p[i].y);
  sort(p + 1, p + 1 + n);
  s = sqrt(tot);
  for (int i = 1; i <= tot / s + 1; i++) {
    for (int j = 1; j <= s; j++) q[i].p[j] = (node){(i - 1) * s + j, 0};
    q[i].sz = s;
    q[i].built();
  }
  for (int i = 0; now <= n; i++) {
    mx = make_pair(0, 0);
    for (; now <= n && p[now].x < i; now++) {
      for (int j = (p[now].y - 1) / s * s + 1; j <= p[now].y; j++)
        q[(p[now].y - 1) / s + 1].p[j - (p[now].y - 1) / s * s].y += j;
      q[(p[now].y - 1) / s + 1].built();
      for (int j = 1; j <= (p[now].y - 1) / s; j++) q[j].x++;
    }
    for (int j = 1; j <= tot / s + 1; j++) {
      tmp = q[j].query();
      if (tmp.first > mx.first) mx = tmp;
    }
    printf("%I64d %d\n", mx.first + (n - now + 1) * w * i, mx.second);
  }
  return 0;
}
