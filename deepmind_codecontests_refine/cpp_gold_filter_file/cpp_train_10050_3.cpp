#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, K, ans;
int sta[N], top, nxt[N];
struct node {
  int to, next;
} e[N << 1];
int head[N], cnt;
long long g[N], w[N], pre[N], suf[N];
inline void add(int x, int y) {
  e[cnt] = (node){y, head[x]};
  head[x] = cnt++;
}
long long mp[N << 2], sp[N << 2], ms[N << 2], tag[N << 2];
inline void upd(int rt, long long v) { tag[rt] += v, ms[rt] += v, sp[rt] += v; }
inline void PushDown(int rt) {
  if (tag[rt]) upd(rt << 1, tag[rt]), upd(rt << 1 | 1, tag[rt]), tag[rt] = 0;
}
long long calc(long long t, int l, int r, int rt) {
  if (l == r) return t + mp[rt];
  PushDown(rt);
  int m = (l + r) >> 1;
  if (ms[rt << 1] >= t) return min(calc(t, l, m, rt << 1), sp[rt]);
  return min(t + mp[rt << 1], calc(t, m + 1, r, rt << 1 | 1));
}
inline void PushUp(int l, int r, int rt) {
  ms[rt] = max(ms[rt << 1], ms[rt << 1 | 1]);
  int m = (l + r) >> 1;
  sp[rt] = calc(ms[rt << 1], m + 1, r, rt << 1 | 1);
}
void build(int l, int r, int rt) {
  if (l == r) return ms[rt] = suf[l], mp[rt] = -suf[l], void();
  int m = (l + r) >> 1;
  build(l, m, rt << 1), build(m + 1, r, rt << 1 | 1), PushUp(l, r, rt),
      mp[rt] = min(mp[rt << 1], mp[rt << 1 | 1]);
}
void Update(int L, int R, long long v, int l, int r, int rt) {
  if (L > R) return;
  if (L <= l && r <= R) return upd(rt, v);
  PushDown(rt);
  int m = (l + r) >> 1;
  if (L <= m) Update(L, R, v, l, m, rt << 1);
  if (m < R) Update(L, R, v, m + 1, r, rt << 1 | 1);
  PushUp(l, r, rt);
}
int solve(long long t, int l, int r, int rt) {
  if (l == r) return t + mp[rt] <= K ? l : 0;
  PushDown(rt);
  int m = (l + r) >> 1;
  if (t + mp[rt << 1 | 1] <= K) return solve(t, m + 1, r, rt << 1 | 1);
  return solve(t, l, m, rt << 1);
}
int query(long long t, int l, int r, int rt) {
  if (l == r) return t + mp[rt] <= K ? l : 0;
  PushDown(rt);
  int m = (l + r) >> 1;
  if (ms[rt << 1] >= t)
    if (sp[rt] <= K)
      return query(ms[rt << 1], m + 1, r, rt << 1 | 1);
    else
      return query(t, l, m, rt << 1);
  else
    return max(solve(t, l, m, rt << 1), query(t, m + 1, r, rt << 1 | 1));
}
void dfs(int x) {
  sta[++top] = x;
  if (x != n + 1) {
    Update(1, x - 1, -1e17, 1, n, 1),
        Update(nxt[x] - 1, n, pre[x - 1] - pre[nxt[x] - 1], 1, n, 1);
    int l = 1, r = top;
    while (l < r) {
      int m = (l + r) >> 1;
      if (pre[x - 1] - pre[sta[m] - 1] <= K)
        r = m;
      else
        l = m + 1;
    }
    Update(sta[r - 1], n, 1e17, 1, n, 1);
    ans = max(ans, query(-1e17, 1, n, 1) - x + 1);
    Update(1, x - 1, 1e17, 1, n, 1), Update(sta[r - 1], n, -1e17, 1, n, 1);
  }
  for (int i = head[x]; i != -1; i = e[i].next) dfs(e[i].to);
  if (x != n + 1)
    Update(nxt[x] - 1, n, -(pre[x - 1] - pre[nxt[x] - 1]), 1, n, 1);
  top--;
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &K);
  for (int i = 1; i < n; i++) scanf("%lld", &w[i]);
  w[n] = 1e17;
  for (int i = 1; i <= n; i++)
    scanf("%lld", &g[i]), pre[i] = pre[i - 1] + g[i] - w[i],
                          suf[i] = suf[i - 1] + g[i] - w[i - 1];
  sta[top = 0] = n;
  for (int i = n - 1; ~i; i--) {
    while (top && pre[sta[top]] >= pre[i]) top--;
    nxt[i + 1] = sta[top] + 1, add(nxt[i + 1], i + 1);
    sta[++top] = i;
  }
  build(1, n, 1), top = 0, dfs(n + 1), printf("%d\n", ans);
}
