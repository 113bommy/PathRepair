#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k, S, T, a[N], c[N], lst[N], q[N], dis[N],
    tot = 1, to[N], nx[N], hd[N], cap[N], cost[N], mx[N], pre[N], ans;
bool inq[N];
inline void read(int &i) {
  i = 0;
  char c = getchar();
  bool j = 0;
  for (; !isdigit(c); c = getchar())
    if (c == '-') j = 1;
  for (; isdigit(c); c = getchar()) i = (i << 1) + (i << 3) + c - '0';
  i = j ? -i : i;
}
inline void add(int x, int y, int z, int w) {
  to[++tot] = y, nx[tot] = hd[x], hd[x] = tot, cap[tot] = z, cost[tot] = w;
  to[++tot] = x, nx[tot] = hd[y], hd[y] = tot, cap[tot] = 0, cost[tot] = -w;
}
bool spfa() {
  memset(dis, 0x3f, 4 * (T + 1));
  int qh = 0, qt = 1, x, e;
  dis[S] = 0;
  q[0] = S;
  mx[S] = 1e9;
  while (qh != qt) {
    x = q[qh++];
    inq[x] = 0;
    for (e = hd[x]; e; e = nx[e])
      if (cap[e] && dis[to[e]] > dis[x] + cost[e]) {
        dis[to[e]] = dis[x] + cost[e];
        pre[to[e]] = e;
        mx[to[e]] = min(cap[e], mx[x]);
        if (!inq[to[e]]) inq[to[e]] = 1, q[qt++] = to[e];
      }
  }
  if (dis[T] == dis[0]) return 0;
  x = T;
  while (x != S) {
    e = pre[x];
    cap[e] -= mx[T], cap[e ^ 1] += mx[T];
    x = to[e ^ 1];
  }
  ans += mx[T] * dis[T];
  return 1;
}
int main() {
  read(n);
  read(k);
  k--;
  S = n + 1, T = n + 2;
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= n; ++i) read(c[i]);
  for (int i = 1; i <= n; ++i) {
    ans += c[a[i]];
    if (lst[a[i]]) {
      if (lst[a[i]] + 1 == i)
        ans -= c[a[i]];
      else
        add(lst[a[i]] + 1, i, 1, -c[a[i]]);
    }
    lst[a[i]] = i;
  }
  add(S, 1, k, 0);
  add(n, T, k, 0);
  for (int i = 1; i < n; ++i) add(i, i + 1, k, 0);
  while (spfa())
    ;
  printf("%d\n", ans);
  return 0;
}
