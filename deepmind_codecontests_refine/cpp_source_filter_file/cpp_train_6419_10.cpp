#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int from, to;
  int val;
  int next;
} eage[2005];
int head[1005];
int tot = 0;
void add(int x, int y, int z) {
  eage[++tot].from = x;
  eage[tot].to = y;
  eage[tot].val = z;
  eage[tot].next = head[x];
  head[x] = tot;
}
int n, m;
int x, y;
long long dis[1005];
int t[1005], c[1005];
bool taken[1005];
vector<int> neigh[1005];
vector<int> cost[1005];
void rebuild(int k) {
  memset(taken, 0, sizeof taken);
  for (int i = 1; i <= n; i++) dis[i] = (1LL << 60);
  priority_queue<pair<int, int> > que;
  que.push(make_pair(0, k));
  dis[k] = 0;
  while (!que.empty()) {
    pair<int, int> now = que.top();
    que.pop();
    int v = now.second;
    if (taken[v]) continue;
    taken[v] = true;
    if (dis[v] >= t[k]) continue;
    for (int i = head[v]; i; i = eage[i].next)
      if (dis[eage[i].to] > dis[v] + eage[i].val) {
        dis[eage[i].to] = dis[v] + eage[i].val;
        que.push(make_pair(-dis[eage[i].to], eage[i].to));
      }
  }
  for (int i = 1; i <= n; i++)
    if (dis[i] <= t[k] && i != k) neigh[k].push_back(i);
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &x, &y);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
    add(y, x, z);
  }
  for (int i = 1; i <= n; i++) scanf("%d%d", &t[i], &c[i]);
  for (int i = 1; i <= n; i++) rebuild(i);
  memset(taken, 0, sizeof taken);
  for (int i = 1; i <= n; i++) dis[i] = (1LL << 60);
  dis[x] = 0;
  priority_queue<pair<int, int> > que;
  que.push(make_pair(0, x));
  while (!que.empty()) {
    pair<int, int> now = que.top();
    int v = now.second;
    que.pop();
    if (taken[v]) continue;
    taken[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++)
      if (dis[neigh[v][i]] > dis[v] + c[v]) {
        dis[neigh[v][i]] = dis[v] + c[v];
        que.push(make_pair(-dis[neigh[v][i]], neigh[v][i]));
      }
  }
  if (dis[y] == (1LL << 60)) dis[y] = -1;
  printf("%d", dis[y]);
  return 0;
}
