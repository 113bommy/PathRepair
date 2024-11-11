#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 100, inf = 0x3f3f3f3f;
const int mod97 = 1e9 + 7, mod33 = 998244353;
const int drc[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct edge {
  int to, cap, dis, nt;
} e[MAX];
int tot, head[555];
int MinCost, MaxFlow;
int n, m, K, Q, H;
int ans[205][205];
int a[105][105];
int b[105];
void add(int x, int y, int cap, int dis) {
  e[tot].to = y;
  e[tot].cap = cap;
  e[tot].dis = dis;
  e[tot].nt = head[x];
  head[x] = tot;
  tot++;
}
bool Bellman_Ford(int S, int T) {
  int pre[T + 1], flow[T + 1], dis[T + 1];
  bool in[T + 1];
  memset(dis, 0x3f, sizeof(dis));
  memset(in, 0, sizeof(in));
  dis[S] = 0;
  flow[S] = inf;
  pre[S] = -1;
  queue<int> q;
  q.push(S);
  in[S] = 1;
  while (q.size()) {
    int tmp = q.front();
    q.pop();
    in[tmp] = 0;
    for (int i = head[tmp]; ~i; i = e[i].nt) {
      int j = e[i].to;
      if (e[i].cap > 0 && dis[j] > dis[tmp] + e[i].dis) {
        dis[j] = dis[tmp] + e[i].dis;
        flow[j] = min(flow[tmp], e[i].cap);
        pre[j] = i ^ 1;
        if (!in[j]) {
          q.push(j);
          in[j] = 1;
        }
      }
    }
  }
  if (dis[T] == inf) return 0;
  MinCost += dis[T] * flow[T];
  MaxFlow += flow[T];
  for (int i = T; i > 0; i = e[pre[i]].to) {
    if (i > 0 && i < (n << 1 | 1)) {
      ans[e[pre[i]].to][i] += flow[T];
    }
    e[pre[i]].cap += flow[T];
    e[pre[i] ^ 1].cap -= flow[T];
  }
  return 1;
}
void Solve() {
  MaxFlow = MinCost = tot = 0;
  while (Bellman_Ford(0, n << 1 | 1))
    ;
  int sum = 0;
  for (int i = 1; i <= n; ++i) sum += b[i];
  if (sum != MaxFlow) {
    puts("NO");
    return;
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%d ", ans[i][j + n] - ans[j + n][i]);
    }
    puts("");
  }
  return;
}
int Main() {
  int t = 1;
  while (t--) {
    while (~scanf("%d%d", &n, &m)) {
      memset(head, -1, sizeof(head));
      int sum1 = 0;
      for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        sum1 += x;
        add(0, i, x, 0);
        add(i, 0, 0, 0);
        add(i, i + n, inf, 0);
        add(i + n, i, 0, 0);
      }
      for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        sum1 -= x;
        b[i] = x;
        add(i + n, n << 1 | 1, x, 0);
        add(n << 1 | 1, i + n, 0, 0);
      }
      for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y + n, inf, 0);
        add(y + n, x, 0, 0);
        add(y, x + n, inf, 0);
        add(x + n, y, 0, 0);
      }
      if (sum1) {
        puts("NO");
        continue;
      }
      Solve();
    }
  }
  return 0;
}
int main() { return Main(); }
