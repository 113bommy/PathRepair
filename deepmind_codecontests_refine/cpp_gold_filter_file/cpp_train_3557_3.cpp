#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
template <class T>
inline void umin(T &x, T y) {
  x = x < y ? x : y;
}
template <class T>
inline void umax(T &x, T y) {
  x = x > y ? x : y;
}
inline unsigned int R() {
  static unsigned int seed = 416;
  return seed ^= seed >> 5, seed ^= seed << 17, seed ^= seed >> 13;
}
const int N = 233333;
int rt, n, val[N], fa[N];
vector<int> e[N];
map<int, int> Map[N];
struct node {
  int x, y, z;
} ans[N];
int len;
void dfs(int u, int Fa) {
  fa[u] = Fa;
  for (register int i = (0); i <= (((int)e[u].size()) - 1); i++)
    if (e[u][i] != Fa) dfs(e[u][i], u);
  val[u] = Map[u][Fa];
}
void find(int u, int fa, int &x) {
  if (((int)e[u].size()) == 1) {
    x = u;
  }
  for (register int i = (0); i <= (((int)e[u].size()) - 1); i++)
    if (e[u][i] != fa) find(e[u][i], u, x);
}
void dfs1(int u) {
  for (register int i = (0); i <= (((int)e[u].size()) - 1); i++)
    if (e[u][i] != fa[u]) dfs1(e[u][i]);
  if (((int)e[u].size()) == 1) {
    if (val[u]) {
      ans[++len] = (node){u, rt, -val[u]};
      int x = -val[u];
      for (int d = u; d != rt; d = fa[d]) val[d] += x;
    }
  } else {
    int le[4];
    int l = 0, x = u;
    for (register int i = (0); i <= (((int)e[x].size()) - 1); i++)
      if (e[x][i] != fa[x] && l < 2) {
        l++;
        find(e[x][i], x, le[l]);
      }
    ans[++len] = (node){rt, le[1], -val[x] / 2};
    ans[++len] = (node){rt, le[2], -val[x] / 2};
    ans[++len] = (node){le[1], le[2], val[x] / 2};
    int del = -val[x];
    for (int d = u; d != rt; d = fa[d]) val[d] += del;
  }
}
int main() {
  read(n);
  for (register int i = (1); i <= (n - 1); i++) {
    int u, v, w;
    read(u);
    read(v);
    read(w);
    e[u].push_back(v);
    e[v].push_back(u);
    Map[u][v] = Map[v][u] = w;
  }
  for (register int i = (1); i <= (n); i++)
    if (((int)e[i].size()) == 2) {
      puts("NO");
      return 0;
    }
  puts("YES");
  rt = 1;
  for (register int i = (1); i <= (n); i++)
    if (((int)e[i].size()) == 1) rt = i;
  dfs(rt, 0);
  dfs1(rt);
  for (register int i = (1); i <= (n); i++) assert(!val[i]);
  printf("%d\n", len);
  for (register int i = (1); i <= (len); i++)
    printf("%d %d %d\n", ans[i].x, ans[i].y, -ans[i].z);
  return 0;
}
