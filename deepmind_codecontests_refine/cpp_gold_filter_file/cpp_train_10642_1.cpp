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
const int N = 200005, K = 20;
int a[N], b[N], st[N], dp[N][K], in[N], sp[N], SP[N], out[N], ti, dep[N], an[N],
    q[N << 2];
vector<int> v[N], e[N];
inline bool zx(int a, int b) { return in[a] <= in[b] && out[a] >= out[b]; }
void dfs(int p, int fa) {
  dp[p][0] = fa;
  in[p] = ++ti;
  dep[p] = dep[fa] + 1;
  for (auto i : v[p])
    if (i != fa) {
      dfs(i, p);
    }
  out[p] = ti;
}
int lca(int x, int y) {
  if (zx(x, y)) return x;
  for (int i = (int)(K - 1); i >= (int)(0); i--)
    if (dp[x][i] && !zx(dp[x][i], y)) x = dp[x][i];
  return dp[x][0];
}
int dis(int x, int y) {
  int t = lca(x, y);
  return dep[x] + dep[y] - dep[t] * 2;
}
int chu(int x, int y) { return (x + y - 1) / y; }
int cmp(int x, int y, int t) {
  if (!x || !y) return x | y;
  int X = chu(dis(x, t), sp[x]), Y = chu(dis(y, t), sp[y]);
  if (X != Y)
    return X < Y ? x : y;
  else
    return SP[x] < SP[y] ? x : y;
}
void d1(int p) {
  for (auto i : e[p]) {
    d1(i);
    an[p] = cmp(an[i], an[p], p);
  }
}
void d2(int p) {
  for (auto i : e[p]) {
    an[i] = cmp(an[p], an[i], i);
    d2(i);
  }
}
bool cm(int a, int b) { return in[a] < in[b]; }
int main() {
  int n = read();
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int s = read(), t = read();
    v[s].push_back(t);
    v[t].push_back(s);
  }
  dfs(1, 0);
  for (int i = (int)(1); i <= (int)(K - 1); i++)
    for (int j = (int)(1); j <= (int)(n); j++)
      dp[j][i] = dp[dp[j][i - 1]][i - 1];
  int Q = read();
  while (Q--) {
    int k = read(), m = read(), tot = 1;
    q[1] = 1;
    for (int i = (int)(1); i <= (int)(k); i++) {
      a[i] = read();
      sp[a[i]] = read();
      SP[a[i]] = i;
      an[a[i]] = a[i];
      q[++tot] = a[i];
    }
    for (int i = (int)(1); i <= (int)(m); i++) {
      b[i] = read();
      q[++tot] = b[i];
    }
    sort(q + 1, q + tot + 1, cm);
    for (int i = (int)(tot - 1); i >= (int)(1); i--)
      q[++tot] = lca(q[i], q[i + 1]);
    sort(q + 1, q + tot + 1, cm);
    tot = unique(q + 1, q + tot + 1) - q - 1;
    int top = 1;
    st[1] = 1;
    for (int i = (int)(2); i <= (int)(tot); i++) {
      while (!zx(st[top], q[i])) top--;
      e[st[top]].push_back(q[i]);
      st[++top] = q[i];
    }
    d1(1);
    d2(1);
    for (int i = (int)(1); i <= (int)(m); i++) wri(SP[an[b[i]]]);
    puts("");
    for (int i = (int)(1); i <= (int)(tot); i++) {
      an[q[i]] = 0;
      e[q[i]].clear();
    }
  }
}
