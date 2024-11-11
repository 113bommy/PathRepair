#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
const int inf = 0x3f3f3f3f;
int read() {
  int num = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
  return num * flag;
}
int n, m, k, cnt, tot, w, b, shit[M];
int du[M], f[M], fa[M], use[M], col[M];
struct edge {
  int v, next;
  edge(int V = 0, int N = 0) : v(V), next(N) {}
} e[2 * M];
int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
void uni(int u, int v) {
  int x = find(u), y = find(v);
  if (x == y) return;
  k--;
  fa[x] = y;
}
void fuck(int u, int c) {
  if (col[u] != -1) return;
  col[u] = c;
  if (c == 0)
    w++;
  else
    b++;
  for (int i = f[u]; i; i = e[i].next) fuck(e[i].v, c ^ 1);
}
void paint(int f) {
  w = b = 0;
  memset(col, -1, sizeof col);
  for (int i = 1; i <= n; i++)
    if (i == fa[i]) fuck(i, f);
}
int work2(int fl) {
  int mx = inf, t = 0;
  for (int i = 1; i <= n; i++)
    if (du[i] < mx && col[i] == fl && !use[i]) {
      t = i;
      mx = du[i];
    }
  int x = 2;
  memset(shit, 0, sizeof shit);
  for (int i = f[t]; i; i = e[i].next)
    if (col[e[i].v] == fl ^ 1) shit[e[i].v] = 1;
  for (int i = 1; i <= n; i++)
    if (!shit[i] && col[i] == fl ^ 1 && !use[i]) x--;
  if (x > 0) return 0;
  cnt++;
  x = 2;
  use[t] = cnt;
  for (int i = 1; i <= n; i++)
    if (!shit[i] && col[i] == fl ^ 1 && !use[i]) {
      use[i] = cnt;
      x--;
      if (x == 0) return 1;
    }
}
void print() {
  queue<int> q1, q2;
  for (int i = 1; i <= n; i++) {
    if (!use[i] && col[i] == 0) q1.push(i);
    if (!use[i] && col[i] == 1) q2.push(i);
  }
  while (!q1.empty()) {
    cnt++;
    for (int i = 0; i < 3; i++) {
      int t = q1.front();
      q1.pop();
      use[t] = cnt;
    }
  }
  while (!q2.empty()) {
    cnt++;
    for (int i = 0; i < 3; i++) {
      int t = q2.front();
      q2.pop();
      use[t] = cnt;
    }
  }
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d ", use[i]);
  exit(0);
}
void work() {
  cnt = 0;
  if (w % 3 == 1) {
    if (work2(0)) print();
    if (w >= 4 && work2(1) && work2(1)) print();
  } else {
    if (work2(1)) print();
    if (b >= 4 && work2(0) && work2(0)) print();
  }
}
signed main() {
  n = k = read();
  m = read();
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    e[++tot] = edge(v, f[u]), f[u] = tot;
    e[++tot] = edge(u, f[v]), f[v] = tot;
    du[u]++;
    du[v]++;
    uni(u, v);
  }
  paint(0);
  memset(use, 0, sizeof use);
  if (w % 3)
    work();
  else
    print();
  if (k == 2) {
    int x = 0;
    w = b = 0;
    memset(col, -1, sizeof col);
    for (int i = 1; i <= n; i++)
      if (i == fa[i]) {
        fuck(i, x);
        x ^= 1;
      }
    memset(use, 0, sizeof use);
    if (w % 3)
      work();
    else
      print();
  }
  puts("NO");
}
