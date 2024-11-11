#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
const int inf = 1e9;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T>
inline bool rd(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <class T>
inline void pt(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) pt(x / 10);
  putchar(x % 10 + '0');
}
using namespace std;
const int N = 305;
struct Node {
  int u, v, cap;
  Node(int a = 0, int b = 0, int c = 0) : u(a), v(b), cap(c) {}
  void put() {
    pt(u);
    putchar(' ');
    pt(v);
    putchar(' ');
    pt(cap);
    putchar('\n');
  }
};
vector<Node> ans;
int n, V, m;
int a[N], b[N];
vector<int> G[N], D[N];
int du[N];
bool vis[N];
long long s1;
void dfs(int x) {
  vis[x] = 1;
  s1 += a[x] - b[x];
  for (auto v : G[x])
    if (!vis[v]) {
      D[x].push_back(v);
      D[v].push_back(x);
      du[x]++;
      du[v]++;
      dfs(v);
    }
}
bool ok() {
  memset(vis, 0, sizeof vis);
  memset(du, 0, sizeof du);
  s1 = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      dfs(i);
      if (s1 != 0) return false;
    }
  return true;
}
bool del[N];
bool flag;
void add(int from, int to, int k) {
  if (k == 0) return;
  a[from] -= k;
  a[to] += k;
  ans.push_back(Node(from, to, k));
}
void go(int u, int fa, int sor) {
  for (auto v : D[u])
    if (v != fa && del[v] == false) go(v, u, sor);
  if (fa == u) return;
  if (fa == sor) {
    if (flag) {
      int tmp = min(a[fa] - b[fa], V - a[u]);
      add(fa, u, tmp);
    } else {
      int tmp = min(b[fa] - a[fa], a[u]);
      add(u, fa, tmp);
    }
  } else {
    if (flag) {
      int tmp = min(V - a[u], a[fa]);
      add(fa, u, tmp);
    } else {
      int tmp = min(V - a[fa], a[u]);
      add(u, fa, tmp);
    }
  }
}
void work() {
  memset(del, 0, sizeof del);
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (du[i] == 1) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (a[u] != b[u]) {
      flag = a[u] > b[u];
      go(u, u, u);
    }
    for (auto v : D[u]) {
      if (del[v]) continue;
      if (--du[v] == 1) q.push(v);
    }
    del[u] = 1;
  }
}
int main() {
  rd(n);
  rd(V);
  rd(m);
  for (int i = 1; i <= n; i++) rd(a[i]);
  for (int i = 1; i <= n; i++) rd(b[i]);
  while (m--) {
    int x, y;
    rd(x);
    rd(y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  if (!ok()) {
    puts("NO");
    return 0;
  }
  work();
  pt(int(ans.size()));
  puts("");
  for (auto v : ans) v.put();
  return 0;
}
