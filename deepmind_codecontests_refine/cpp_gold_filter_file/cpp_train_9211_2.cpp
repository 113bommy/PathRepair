#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 200005, M = N << 1, K = 18;
vector<int> v[N];
int cnt, ti, color, ne = 1, top;
int dp[N][K], q[N], col[N], in[N], out[N], dfn[N], low[N], to[N], son[N], ed[M],
    nxt[M];
void GG() {
  puts("No");
  exit(0);
}
void ae(int a, int b) {
  nxt[++ne] = son[a];
  son[a] = ne;
  ed[ne] = b;
}
struct data {
  int s[N];
  void add(int a, int b) {
    s[a]++;
    s[b]--;
  }
  void solve(int p, int fa) {
    for (auto i : v[p])
      if (i != fa) {
        solve(i, p);
        s[p] += s[i];
      }
  }
} T[2];
void dfs(int p, int fa) {
  q[++top] = p;
  dfn[p] = low[p] = ++ti;
  for (int i = son[p]; i; i = nxt[i])
    if (i != (fa ^ 1)) {
      int v = ed[i];
      if (!dfn[v]) {
        dfs(v, i);
        low[p] = min(low[p], low[v]);
      } else
        low[p] = min(low[p], dfn[v]);
    }
  if (dfn[p] == low[p]) {
    cnt++;
    while (1) {
      to[q[top]] = cnt;
      if (q[top--] == p) break;
    }
  }
}
void ddd(int p, int fa) {
  col[p] = color;
  dp[p][0] = fa;
  in[p] = ++ti;
  for (auto i : v[p])
    if (i != fa) ddd(i, p);
  out[p] = ti;
}
bool zx(int a, int b) { return in[a] <= in[b] && out[a] >= out[b]; }
int get(int a, int b) {
  if (zx(a, b)) return a;
  for (int i = (int)(K - 1); i >= (int)(0); i--)
    if (dp[a][i] && !zx(dp[a][i], b)) a = dp[a][i];
  return dp[a][0];
}
int main() {
  int n = read(), m = read(), q = read();
  for (int i = (int)(1); i <= (int)(m); i++) {
    int s = read(), t = read();
    ae(s, t);
    ae(t, s);
  }
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!dfn[i]) dfs(1, 0);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = son[i]; j; j = nxt[j])
      if (to[i] != to[ed[j]]) v[to[i]].push_back(to[ed[j]]);
  for (int i = (int)(1); i <= (int)(cnt); i++)
    if (!col[i]) {
      color++;
      ddd(i, 0);
    }
  for (int i = (int)(1); i <= (int)(K - 1); i++)
    for (int j = (int)(1); j <= (int)(cnt); j++)
      dp[j][i] = dp[dp[j][i - 1]][i - 1];
  while (q--) {
    int u = to[read()], v = to[read()];
    if (col[u] != col[v]) GG();
    int lca = get(u, v);
    T[0].add(u, lca);
    T[1].add(v, lca);
  }
  for (int i = (int)(0); i <= (int)(1); i++) T[i].solve(1, 0);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (T[0].s[i] && T[1].s[i]) GG();
  puts("Yes");
}
