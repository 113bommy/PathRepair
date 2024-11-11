#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x;
}
int n, head[maxn], cnt = 1;
double add[maxn], v[maxn];
struct edge {
  int to, next, id;
} e[maxn << 1];
inline void add_edge(int from, int to) {
  e[cnt].to = to;
  e[cnt].next = head[from];
  head[from] = cnt++;
  e[cnt].to = from;
  e[cnt].next = head[to];
  head[to] = cnt++;
}
void dfs(int x, int fa) {
  int c = (bool)fa;
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (y == fa) continue;
    dfs(y, x);
    ++c;
  }
  double t = 2.0 / c;
  int cur = 0;
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (y == fa) continue;
    ++cur;
    add[y] = cur * t;
  }
}
void get_val(int x, int fa, double tot) {
  if (tot > 2 - 1e-8) tot -= 2.0;
  v[x] = tot;
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (y == fa) continue;
    get_val(y, x, tot + add[y] + 1);
  }
}
void print(int x, int fa) {
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (y == fa) continue;
    if (v[y] < 1)
      printf("1 %d %d %d %.10lf\n", e[i].id, x, y, v[y]);
    else
      printf("1 %d %d %d %.10lf\n", e[i].id, y, x, v[y] - 1);
    print(y, x);
  }
}
int main() {
  n = read();
  printf("%d\n", n - 1);
  for (int i = 1; i < n; ++i) {
    int u = read(), v = read();
    e[cnt].id = i, e[cnt + 1].id = i;
    add_edge(u, v);
  }
  dfs(1, 0);
  get_val(1, 0, 0);
  print(1, 0);
  return 0;
}
