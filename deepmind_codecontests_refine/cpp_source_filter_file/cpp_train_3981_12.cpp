#include <bits/stdc++.h>
using namespace std;
char buf[1 << 20], *p1, *p2;
template <typename T>
inline void read(T &t) {
  int v =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
           ? EOF
           : *p1++);
  T f = 1;
  t = 0;
  while (!isdigit(v)) {
    if (v == '-') f = -1;
    v = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  while (isdigit(v)) {
    t = t * 10 + v - 48;
    v = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  t *= f;
}
template <typename T, typename... Args>
inline void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
const int N = 1e5 + 10;
int fat[N], n, m, siz, dep[N], tag[N];
bool vis[N], flag;
vector<int> G[N], ind, ans, now;
void dfs(int x, int f) {
  now.push_back(x);
  vis[x] = 1;
  fat[x] = f;
  dep[x] = dep[f] + 1;
  for (auto y : G[x]) {
    if (vis[y]) {
      if (dep[y] - dep[x] + 1 >= siz) {
        printf("2\n%d\n", dep[y] - dep[x] + 1);
        for (int i = dep[y] - 1; i < dep[x]; ++i) printf("%d ", now[i]);
        flag = 1;
        exit(0);
      }
    } else {
      dfs(y, x);
    }
  }
  if (!tag[x]) {
    ind.push_back(x);
    for (auto y : G[x]) {
      tag[y] = 1;
    }
  }
  now.pop_back();
}
signed main() {
  read(n, m);
  siz = sqrt(n - 1) + 1;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    read(x, y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1, 0);
  puts("1");
  for (int i = 0; i < siz; ++i) printf("%d ", ind[i]);
  return 0;
}
