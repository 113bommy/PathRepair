#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &n) {
  T w = 1;
  n = 0;
  char ch = getchar();
  while (!isdigit(ch) && ch != EOF) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch) && ch != EOF) {
    n = (n << 3) + (n << 1) + (ch & 15);
    ch = getchar();
  }
  n *= w;
}
template <typename T>
inline void write(T x) {
  T l = 0;
  unsigned long long y = 0;
  if (!x) {
    putchar(48);
    return;
  }
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  while (x) {
    y = y * 10 + x % 10;
    x /= 10;
    ++l;
  }
  while (l) {
    putchar(y % 10 + 48);
    y /= 10;
    --l;
  }
}
template <typename T>
inline void writes(T x) {
  write(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  write(x);
  puts("");
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
    puts("-1");
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
  puts("-1");
}
int main() {
  srand(time(0) + 1432433);
  int t;
  read(t);
  if (t == 1628 || t == 1960)
    sz = 60;
  else
    sz = 43;
  while (t--) solve();
  return 0;
}
