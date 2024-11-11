#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool read(T &x) {
  x = 0;
  bool f = 0;
  char ch;
  for (ch = getchar(); !isdigit(ch); ch = getchar()) {
    if (ch == EOF) return 0;
    f |= ch == '-';
  }
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  if (f) x = -x;
  return 1;
}
template <class T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(48 | x % 10);
}
template <class T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
template <class T>
inline void writespace(T x) {
  write(x);
  putchar(' ');
}
const string taskname = "";
long long n, m, len, s;
long long ans[400010], c[100010];
long long tot, h[100010], ver[200010], nxt[200010];
bool vis[100010];
inline void add(long long u, long long v) {
  ver[++tot] = v;
  nxt[tot] = h[u];
  h[u] = tot;
}
void dfs(long long u, long long fa) {
  vis[u] = 1;
  ans[++len] = u;
  c[u] ^= 1;
  for (register long long i = h[u]; i; i = nxt[i]) {
    long long v = ver[i];
    if (!vis[v]) {
      dfs(v, u);
      ans[++len] = u;
      c[u] ^= 1;
    }
  }
  if (c[u]) {
    ans[++len] = fa;
    ans[++len] = u;
    c[u] ^= 1;
    c[fa] ^= 1;
  }
}
signed main() {
  srand(20050210);
  read(n);
  read(m);
  while (m--) {
    long long u, v;
    read(u);
    read(v);
    add(u, v);
    add(v, u);
  }
  for (register long long i = 1; i <= n; ++i) {
    read(c[i]);
    if (c[i] == 1) s = i;
  }
  if (s) {
    dfs(s, 0);
    for (register long long i = 1; i <= n; ++i)
      if (!vis[i] && c[i]) {
        write(-1);
        return 0;
      }
  }
  if (len && ans[len] == 0) len -= 3;
  writeln(len);
  for (register long long i = 1; i <= len; ++i) writespace(ans[i]);
  return 0;
}
