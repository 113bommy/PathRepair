#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  char c = getchar();
  int tot = 1;
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    tot = -1;
    c = getchar();
  }
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * tot;
}
inline void wr(int x) {
  if (x < 0) {
    putchar('-');
    wr(-x);
    return;
  }
  if (x >= 10) wr(x / 10);
  putchar(x % 10 + '0');
}
inline void wrn(int x) {
  wr(x);
  putchar('\n');
}
inline void wri(int x) {
  wr(x);
  putchar(' ');
}
inline void wrn(int x, int y) {
  wri(x);
  wrn(y);
}
inline void wrn(int a, int b, int c) {
  wri(a);
  wrn(b, c);
}
int n, m, fa[500055], vis[500055], a[500055], b[500055], s1, s2, s, t,
    dis[500055], ans, rt, op;
vector<int> z;
int nedge, head[500055 * 2], to[500055 * 2], Next[500055 * 2];
void add(int a, int b) {
  Next[++nedge] = head[a];
  head[a] = nedge;
  to[nedge] = b;
}
void add_ne(int a, int b) {
  add(a, b);
  add(b, a);
}
void dfs(int x) {
  for (int i = head[x]; i; i = Next[i]) {
    if (to[i] == fa[x]) continue;
    fa[to[i]] = x;
    dis[to[i]] = dis[x] + 1;
    dfs(to[i]);
  }
}
int lca(int x, int y) {
  for (; x != y; x = fa[x])
    if (dis[x] < dis[y]) swap(x, y);
  return x;
}
void ret() {
  puts("-1");
  exit(0);
}
void check() {
  for (int i = (1); i <= (n); i++) {
    if (a[i] != b[i]) {
      if (dis[i] > dis[s]) s = i;
    }
  }
  if (s == 0) {
    wrn(0, ans);
    exit(0);
  }
  for (int i = s; vis[i] = 1, z.push_back(i), a[fa[i]] != b[fa[i]]; i = fa[i])
    ;
  for (int i = (1); i <= (n); i++)
    if (a[i] != b[i] && !vis[i]) t = dis[t] < dis[i] ? i : t;
  if (t) {
    reverse(z.begin(), z.end());
    for (int i = t; vis[i] = 1, z.push_back(i), a[fa[i]] != b[fa[i]]; i = fa[i])
      ;
  } else
    t = fa[z.back()];
  for (int i = (1); i <= (n); i++)
    if (a[i] != b[i] && !vis[i]) ret();
  rt = lca(s, t);
  if (z.size() != dis[s] + dis[t] - 2 * dis[rt]) ret();
}
void init() {
  n = read();
  for (int i = (1); i <= (n); i++) {
    a[i] = read();
    if (a[i] == 0) s1 = i;
  }
  for (int i = (1); i <= (n); i++) {
    b[i] = read();
    if (b[i] == 0) s2 = i;
  }
  for (int i = (1); i <= (n - 1); i++) add_ne(read(), read());
  dis[0] = -1;
  dfs(s2);
  ans = dis[s1];
  for (int i = s1; i != s2; i = fa[i]) swap(a[i], a[fa[i]]);
}
void work() {
  int p = 0;
  for (int i = (0); i <= (z.size() - 1); i++)
    if (b[z[i]] == a[z[0]]) p = i;
  for (int i = (1); i <= (z.size() - 1); i++)
    if (b[z[(i + p) % z.size()]] != a[z[i]]) ret();
  memset(vis, 0, sizeof(vis));
  for (int i = s1; i; i = fa[i]) vis[i] = 1;
  int cqz = 0;
  int wzp = z.size();
  if (vis[z[0]] || vis[z.back()]) {
    for (int i = (0); i <= (z.size() - 1); i++)
      if (!vis[z[i]]) {
        cqz = i;
        break;
      }
    ans += -cqz + min(cqz + p * (wzp + 1), abs((wzp - p) * (wzp + 1) - cqz));
  } else
    ans += min(p, wzp - p) * (wzp + 1);
  for (; !vis[rt]; rt = fa[rt]) ans += 2;
  if (s > t) swap(s, t);
  wrn(s, t, ans);
}
signed main() {
  init();
  check();
  work();
  return 0;
}
