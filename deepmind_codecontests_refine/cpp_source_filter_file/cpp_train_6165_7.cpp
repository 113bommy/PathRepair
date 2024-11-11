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
const int N = 805, inf = 1e9, M = 22;
int n, m, lst[N], v[N], u[N], zb[M][M];
struct graph1 {
  int fa[N / 2];
  void init() {
    for (int i = (int)(0); i <= (int)(n - 1); i++) {
      fa[i] = i;
    }
  }
  inline int gf(int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }
  void ins(int s, int t) {
    s = gf(s);
    t = gf(t);
    fa[s] = t;
  }
  bool check(int s, int t) {
    s = gf(s);
    t = gf(t);
    return s != t;
  }
} G1, G3;
struct graph2 {
  int d[N / 2];
  void init() {
    for (int i = (int)(0); i <= (int)(n - 1); i++) d[i] = 0;
  }
  void ins(int s, int t) { d[s]++; }
  bool check(int s, int t) { return d[s] < 2; }
} G2;
int used[N], dis[N], vis[N];
vector<int> e[N];
char ans[M * 2][M * 2], ch[M][M];
int spfa(int s, int t) {
  for (int i = (int)(1); i <= (int)(t); i++) {
    dis[i] = inf;
    vis[i] = 0;
  }
  queue<int> q;
  q.push(s);
  dis[s] = 0;
  while (q.size()) {
    int t = q.front();
    q.pop();
    vis[t] = 0;
    for (auto i : e[t]) {
      int di = dis[t] + 1;
      if (dis[i] == inf) {
        lst[i] = t;
        dis[i] = di;
        if (!vis[i]) {
          vis[i] = 1;
          q.push(i);
        }
      }
    }
  }
  return dis[t];
}
int solve() {
  int s = m + 1, t = s + 1;
  for (int i = (int)(1); i <= (int)(t); i++) e[i].clear();
  for (int i = (int)(1); i <= (int)(m); i++)
    if (used[i]) {
      G1.init();
      G2.init();
      for (int j = (int)(1); j <= (int)(m); j++)
        if (used[j] && j != i) {
          G1.ins(u[j], v[j]);
          G2.ins(u[j], v[j]);
        }
      for (int j = (int)(1); j <= (int)(m); j++)
        if (!used[j]) {
          if (G1.check(u[j], v[j])) e[i].push_back(j);
          if (G2.check(u[j], v[j])) e[j].push_back(i);
        }
    }
  G1.init();
  G2.init();
  for (int i = (int)(1); i <= (int)(m); i++)
    if (used[i]) {
      G1.ins(u[i], v[i]);
      G2.ins(u[i], v[i]);
    }
  for (int i = (int)(1); i <= (int)(m); i++)
    if (!used[i]) {
      if (G1.check(u[i], v[i])) e[s].push_back(i);
      if (G2.check(u[i], v[i])) e[i].push_back(t);
    }
  int zs = spfa(s, t);
  if (zs < inf) {
    for (int i = lst[t]; i != s; i = lst[i]) {
      used[i] ^= 1;
    }
    return 1;
  }
  return 0;
}
int main() {
  int T = read();
  while (T--) {
    int r = read(), c = read();
    n = 0;
    m = 0;
    memset((used), 0, sizeof(used));
    for (int i = (int)(0); i <= (int)(r - 1); i++) scanf("%s", ch[i]);
    for (int i = (int)(0); i <= (int)(r - 1); i++)
      for (int j = (int)(0); j <= (int)(c - 1); j++) zb[i][j] = n++;
    ch[0][0] = 'X';
    int lim = 0;
    for (int i = (int)(0); i <= (int)(r - 1); i++)
      for (int j = (int)(0); j <= (int)(c - 1); j++)
        if (ch[i][j] == 'O' && (i + j) % 2 == 0) lim++;
    for (int i = (int)(0); i <= (int)(r - 1); i++) {
      for (int j = (int)(0); j <= (int)(c - 2); j++)
        if (ch[i][j] == 'O' && ch[i][j + 1] == 'O') {
          m++;
          u[m] = zb[i][j];
          v[m] = zb[i][j + 1];
          if ((i + j) & 1) swap(u[m], v[m]);
        }
      if (i < r - 1)
        for (int j = (int)(0); j <= (int)(c - 1); j++)
          if (ch[i][j] == 'O' && ch[i + 1][j] == 'O') {
            m++;
            u[m] = zb[i][j];
            v[m] = zb[i + 1][j];
            if ((i + j) & 1) swap(u[m], v[m]);
          }
    }
    lim *= 2;
    while (solve()) lim--;
    if (lim) {
      puts("NO");
      continue;
    }
    ch[0][0] = 'O';
    if (ch[0][1] == 'O') {
      m++;
      u[m] = zb[0][0];
      v[m] = zb[0][1];
    }
    if (ch[1][0] == 'O') {
      m++;
      u[m] = zb[0][0];
      v[m] = zb[0][1];
    }
    for (int i = (int)(0); i <= (int)(n - 1); i++) G3.fa[i] = i;
    for (int i = (int)(1); i <= (int)(m); i++)
      if (used[i]) G3.ins(u[i], v[i]);
    for (int i = (int)(1); i <= (int)(m); i++)
      if (!used[i]) {
        if (G3.check(u[i], v[i])) {
          G3.ins(u[i], v[i]);
          used[i] = 1;
        }
      }
    for (int i = (int)(0); i <= (int)(2 * r - 2); i++) {
      for (int j = (int)(0); j <= (int)(2 * c - 2); j++) {
        ans[i][j] = ' ';
        if (i % 2 == 0 && j % 2 == 0) ans[i][j] = ch[i / 2][j / 2];
      }
      ans[i][2 * c - 1] = 0;
    }
    for (int i = (int)(1); i <= (int)(m); i++)
      if (used[i]) {
        if (u[i] > v[i]) swap(u[i], v[i]);
        int x = u[i] / c, y = u[i] % c;
        if (v[i] == u[i] + 1)
          ans[x * 2][y * 2 + 1] = 'O';
        else
          ans[x * 2 + 1][y * 2] = 'O';
      }
    puts("YES");
    for (int i = (int)(0); i <= (int)(2 * r - 2); i++) puts(ans[i]);
  }
}
