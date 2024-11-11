#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
int dfn[300010], low[300010], stack[300010], head[300010], end[600010],
    nxt[600010];
int bel[300010], f[300010][21], min[300010], max[300010], lm[300010],
    root[300010], size[300010];
bool ins[300010];
int top = 0, idx = 0, cnt = 0, cou = 0;
void link(int a, int b) {
  nxt[++cou] = head[a];
  head[a] = cou;
  end[cou] = b;
}
int query(int l, int r) {
  int lg = log2(r - l + 1);
  return std::max(f[l][lg], f[r - (1 << lg) + 1][lg]);
}
void tarjan(int cur, int last) {
  dfn[cur] = low[cur] = ++idx;
  ins[cur] = true;
  stack[++top] = cur;
  for (int x = head[cur]; x != -1; x = nxt[x]) {
    if (end[x] == last) continue;
    if (dfn[end[x]] == -1) {
      tarjan(end[x], cur);
      if (low[end[x]] < low[cur]) low[cur] = low[end[x]];
    } else if (ins[end[x]] && dfn[end[x]] < low[cur])
      low[cur] = dfn[end[x]];
  }
  if (dfn[cur] == low[cur]) {
    cnt++;
    do {
      bel[stack[top]] = cnt;
      ins[stack[top]] = false;
    } while (stack[top--] != cur);
  }
}
struct President_Tree {
  int lc[6000000], rc[6000000], cou[6000000];
  long long sum[6000000];
  int cnt;
  void init() {
    cnt = 0;
    memset(lc, 0, sizeof(lc));
    memset(rc, 0, sizeof(rc));
  }
  inline void push_up(int cur) {
    sum[cur] = sum[lc[cur]] + sum[rc[cur]];
    cou[cur] = cou[lc[cur]] + cou[rc[cur]];
  }
  void build(int &cur, int l, int r) {
    cur = ++cnt;
    sum[cur] = 0;
    cou[cur] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lc[cur], l, mid);
    build(rc[cur], mid + 1, r);
  }
  void insert(int &cur, int last, int l, int r, int x, int c) {
    cur = ++cnt;
    if (l == r) {
      sum[cur] = sum[last] + c;
      cou[cur] = cou[last] + 1;
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
      rc[cur] = rc[last];
      insert(lc[cur], lc[last], l, mid, x, c);
    } else {
      lc[cur] = lc[last];
      insert(rc[cur], rc[last], mid + 1, r, x, c);
    }
    push_up(cur);
  }
  long long query(int cur, int last, int l, int r, int lim) {
    if (r <= lim)
      return (long long)(cou[cur] - cou[last]) * (long long)(lim);
    else if (l > lim)
      return (sum[cur] - sum[last]);
    int mid = (l + r) >> 1;
    return query(lc[cur], lc[last], l, mid, lim) +
           query(rc[cur], rc[last], mid + 1, r, lim);
  }
} t;
signed main() {
  memset(head, -1, sizeof(head));
  memset(dfn, -1, sizeof(dfn));
  int n = inp();
  int m = inp();
  for (int i = 1; i <= m; i++) {
    int u = inp();
    int v = inp();
    link(u, v);
    link(v, u);
  }
  for (int i = 1; i <= n; i++)
    if (dfn[i] == -1) tarjan(i, -1);
  memset(min, 0x3f, sizeof(min));
  for (int i = 1; i <= n; i++) {
    min[bel[i]] = std::min(min[bel[i]], i);
    max[bel[i]] = std::max(max[bel[i]], i);
    size[bel[i]]++;
  }
  for (int i = 1; i <= cnt; i++)
    if (size[i] >= 2) f[max[i]][0] = std::max(f[max[i]][0], min[i]);
  for (int j = 1; j <= 19; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
  t.init();
  t.build(root[0], 1, n);
  for (int i = 1; i <= n; i++) {
    int l = 1;
    int r = i;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (query(mid, i) >= mid)
        l = mid + 1;
      else
        r = mid;
    }
    t.insert(root[i], root[i - 1], 1, n, l, l);
  }
  int q = inp();
  while (q--) {
    int l = inp();
    int r = inp();
    std::cout << ((long long)(r) * (long long)(r + 1) >> 1) -
                     ((long long)(l - 1) * (long long)(l - 1 + 1) >> 1) -
                     t.query(root[r], root[l - 1], 1, n, l) + (r - l + 1)
              << std::endl;
  }
}
