#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
struct Edge {
  int from, to, cap, flow, cost;
  Edge(int from = 0, int to = 0, int cap = 0, int flow = 0, int cost = 0) {
    this->from = from;
    this->to = to;
    this->cap = cap;
    this->flow = flow;
    this->cost = cost;
  }
};
vector<Edge> edges;
vector<int> g[3205];
bool vis[3205];
int dis[3205];
int pre[3205];
int a[3205];
int s, t;
void init() {
  for (int i = 0; i < 3205; i++) {
    g[i].clear();
  }
  edges.clear();
}
void add(int from, int to, int cap, int cost) {
  edges.push_back(Edge(from, to, cap, 0, cost));
  edges.push_back(Edge(to, from, 0, 0, -cost));
  int m = edges.size();
  g[from].push_back(m - 2);
  g[to].push_back(m - 1);
}
bool spfa(int &flow, int &cost) {
  int i;
  for (i = 0; i < 3205; i++) dis[i] = 0x3f7f7f7f;
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.push(s);
  dis[s] = 0;
  vis[s] = 1;
  pre[s] = 0;
  a[s] = 0x3f7f7f7f;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    int sz = g[u].size();
    for (i = 0; i < sz; i++) {
      Edge &e = edges[g[u][i]];
      if (e.cap > e.flow && dis[e.to] > dis[u] + e.cost) {
        dis[e.to] = dis[u] + e.cost;
        pre[e.to] = g[u][i];
        a[e.to] = min(a[u], e.cap - e.flow);
        if (!vis[e.to]) {
          vis[e.to] = 1;
          q.push(e.to);
        }
      }
    }
  }
  if (dis[t] == 0x3f7f7f7f) return false;
  flow += a[t];
  cost += dis[t] * a[t];
  int v = t;
  while (v != s) {
    edges[pre[v]].flow += a[t];
    edges[pre[v] ^ 1].flow -= a[t];
    v = edges[pre[v]].from;
  }
  return true;
}
int minCost() {
  int flow = 0, cost = 0;
  while (spfa(flow, cost))
    ;
  return cost;
}
char ch[3205], temp[1005];
char str[504][504];
int val[2005];
vector<int> dian;
int main() {
  int m, len, i, x, j, k;
  scanf("%d", &len);
  scanf("%s", ch + 1);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%s%d", str[i] + 1, &val[i]);
  }
  scanf("%d", &x);
  init();
  dian.clear();
  for (i = 1; i <= m; i++) {
    int length = strlen(str[i] + 1);
    for (j = 1; j <= len; j++) {
      int flag = 0, chang = 1;
      for (k = j; chang <= length && k <= len; k++, chang++) {
        if (ch[k] != str[i][chang]) {
          flag = 1;
          break;
        }
      }
      if (chang == length + 1 && flag == 0) {
        add(j - 1, j + length - 1, 1, -val[i]);
        dian.push_back(j - 1);
        dian.push_back(j + length - 1);
      }
    }
  }
  t = 2000;
  dian.push_back(t);
  sort(dian.begin(), dian.end());
  int sz = dian.size();
  for (i = 0; i < sz - 1; i++) {
    add(dian[i], dian[i + 1], x, 0);
    if (i == 0) s = dian[i];
  }
  add(dian[sz - 1], t, x, 0);
  int ans1 = minCost();
  printf("%d\n", -ans1);
  return 0;
}
