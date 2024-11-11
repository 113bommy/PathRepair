#include <bits/stdc++.h>
using namespace std;
const int N = 8e5 + 5;
int n, m, tot, cnt, ans, now, a[N], b[N], tr[N], f[N], g[N], tim[N], Ans[N];
struct node {
  int id, pos, val, f, g;
} t[N];
int lowbit(int x) { return x & -x; }
void add(int x, int v) {
  for (; x <= cnt; x += lowbit(x)) tr[x] = max(tr[x], v);
}
int query(int x) {
  int res = 0;
  for (; x; x -= lowbit(x)) res = max(res, tr[x]);
  return res;
}
bool cmp(node x, node y) {
  if (x.pos == y.pos) return x.val < y.val;
  return x.pos < y.pos;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[++tot] = a[i];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &t[i].pos, &t[i].val);
    b[++tot] = t[i].val;
    t[i].id = i;
  }
  sort(b + 1, b + 1 + tot);
  cnt = unique(b + 1, b + 1 + tot) - b - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
  for (int i = 1; i <= m; i++)
    t[i].val = lower_bound(b + 1, b + 1 + cnt, t[i].val) - b;
  for (int i = 1; i <= n; i++) {
    f[i] = query(a[i] - 1) + 1;
    add(a[i], f[i]);
  }
  memset(tr, 0, sizeof(tr));
  for (int i = n; i; i--) {
    g[i] = query(cnt - a[i]) + 1;
    add(cnt - a[i] + 1, g[i]);
  }
  for (int i = 1; i <= n; i++) ans = max(ans, f[i] + g[i] - 1);
  for (int i = 1; i <= n; i++) {
    if (f[i] + g[i] - 1 == ans) tim[f[i]]++;
  }
  sort(t + 1, t + 1 + m, cmp);
  memset(tr, 0, sizeof(tr));
  now = 1;
  for (int i = 1; i <= m; i++) {
    while (now < t[i].pos) {
      add(a[now], f[now]);
      now++;
    }
    t[i].f = query(t[i].val - 1);
  }
  memset(tr, 0, sizeof(tr));
  now = n;
  for (int i = m; i; i--) {
    while (now > t[i].pos) {
      add(cnt - a[now] + 1, g[now]);
      now--;
    }
    t[i].g = query(cnt - t[i].val);
    if (t[i].f + t[i].g + 1 > ans) Ans[t[i].id] = t[i].f + t[i].g + 1;
  }
  for (int i = 1; i <= m; i++) {
    if (Ans[t[i].id]) continue;
    if (f[t[i].pos] + g[t[i].pos] == ans + 1 && tim[f[t[i].pos]] == 1 &&
        t[i].f + t[i].g + 1 < ans)
      Ans[t[i].id] = ans - 1;
    else
      Ans[t[i].id] = ans;
  }
  for (int i = 1; i <= m; i++) printf("%d\n", Ans[i]);
  return 0;
}
