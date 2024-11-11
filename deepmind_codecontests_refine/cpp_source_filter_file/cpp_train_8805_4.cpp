#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int M = 10005;
const int MX = 1e7;
const int INF = 0x3f3f3f3f;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int n, k, a[N], c[N], ans;
int S, T, dis[N], inq[N], pre[N];
queue<int> q;
struct Edge {
  int v, w, c, nxt;
} e[M << 1];
int first[N], eCnt;
inline void AddEdge(int u, int v, int w, int c) {
  e[++eCnt].v = v;
  e[eCnt].w = w;
  e[eCnt].c = c;
  e[eCnt].nxt = first[u];
  first[u] = eCnt;
}
inline void Add(int u, int v, int w, int c) {
  AddEdge(u, v, w, c);
  AddEdge(v, u, 0, -c);
}
bool SPFA() {
  for (int i = 1; i <= T; ++i) {
    dis[i] = INF;
  }
  dis[S] = 0;
  q.push(S);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = 0;
    for (int i = first[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      if (e[i].w && dis[v] > dis[u] + e[i].c) {
        dis[v] = dis[u] + e[i].c;
        pre[v] = i;
        if (!inq[v]) {
          q.push(v);
          inq[v] = 1;
        }
      }
    }
  }
  return dis[T] < INF;
}
void Modify() {
  for (int i = pre[T]; i; i = pre[e[i ^ 1].v]) {
    --e[i].w;
    ++e[i ^ 1].w;
  }
  ans += dis[T];
}
void init() {
  read(n);
  read(k);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    read(c[i]);
  }
}
void solve() {
  eCnt = 1;
  S = n * 2 + 1;
  T = S + 1;
  for (int i = 1; i <= n; ++i) {
    Add(S, i, 1, c[a[i]]);
    Add(i, n + i, 1, -MX);
    Add(n + i, T, 1, 0);
    for (int j = i + 1; j <= n; ++j) {
      Add(n + i, j, 1, (a[i] != a[j]) * c[a[j]]);
    }
  }
  ans = n * MX;
  k = min(n, k);
  while (k--) {
    if (SPFA()) Modify();
  }
  printf("%d\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
