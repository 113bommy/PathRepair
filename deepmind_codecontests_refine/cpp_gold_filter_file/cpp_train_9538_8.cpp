#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
inline char Getchar() {
  static char buffer[10 << 20], *T, *S = T;
  return S == T        ? T = buffer + fread(S = buffer, 1, 10 << 20, stdin),
                  *S++ : *S++;
}
char Output[50 << 20], *S = Output;
inline int Getint() {
  int x = 0, f = 1;
  char ch = Getchar();
  while (!isdigit(ch)) ch != '-' ?: f = -1, ch = Getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = Getchar();
  return x * f;
}
int n, m, h[N];
struct edge {
  int to, next;
} e[N];
void addedge(int x, int y) {
  static int cnt;
  e[++cnt] = (edge){y, h[x]};
  h[x] = cnt;
}
int sign, dep[N], prt[N], son[N], size[N], top[N], bot[N], dfn[N];
void dfs1(int x, int fa) {
  dep[x] = dep[fa] + 1;
  prt[x] = fa;
  size[x] = 1;
  for (int i = h[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (y == fa) continue;
    dfs1(y, x);
    size[x] += size[y];
    if (size[y] > size[son[x]]) son[x] = y;
  }
}
void dfs2(int x, int tp) {
  top[x] = tp;
  dfn[x] = ++sign;
  if (son[x])
    dfs2(son[x], tp), bot[x] = bot[son[x]];
  else
    bot[x] = x;
  for (int i = h[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (y == prt[x] || y == son[x]) continue;
    dfs2(y, y);
  }
}
struct BIT {
  long long tr[N];
  inline void add(int x, int val) {
    for (int i = x; i <= n; i += i & -i) tr[i] += val;
  }
  inline long long ask(int x) {
    long long ans = 0;
    for (int i = x; i; i -= i & -i) ans += tr[i];
    return ans;
  }
} T1;
struct BIT2 {
  int tr[N];
  inline void add(int x, int val) {
    for (int i = x; i <= n; i += i & -i) tr[i] += val;
  }
  inline int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= i & -i) ans += tr[i];
    return ans;
  }
} T2;
int id[N];
inline void ins(int x) {
  while (x) {
    T1.add(dfn[top[x]], dfn[top[x]]);
    T1.add(dfn[x] + 1, -dfn[x] - 1);
    T1.add(dfn[bot[x]] + 1, dfn[x] + 1 - dfn[top[x]]);
    T2.add(dfn[top[x]], 1);
    T2.add(dfn[x] + 1, -1);
    x = prt[top[x]];
  }
}
inline long long ask(int x) {
  long long ans = 0;
  while (x) {
    ans += (dfn[x] + 1ll) * T2.ask(dfn[x]) - T1.ask(dfn[x]);
    x = prt[top[x]];
  }
  return ans;
}
inline void putint(long long x) {
  if (x < 10)
    *S++ = '0' + x;
  else
    putint(x / 10), *S++ = '0' + x % 10;
}
int main() {
  n = Getint();
  int rt = 0;
  for (int i = 1; i <= n; i++) {
    int fa = Getint();
    if (!fa)
      rt = i;
    else
      addedge(fa, i);
  }
  dfs1(rt, 0);
  dfs2(rt, rt);
  for (int i = 1; i <= n; i++) id[i] = i;
  sort(id + 1, id + n + 1,
       [](const int& x, const int& y) { return dep[x] < dep[y]; });
  static long long ans[N];
  for (int l = 1, r; l <= n; l = r + 1) {
    r = l;
    while (r < n && dep[id[r + 1]] == dep[id[l]]) r++;
    for (int i = l; i <= r; i++) ins(id[i]);
    for (int i = l; i <= r; i++) ans[id[i]] = ask(id[i]) - dep[id[i]];
  }
  for (int i = 1; i <= n; i++) putint(ans[i]), *S++ = ' ';
  fwrite(Output, 1, S - Output, stdout);
}
