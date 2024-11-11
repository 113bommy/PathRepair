#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int mod = 998244353;
void reduce(int &a) { a += a >> 31 & mod; }
int Mod(int x) { return x >= mod ? x - mod : x; }
int read() {
  int x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
  return x * f;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 210, M = N * N / 4;
int S, T;
;
struct edge {
  int nxt, to, w;
} e[M << 1];
int head[N], ecnt = 1;
void add(int u, int v, long long w = 0) {
  e[++ecnt].w = w, e[ecnt].to = v, e[ecnt].nxt = head[u];
  head[u] = ecnt;
}
void add_edge(int u, int v, long long w = 0) {
  add(u, v, w), add(v, u, w * 0);
};
int dis[N], cur[N];
queue<int> q;
bool BFS() {
  memset(dis, -1, sizeof(dis)), q.push(S), dis[S] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = cur[u] = head[u], v; i; i = e[i].nxt)
      if (e[i].w && !~dis[v = e[i].to]) dis[v] = dis[u] + 1, q.push(v);
  }
  return ~dis[T];
}
int DFS(int u, int exp) {
  if (u == T) return exp;
  int f, flow = 0;
  for (int &i = cur[u]; i && exp; i = e[i].nxt)
    if (e[i].w && dis[e[i].to] == dis[u] + 1)
      f = DFS(e[i].to, min(exp, e[i].w)), flow += f, exp -= f, e[i].w -= f,
      e[i ^ 1].w += f;
  return flow;
}
int Dinic() {
  int flow = 0;
  while (BFS()) flow += DFS(S, 1061109567);
  return flow;
}
int n, a[N];
vector<int> odd, eve, tmp;
vector<vector<int> > ans;
bool vis[N];
void dfs(int u) {
  vis[u] = 1, tmp.push_back(u);
  for (int i = head[u], v; i; i = e[i].nxt)
    if (!vis[v = e[i].to] && e[i ^ (a[u] & 1)].w) {
      dfs(v);
      break;
    }
}
bool prime(int x) {
  for (int i = 2; i * i <= x; i++)
    if (!(x % i)) return 0;
  return 1;
}
int main() {
  n = read(), S = 0, T = n + 1;
  for (int i = 1; i <= n; i++)
    if ((a[i] = read()) & 1)
      odd.push_back(i), add_edge(S, i, 2);
    else
      eve.push_back(i), add_edge(i, T, 2);
  if (odd.size() != eve.size()) {
    puts("Impossible");
    return 0;
  }
  for (int x : odd)
    for (int y : eve)
      if (prime(a[x] + a[y])) add_edge(x, y, 1);
  if (Dinic() ^ n) {
    puts("Impossible");
    return 0;
  }
  vis[0] = vis[n + 1] = 1;
  for (int i : odd)
    if (!vis[i]) tmp.clear(), dfs(i), ans.push_back(tmp);
  print(ans.size()), putchar('\n');
  for (auto v : ans) {
    print(v.size()), putchar(' ');
    for (int i : v) print(i), putchar(' ');
    putchar('\n');
  }
  return 0;
}
