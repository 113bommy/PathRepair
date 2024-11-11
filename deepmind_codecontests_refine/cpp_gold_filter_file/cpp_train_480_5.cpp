#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int SIZ = 500;
inline void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
struct note {
  int t;
  int next;
};
int cnt;
int head[N];
note e[N << 1];
inline void add(int x, int y) {
  e[++cnt].t = y;
  e[cnt].next = head[x];
  head[x] = cnt;
}
int n, m;
namespace tl {
int cnt;
int id[N], iid[N];
int fa[N];
int top[N], son[N], siz[N];
void dfs1(int p, int f) {
  fa[p] = f;
  siz[p] = 1;
  for (int i = head[p]; i + 1; i = e[i].next) {
    int t = e[i].t;
    if (t == f) {
      continue;
    }
    dfs1(t, p);
    siz[p] += siz[t];
    if (siz[t] > siz[son[p]]) {
      son[p] = t;
    }
  }
}
void dfs2(int p, int top_p) {
  id[p] = ++cnt;
  iid[cnt] = p;
  top[p] = top_p;
  if (son[p]) {
    dfs2(son[p], top_p);
  }
  for (int i = head[p]; i + 1; i = e[i].next) {
    int t = e[i].t;
    if (t == fa[p] || t == son[p]) {
      continue;
    }
    dfs2(t, t);
  }
}
int bol;
int idb[N];
int tag[N / SIZ + 10];
int l[N / SIZ + 10], r[N / SIZ + 10];
int col[N];
int sum[N / SIZ + 10][N << 1];
int t[N];
int a[N];
inline void input() {
  for (int i = 1; i <= n; i++) {
    read(t[i]);
    t[i]++;
  }
}
inline void init() {
  dfs1(1, -1);
  dfs2(1, 1);
  for (int i = 1; i <= n; i++) {
    idb[i] = (i - 1) / SIZ + 1;
    if (idb[i] != idb[i - 1]) {
      r[idb[i - 1]] = i - 1;
      l[idb[i]] = i;
    }
  }
  r[idb[n]] = n;
  for (int i = 1; i <= n; i++) {
    a[id[i]] = n - t[i];
  }
  for (int i = 1; i <= n; i++) {
    sum[idb[i]][a[i]]++;
  }
}
int ans;
inline void update(int l, int r, int val) {
  for (int i = l; i <= r; i++) {
    int o = idb[i];
    if (!col[i] && a[i] >= n - tag[o]) {
      ans--;
    }
    if (!col[i]) {
      sum[o][a[i]]--;
    }
    a[i] += val;
    if (!col[i]) {
      sum[o][a[i]]++;
    }
    if (!col[i] && a[i] >= n - tag[o]) {
      ans++;
    }
  }
}
inline void modify(int L, int R, int val) {
  int x = idb[L], y = idb[R];
  if (x == y) {
    update(L, R, val);
    return;
  }
  update(L, r[x], val);
  update(l[y], R, val);
  for (int i = x + 1; i <= y - 1; i++) {
    if (val == 1) {
      tag[i]++;
      ans += sum[i][n - tag[i]];
    } else {
      ans -= sum[i][n - tag[i]];
      tag[i]--;
    }
  }
}
inline void query(int x) {
  int val = (x > 0) ? 1 : -1;
  x = abs(x);
  col[id[x]] ^= 1;
  if (a[id[x]] >= n - tag[idb[id[x]]]) {
    ans -= val;
  }
  sum[idb[id[x]]][a[id[x]]] -= val;
  while (x + 1) {
    modify(id[top[x]], id[x], val);
    x = fa[top[x]];
  }
  printf("%d ", ans);
}
}  // namespace tl
int main() {
  memset(head, -1, sizeof(head));
  read(n), read(m);
  for (int i = 2; i <= n; i++) {
    int x;
    read(x);
    add(x, i);
    add(i, x);
  }
  tl::input();
  tl::init();
  for (int i = 1; i <= m; i++) {
    int x;
    read(x);
    tl::query(x);
  }
  puts("");
  return 0;
}
