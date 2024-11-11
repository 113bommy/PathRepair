#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 998244353;
const int MAXN = 4405;
const int MAXM = MAXN << 6;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
queue<int> que;
long long c[MAXN], to[MAXN];
pair<long long, long long> a[MAXN];
int n, nn, vnum, edgenum = 1, id0[MAXN], idt[MAXN], t, S, T;
int flow[MAXN << 2], dist[MAXN << 2], vis[MAXN << 2];
int head[MAXN << 2], pre[MAXN << 2], from[MAXN << 2];
struct enode {
  int to, nxt, f, c;
} e[MAXM];
int compare0(int x, int y) {
  return (a[x].second < a[y].second) ||
         (a[x].second == a[y].second && a[x].first > a[y].first);
}
int comparet(int x, int y) {
  return a[x].first * t + a[x].second < a[y].first * t + a[y].second;
}
bool check(int x) {
  t = x;
  for (int i = 1; i <= nn; i++) c[i] = a[i].first * t + a[i].second;
  for (int i = 1, k = 1; i <= nn; i++) {
    if (c[id0[i]] > c[id0[k]]) k = i;
    to[id0[i]] = c[id0[k]];
  }
  sort(to + 1, to + n + 1);
  sort(idt + 1, idt + nn + 1, comparet);
  for (int i = 1, now = 1; i <= nn; i++) {
    if (idt[i] <= n) continue;
    if (to[now] < c[idt[i]])
      return 0;
    else
      now++;
  }
  return 1;
}
int solve1() {
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}
void add(int u, int v, int f, int c) {
  e[++edgenum] = (enode){v, head[u], f, c}, head[u] = edgenum;
  e[++edgenum] = (enode){u, head[v], 0, -c}, head[v] = edgenum;
}
void build() {
  S = nn << 1 | 1, T = vnum = S + 1;
  for (int i = 1; i <= n; i++) add(S, i, 1, 0);
  for (int i = n + 1; i <= nn; i++) add(i + nn, T, 1, 0);
  for (int i = 1; i <= nn; i++) add(i, i + nn, INF, 0);
  for (int i = 1; i <= nn; i++) c[i] = a[i].second;
  for (int i = 1, j; i <= nn; i = j + 1) {
    j = i, vnum++;
    while (c[id0[i]] == c[id0[j + 1]]) j++;
    for (int k = i; k <= j; k++)
      add(id0[k], vnum, INF, 1), add(vnum, id0[k], INF, 0);
    if (i > 1) add(vnum, vnum - 1, INF, 0);
  }
  for (int i = 1; i <= nn; i++) c[i] = a[i].first * t + a[i].second;
  for (int i = 1, j; i <= nn; i = j + 1) {
    j = i, vnum++;
    while (c[idt[i]] == c[idt[j + 1]]) j++;
    for (int k = i; k <= j; k++)
      add(idt[k] + nn, vnum, INF, 1), add(vnum, idt[k] + nn, INF, 0);
    if (i > 1) add(vnum, vnum - 1, INF, 0);
  }
}
int bfs() {
  for (int i = 1; i <= vnum; i++) dist[i] = INF, flow[i] = vis[i] = 0;
  dist[S] = 0, flow[S] = INF, vis[S] = 1, que.push(S);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to, f = e[i].f, c = e[i].c;
      if (!f || dist[u] + e[i].c >= dist[v]) continue;
      pre[v] = u, from[v] = i;
      flow[v] = min(flow[u], f);
      dist[v] = dist[u] + e[i].c;
      if (!vis[v]) vis[v] = 1, que.push(v);
    }
    vis[u] = 0;
  }
  return flow[T];
}
int MCMF() {
  int ans = 0;
  while (bfs()) {
    ans += dist[T] * flow[T];
    for (int p = T; p != S; p = pre[p])
      e[from[p]].f -= flow[T], e[from[p] ^ 1].f += flow[T];
  }
  return ans;
}
int main() {
  n = read(), nn = n + n;
  for (int i = 1; i <= nn; i++)
    a[i].first = read(), a[i].second = read(), id0[i] = idt[i] = i;
  sort(id0 + 1, id0 + nn + 1, compare0);
  t = solve1();
  if (!check(t)) {
    puts("-1");
    return 0;
  }
  printf("%d ", t);
  sort(idt + 1, idt + nn, comparet);
  build();
  int ans = MCMF();
  printf("%d\n", ans);
  return 0;
}
