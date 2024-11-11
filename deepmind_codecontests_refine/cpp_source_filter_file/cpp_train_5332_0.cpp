#include <bits/stdc++.h>
using namespace std;
const long long P = 1e9 + 7;
const int N = 805, M = 1e5 + 5;
const int INF = (1 << 30) - 1;
const double pi = acos(-1);
mt19937 rng(time(0));
struct edge {
  int to, nxt;
  int w, c;
} e[M];
int n1, n2, n, m, x, y, r, b, id[N];
int ans, S, T, S_, T_, i, tot = 1, head[N], d[N], path[N];
char s1[N], s2[N], ch;
queue<int> Q;
bool v[N];
void add(int x, int y, int w, int c) {
  e[++tot] = {y, head[x], w, c}, head[x] = tot;
  e[++tot] = {x, head[y], 0, c}, head[y] = tot;
}
bool spfa() {
  for (int i = (0); i <= (N - 1); ++i) d[i] = INF;
  memset(v, 0, sizeof v);
  d[S] = 0, Q.push(S), v[S] = 1;
  while (!Q.empty()) {
    x = Q.front(), Q.pop(), v[x] = 0;
    for (i = head[x]; i; i = e[i].nxt)
      if (e[i].w && d[y = e[i].to] > d[x] + e[i].c) {
        d[y] = d[x] + e[i].c, path[y] = i;
        if (!v[y]) Q.push(y), v[y] = 1;
      }
  }
  if (d[T] == INF) return false;
  int flow = INF;
  for (y = T; y != S; y = e[i ^ 1].to) i = path[y], flow = min(flow, e[i].w);
  for (y = T; y != S; y = x) {
    i = path[y], x = e[i ^ 1].to;
    e[i].w -= flow, e[i ^ 1].w += flow;
  }
  ans += d[T];
  return true;
}
void adds(int u, int v) {
  add(u, v, INF - 1, 0), add(S, v, 1, 0), add(u, T, 1, 0);
}
int main() {
  cin >> n1 >> n2 >> m >> r >> b;
  n = n1 + n2, S = 0, S_ = n + 1, T_ = n + 2, T = n + 3;
  add(T_, S_, INF, 0);
  cin >> (s1 + 1) >> (s2 + 1);
  for (int i = (1); i <= (n1); ++i) {
    if (s1[i] == 'U') add(S_, i, INF, 0), add(i, T_, INF, 0);
    if (s1[i] == 'R') adds(S_, i);
    if (s1[i] == 'B') adds(i, T_);
  }
  for (int i = (1); i <= (n2); ++i) {
    if (s2[i] == 'U') add(S_, n1 + i, INF, 0), add(n1 + i, T_, INF, 0);
    if (s2[i] == 'R') adds(n1 + i, T_);
    if (s2[i] == 'B') adds(S_, n1 + i);
  }
  for (int i = (1); i <= (m); ++i) {
    cin >> x >> y;
    y += n1;
    id[i] = tot + 1;
    add(x, y, 1, r);
    add(y, x, 1, b);
  }
  while (spfa())
    ;
  for (i = head[S]; i; i = e[i].nxt)
    if (e[i].w) {
      cout << "-1\n";
      return 0;
    }
  cout << ans << endl;
  for (int i = (1); i <= (m); ++i) {
    e[id[i]].w == 0 && (ch = 'R') || e[id[i] + 2].w == 0 && (ch = 'B') ||
        (ch = 'U');
    cout << ch;
  }
  return 0;
}
