#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int maxm = 10010;
const int INF = 2e9;
struct Edge {
  int to, next, w;
} edge[maxm * 2];
int head[maxn], tot;
void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w) {
  edge[tot].to = v;
  edge[tot].w = w;
  edge[tot].next = head[u];
  head[u] = tot++;
}
struct node {
  int u, dis;
  node(int _u = 0, int _dis = 0) : u(_u), dis(_dis) {}
  bool operator<(const node& nx) const { return dis > nx.dis; }
};
int d[maxn];
int n, m, l, s, t;
void dj(int st) {
  for (int i = 0; i < n; ++i) d[i] = INF;
  priority_queue<node> Q;
  d[st] = 0;
  Q.push(node(st, 0));
  while (!Q.empty()) {
    node tmp = Q.top();
    Q.pop();
    int poi = tmp.u, w = tmp.dis;
    if (w > d[poi]) continue;
    for (int i = head[poi]; ~i; i = edge[i].next) {
      int v = edge[i].to, wx = edge[i].w;
      if (d[v] > w + wx) {
        d[v] = w + wx;
        if (d[v] <= l) Q.push(node(v, d[v]));
      }
    }
  }
}
int e[maxm][3];
int us[maxm][3];
int id[maxm];
int main() {
  init();
  scanf("%d%d%d%d%d", &n, &m, &l, &s, &t);
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]);
    if (e[i][2] == 0) {
      for (int j = 0; j < 3; ++j) us[cnt][j] = e[i][j];
      id[i] = cnt;
      ++cnt;
    } else {
      addedge(e[i][0], e[i][1], e[i][2]);
      addedge(e[i][1], e[i][0], e[i][2]);
    }
  }
  dj(s);
  if (d[t] < l) {
    puts("NO");
    return 0;
  }
  if (cnt == 0 && d[t] == l) {
    puts("YES");
    for (int i = 0; i < m; ++i) printf("%d %d %d\n", e[i][0], e[i][1], e[i][2]);
    return 0;
  }
  bool flag = false;
  int cx = 0;
  while (cx < cnt) {
    addedge(us[cx][0], us[cx][1], 1);
    addedge(us[cx][1], us[cx][0], 1);
    dj(s);
    if (d[t] <= l) {
      flag = true;
      us[cx][2] = l - d[t] + 1;
      break;
    }
    us[cx][2] = 1;
    ++cx;
  }
  if (!flag) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = cx + 1; i < cnt; ++i) us[i][2] = 2e9;
  for (int i = 0; i < m; ++i) {
    if (e[i][2] != 0)
      printf("%d %d %d\n", e[i][0], e[i][1], e[i][2]);
    else
      printf("%d %d %d\n", e[i][0], e[i][1], us[id[i]][2]);
  }
  return 0;
}
