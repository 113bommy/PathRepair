#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T1, class T2>
inline void print(T1 x1, T2 x2) {
  printsp(x1), println(x2);
}
template <class T1, class T2, class T3>
inline void print(T1 x1, T2 x2, T3 x3) {
  printsp(x1), printsp(x2), println(x3);
}
template <class T1, class T2, class T3, class T4>
inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {
  printsp(x1), printsp(x2), printsp(x3), println(x4);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int a[55], b[55], c[55];
int L[55], R[55];
int first[55], second[55], d[55];
int V, E, src, tar;
int head[20000], work[20000], dis[20000];
int to[400000], cap[400000], nxt[400000];
int q[20000], qf, qb;
void init(int n, int s, int t) {
  memset(head, -1, sizeof(int) * n);
  V = n;
  E = 0;
  src = s;
  tar = t;
}
void add_edge(int u, int v, int c) {
  to[E] = v;
  cap[E] = c;
  nxt[E] = head[u];
  head[u] = E++;
  to[E] = u;
  cap[E] = 0;
  nxt[E] = head[v];
  head[v] = E++;
}
bool bfs() {
  memset(dis, -1, sizeof(dis));
  qf = qb = 0;
  q[qb++] = src;
  dis[src] = 0;
  while (qf < qb && dis[tar] == -1) {
    int u = q[qf++];
    for (int i = head[u]; i >= 0; i = nxt[i]) {
      int v = to[i];
      if (dis[v] == -1 && cap[i] > 0) {
        dis[v] = dis[u] + 1;
        q[qb++] = v;
      }
    }
  }
  return dis[tar] >= 0;
}
int dfs(int u, int &bot) {
  int v, bot1, delta;
  if (u == tar) return bot;
  for (int &i = work[u]; i >= 0; i = nxt[i]) {
    int v = to[i];
    if (dis[v] != dis[u] + 1 || cap[i] == 0) continue;
    bot1 = min(bot, cap[i]);
    if (delta = dfs(v, bot1)) {
      cap[i] -= delta;
      cap[i ^ 1] += delta;
      bot = bot1;
      return delta;
    }
  }
  return 0;
}
int dinic() {
  int ans = 0, delta, bot;
  while (bfs()) {
    memcpy(work, head, sizeof(int) * V);
    while (delta = dfs(src, bot = 0x3f3f3f3f)) ans += delta;
  }
  return ans;
}
int main() {
  int n, m;
  gn(n, m);
  init(n * 202 + 10, 0, n * 202 + 1);
  for (int i = 1; i <= n; i++) {
    gn(a[i], b[i], c[i]);
  }
  for (int i = 1; i <= n; i++) {
    gn(L[i], R[i]);
  }
  for (int i = 0; i < m; i++) {
    gn(first[i], second[i], d[i]);
  }
  int mx = 20000000;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 201; j++) {
      if (j >= L[i] + 101 && j <= R[i] + 101)
        add_edge(i + n * (j - 1), i + n * j,
                 mx - (a[i] * (j - 101) * (j - 101) + b[i] * (j - 101) + c[i]));
      else
        add_edge(i + n * (j - 1), i + n * j, 0x3f3f3f3f);
    }
    add_edge(src, i, 0x3f3f3f3f);
    add_edge(i + 201 * n, tar, 0x3f3f3f3f);
  }
  for (int i = 0; i < m; i++) {
    for (int j = max(1, d[i]); j <= 201; j++) {
      int k = j - d[i];
      if (k < 0 || k > 201) continue;
      add_edge(first[i] + n * j, second[i] + n * k, 0x3f3f3f3f);
    }
  }
  println(-dinic() + n * mx);
  return 0;
}
