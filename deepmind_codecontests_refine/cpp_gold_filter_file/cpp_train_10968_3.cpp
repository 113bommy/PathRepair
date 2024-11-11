#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
const int N = 5e3 + 3;
const int INF = 2e9;
struct edge {
  int to, w;
};
vector<edge> G[N];
vector<int> g1[N];
vector<int> g2[N];
int n, dis[N], m, cnt[N];
bool vis[N];
bool spfa(int s) {
  queue<int> q;
  for (int i = 1; i <= n; ++i) dis[i] = INF, vis[i] = false;
  dis[s] = 0;
  q.push(s);
  vis[s] = true;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    vis[x] = false;
    for (register int i = 0; i < G[x].size(); ++i) {
      edge t = G[x][i];
      if (dis[t.to] > dis[x] + t.w) {
        dis[t.to] = dis[x] + t.w;
        if (!vis[t.to]) {
          vis[t.to] = true;
          cnt[t.to]++;
          if (cnt[t.to] > n + 1) {
            cout << "No" << endl;
            return false;
          }
          q.push(t.to);
        }
      }
    }
  }
  return true;
}
struct node {
  int a, b;
} c[N];
int onpath[N];
void dfs1(int x) {
  onpath[x]++;
  for (int i = 0; i < g1[x].size(); ++i)
    if (!onpath[g1[x][i]]) dfs1(g1[x][i]);
}
void dfs2(int x) {
  onpath[x]++;
  for (int i = 0; i < g2[x].size(); ++i)
    if (onpath[g2[x][i]] == 1) dfs2(g2[x][i]);
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) G[0].push_back((edge){i, 0});
  for (int i = 1; i <= m; ++i) {
    c[i].a = read();
    c[i].b = read();
    g1[c[i].a].push_back(c[i].b);
    g2[c[i].b].push_back(c[i].a);
  }
  dfs1(1);
  dfs2(n);
  for (int i = 1; i <= m; ++i) {
    if ((onpath[c[i].a] >= 2) && (onpath[c[i].b] >= 2)) {
      G[c[i].a].push_back((edge){c[i].b, 2});
      G[c[i].b].push_back((edge){c[i].a, -1});
    }
  }
  if (spfa(1)) {
    if (dis[n] == INF) {
      cout << "No" << endl;
      return 0;
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= m; ++i) {
      if ((onpath[c[i].a] >= 2) && (onpath[c[i].b]) &&
          (dis[c[i].b] == dis[c[i].a] + 2))
        cout << 2 << endl;
      else
        cout << 1 << endl;
    }
  }
  return 0;
}
