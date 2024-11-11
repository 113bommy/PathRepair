#include <bits/stdc++.h>
char ch;
inline void read(int &x) {
  x = 0;
  ch = getchar();
  while (ch <= 32) ch = getchar();
  while (ch > 32) x = x * 10 + ch - 48, ch = getchar();
};
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
int n, q;
char a[100005];
int next[100005], prev[100005];
inline void del(int x) {
  next[prev[x]] = next[x];
  prev[next[x]] = prev[x];
};
struct data {
  int a[10];
};
data ans[(100005 * 20)];
int pos[(100005 * 20)];
int opcnt;
int first[100005];
inline void pre() {
  data now_ans = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  int maxr = 0;
  while (maxr < n) {
    int startl = maxr + 1;
    int now = startl;
    prev[startl] = startl - 1;
    next[startl - 1] = startl;
    bool last_type = 0;
    int lastpos = 0;
    bool dir = 1;
    first[startl] = opcnt + 1;
    while (1) {
      ans[++opcnt] = now_ans;
      pos[opcnt] = now;
      if (!first[now]) first[now] = opcnt;
      maxr = max(maxr, now);
      if (now > n || now < startl) break;
      if (a[now] > '0' && a[now] <= '9') {
        int t = a[now] - '0';
        ++now_ans.a[t];
        --a[now];
        last_type = 0;
      } else if (a[now] == '0') {
        ++now_ans.a[0];
        del(now);
        last_type = 0;
      } else if (a[now] == '>') {
        if (last_type) del(lastpos);
        dir = 1;
        last_type = 1;
      } else {
        if (last_type) del(lastpos);
        dir = 0;
        last_type = 1;
      };
      lastpos = now;
      now = dir ? next[now] : prev[now];
    };
  };
};
struct edge {
  edge *next;
  int r, id;
};
edge *se[100005], e[100005], *etot = e;
inline void addedge(int l, int r, int id) {
  *++etot = (edge){se[l], r, id};
  se[l] = etot;
};
data _ans[100005];
int T[(1 << 17) << 1];
inline void modify(int x, int val) {
  T[x += (1 << 17) + 1] = val;
  while (x ^ 1) T[x >> 1] = min(T[x], T[x ^ 1]), x >>= 1;
};
inline int query(int l, int r) {
  int ret = 0x3f3f3f3f;
  l += (1 << 17);
  r += (1 << 17) + 2;
  while (l ^ r ^ 1) {
    if (~l & 1) ret = min(ret, T[l ^ 1]);
    if (r & 1) ret = min(ret, T[r ^ 1]);
    l >>= 1;
    r >>= 1;
  };
  return ret;
};
inline void solve() {
  memset(T, 0x3f, sizeof(T));
  first[n + 1] = opcnt + 1;
  int i, j;
  for (i = n; i >= 1; i--) {
    int _l = first[i];
    for (j = first[i + 1] - 1; j >= _l; j--) {
      int p = pos[j];
      modify(p, j);
    };
    edge *te = se[i];
    while (te) {
      int r = te->r;
      int p = min(query(0, i - 1), query(r + 1, n + 1));
      int p0 = first[i];
      int id = te->id;
      for (j = 0; j < 10; j++) {
        _ans[id].a[j] = ans[p].a[j] - ans[p0].a[j];
      };
      te = te->next;
    };
  };
  for (i = 1; i <= q; i++) {
    for (j = 0; j < 10; j++) printf("%d ", _ans[i].a[j]);
    puts("");
  };
};
int main() {
  read(n);
  read(q);
  int i;
  scanf("%s", a + 1);
  for (i = 1; i <= n; i++) next[i] = i + 1, prev[i] = i - 1;
  next[0] = 1;
  prev[n + 1] = n;
  pre();
  for (i = 1; i <= q; i++) {
    int l, r;
    read(l);
    read(r);
    addedge(l, r, i);
  };
  solve();
}
