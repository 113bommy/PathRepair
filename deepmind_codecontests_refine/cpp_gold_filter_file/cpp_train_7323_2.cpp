#include <bits/stdc++.h>
using namespace std;
vector<int> G[100005];
int vis[100005];
long long cnt[100005], cnt1[100005];
int n, m;
struct st {
  int x;
  int y;
} s[100005];
int dis[100005];
int dis1[100005];
void spfa() {
  for (int i = 1; i <= n; i++) dis[i] = 1e9, vis[i] = 0;
  vis[1] = 1;
  cnt[1] = 1;
  dis[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    int len = G[u].size();
    for (int i = 0; i < len; i++) {
      int v = G[u][i];
      if (dis[v] > dis[u] + 1) {
        cnt[v] = cnt[u];
        dis[v] = dis[u] + 1;
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      } else if (dis[v] == dis[u] + 1) {
        cnt[v] += cnt[u];
      }
    }
  }
}
void spfa1() {
  for (int i = 1; i <= n; i++) dis1[i] = 1e9, vis[i] = 0;
  cnt1[n] = 1;
  vis[n] = 1;
  dis1[n] = 0;
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    int len = G[u].size();
    for (int i = 0; i < len; i++) {
      int v = G[u][i];
      if (dis1[v] > dis1[u] + 1) {
        cnt1[v] = cnt1[u];
        dis1[v] = dis1[u] + 1;
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      } else if (dis1[v] == dis1[u] + 1) {
        cnt1[v] += cnt1[u];
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
    s[i].x = x;
    s[i].y = y;
  }
  spfa();
  spfa1();
  int ans = dis[n];
  long long Max = 0;
  for (int i = 1; i <= n; i++) {
    if (dis1[i] + dis[i] == ans) {
      if (i == 1 || i == n) {
        Max = max(Max, (long long)cnt1[i] * cnt[i]);
      } else
        Max = max(Max, (long long)cnt1[i] * cnt[i] * 2);
    }
  }
  double ans1 = (double)Max / cnt[n];
  printf("%.12lf\n", ans1);
  return 0;
}
