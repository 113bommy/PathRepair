#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
const int maxm = 1000005;
vector<int> G[maxn];
int dis[maxn], pre[maxn];
int big, n, m;
void dfs() {
  for (int s = 1; s <= n; s++) dis[s] = 0x3f3f3f3f;
  memset(pre, -1, sizeof(pre));
  queue<int> q;
  big = 1;
  q.push(1);
  dis[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    big = max(big, dis[u]);
    int sz = G[u].size();
    for (int s = 0; s < sz; s++) {
      int v = G[u][s];
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        pre[v] = u;
        q.push(v);
      }
    }
  }
}
int spe_bfs(int st) {
  for (int s = 1; s <= n; s++) dis[s] = 0x3f3f3f3f;
  memset(pre, -1, sizeof(pre));
  queue<int> q;
  q.push(st);
  dis[st] = 1;
  while (q.size()) {
    int u = q.front(), sz = G[u].size();
    q.pop();
    if (dis[u] == 3) return u;
    for (int s = 0; s < sz; s++) {
      int v = G[u][s];
      if (v == 1) continue;
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        pre[v] = u;
        q.push(v);
      }
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs();
  if (dis[n] <= 4) {
    printf("%d\n", dis[n] - 1);
    stack<int> q;
    int t = n;
    while (~t) {
      q.push(t);
      t = pre[t];
    }
    while (q.size()) {
      if (q.size() == 1)
        printf("%d\n", q.top());
      else
        printf("%d ", q.top());
      q.pop();
    }
  } else {
    if (big >= 3) {
      printf("5\n");
      int t;
      stack<int> q;
      for (int s = 1; s <= n; s++)
        if (dis[s] == 3) {
          t = s;
          break;
        }
      q.push(n);
      q.push(1);
      while (~t) {
        q.push(t);
        t = pre[t];
      }
      while (q.size()) {
        if (q.size() == 1)
          printf("%d\n", q.top());
        else
          printf("%d ", q.top());
        q.pop();
      }
    } else {
      int sz = G[1].size();
      int st = -1, en;
      for (int s = 0; s < sz; s++) {
        int v = G[1][s], ans = spe_bfs(v);
        if (ans != 0) {
          st = v;
          en = ans;
          break;
        }
      }
      if (st == -1)
        printf("-1\n");
      else {
        printf("5\n");
        stack<int> q;
        q.push(n);
        q.push(st);
        int t = en;
        while (~t) {
          q.push(t);
          t = pre[t];
        }
        q.push(1);
        while (q.size()) {
          if (q.size() == 1)
            printf("%d\n", q.top());
          else
            printf("%d ", q.top());
          q.pop();
        }
      }
    }
  }
  return 0;
}
