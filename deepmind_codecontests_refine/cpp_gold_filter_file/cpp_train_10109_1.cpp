#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, m, tot;
int to[N], _next[N], head[N], deg_in[N], deg_out[N], vis[30][N], used[30];
vector<int> src, sink;
void addEdge(int u, int v) {
  to[++tot] = v, _next[tot] = head[u], head[u] = tot;
}
void BFS(int s, int p) {
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[p][u] = true;
    for (int i = head[u]; i; i = _next[i]) {
      int v = to[i];
      if (!vis[p][v]) {
        vis[p][v] = true;
        q.push(v);
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, v, u; i <= m; i++) {
    scanf("%d%d", &v, &u);
    addEdge(v, u);
    deg_out[v]++, deg_in[u]++;
  }
  for (int i = 1; i <= n; i++) {
    if (deg_in[i] == 0) src.push_back(i);
    if (deg_out[i] == 0) sink.push_back(i);
  }
  int c = src.size();
  for (int i = 0; i < c; i++) BFS(src[i], i);
  bool flag = true;
  for (int i = 1; i < (1 << c) - 1; i++) {
    int cnt1 = 0, cnt2 = 0;
    for (int j = 0; j < c; j++)
      if ((1 << j) & i) {
        for (int k = 0; k < c; k++)
          if (vis[j][sink[k]]) used[k] = 1;
        cnt1++;
      }
    for (int j = 0; j < c; j++) {
      cnt2 += used[j], used[j] = 0;
    }
    if (cnt1 >= cnt2) flag = false;
  }
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
}
