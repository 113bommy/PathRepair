#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int mod = 1e9 + 7;
int n;
struct Edge {
  int from, to, next;
} edge[200100 << 1];
int head[200100], num_edge;
inline void add_Edge(int from, int to) {
  int t = ++num_edge;
  edge[t].from = from;
  edge[t].to = to;
  edge[t].next = head[from];
  head[from] = t;
}
long long dp[200100], pre[200100], suf[200100], ans[200100];
inline void dfs(int now, int comfrom) {
  dp[now] = 1;
  for (int i = head[now]; i != -1; i = edge[i].next) {
    int to = edge[i].to;
    if (to == comfrom) continue;
    dfs(to, now);
    dp[now] = dp[now] * (dp[to] + 1) % mod;
  }
}
int fa[200100];
inline void bfs() {
  queue<int> q;
  q.push(1);
  fa[1] = 0;
  ans[1] = dp[1];
  dp[1] = 0;
  vector<int> son;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    son.clear();
    for (int i = head[now]; i != -1; i = edge[i].next) {
      int to = edge[i].to;
      if (fa[now] == to) continue;
      fa[to] = now;
      son.push_back(to);
    }
    int len = (int)son.size();
    long long nowv = 1;
    for (int i = 0; i < len; i++) {
      pre[i] = nowv;
      nowv = nowv * (dp[son[i]] + 1) % mod;
    }
    nowv = 1;
    for (int i = len - 1; i >= 0; i--) {
      suf[i] = nowv;
      nowv = nowv * (dp[son[i]] + 1) % mod;
    }
    int t = 0;
    for (int i = head[now]; i != -1; i = edge[i].next) {
      int to = edge[i].to;
      if (fa[now] == to) continue;
      long long nowv = pre[t] * suf[t] % mod;
      nowv = nowv * (dp[now] + 1) % mod;
      ans[to] = dp[to] * (nowv + 1) % mod;
      q.push(to);
      t++;
      dp[to] = nowv;
    }
  }
}
int main() {
  n = read();
  num_edge = 0;
  for (int i = 1; i <= n; i++) {
    head[i] = -1;
  }
  for (int i = 2; i <= n; i++) {
    int p = read();
    add_Edge(p, i);
    add_Edge(i, p);
  }
  dfs(1, 0);
  bfs();
  for (int i = 1; i <= n; i++) {
    if (i != 1) printf(" ");
    printf("%d", (int)ans[i]);
  }
  printf("\n");
  return 0;
}
