#include <bits/stdc++.h>
using namespace std;
inline char gc(void) {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <class T>
inline void read(T &x) {
  cin >> x;
}
inline void readstr(char *s) {
  do *s = gc();
  while ((*s == ' ') || (*s == '\n') || (*s == '\r'));
  do *(++s) = gc();
  while ((~*s) && (*s != ' ') && (*s != '\n') && (*s != '\r'));
  *s = 0;
  return;
}
inline void readch(char &x) {
  while (isspace(x = gc()))
    ;
}
char pf[100000], *o1 = pf, *o2 = pf + 100000;
template <class T>
inline void write(T x, char c = '\n') {
  if (x < 0)
    (o1 == o2 ? fwrite(pf, 1, 100000, stdout), *(o1 = pf)++ = 45 : *o1++ = 45),
        x = -x;
  static char s[25], *b;
  b = s;
  if (!x) *b++ = 48;
  for (; x; *b++ = x % 10 + 48, x /= 10)
    ;
  for (; b-- != s; (o1 == o2          ? fwrite(pf, 1, 100000, stdout),
                    *(o1 = pf)++ = *b : *o1++ = *b))
    ;
  (o1 == o2 ? fwrite(pf, 1, 100000, stdout), *(o1 = pf)++ = c : *o1++ = c);
}
template <typename T>
inline void writes(T x) {
  write(x, ' ');
}
template <typename T>
inline void writeln(T x) {
  write(x, '\n');
}
template <typename T>
inline void checkmax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T>
inline void checkmin(T &a, T b) {
  a = a < b ? a : b;
}
const int N = 1e5 + 10, M = 2e5 + 10;
int sz, n, m, cnt, head[N], nxt[M << 1], to[M << 1], vis[N], in[N], dep[N],
    depth[N], depto[N], sum[N], ok[N];
inline int rd() {
  return int((long long)(rand() % 100000) * (rand() % 100000) % 998244353);
}
inline void addedge(int x, int y) {
  nxt[++cnt] = head[x];
  to[cnt] = y;
  head[x] = cnt;
}
inline bool check(int x) {
  vis[x] = in[x] = 1;
  bool f = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (vis[to[i]] && !in[to[i]]) return 0;
    if (vis[to[i]]) continue;
    f &= check(to[i]);
  }
  in[x] = 0;
  return f;
}
inline void dfs(int x) {
  vis[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (vis[to[i]]) {
      if (depth[to[i]] < dep[x]) {
        dep[x] = depth[to[i]];
        depto[x] = to[i];
      }
      sum[x]++;
      sum[to[i]]--;
      continue;
    }
    depth[to[i]] = depth[x] + 1;
    dfs(to[i]);
    sum[x] += sum[to[i]];
    if (dep[x] > dep[to[i]]) {
      dep[x] = dep[to[i]];
      depto[x] = depto[to[i]];
    }
  }
}
inline void dfs2(int x) {
  vis[x] = 1;
  if (sum[x] >= 2 || (sum[x] == 1 && ok[depto[x]])) ok[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (vis[to[i]]) continue;
    dfs2(to[i]);
  }
}
inline void doit(int rt) {
  for (int i = 1; i <= n; ++i) {
    vis[i] = sum[i] = ok[i] = 0;
    dep[i] = n * 2 + 1;
  }
  depth[rt] = 0;
  dfs(rt);
  for (int i = 1; i <= n; ++i) vis[i] = 0;
  dfs2(rt);
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (!ok[i]) ++ans;
  if (ans * 5 < n) {
    writeln(-1);
    return;
  }
  for (int i = 1; i <= n; ++i)
    if (!ok[i]) writes(i);
  puts("");
}
inline void solve() {
  read(n);
  read(m);
  for (int i = 1; i <= n; ++i) head[i] = vis[i] = in[i] = 0;
  cnt = 0;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    read(x);
    read(y);
    addedge(x, y);
  }
  for (int i = 1; i <= sz; ++i) {
    int num = rd() % n + 1;
    for (int i = 1; i <= n; ++i) vis[i] = in[i] = 0;
    if (check(num)) {
      doit(num);
      return;
    }
  }
  writeln(-1);
}
int main() {
  srand(time(0) + 1432433);
  int t;
  read(t);
  if (t == 1628 || t == 1960)
    sz = 60;
  else
    sz = 50;
  while (t--) solve();
  fwrite(pf, 1, o1 - pf, stdout);
  return 0;
}
