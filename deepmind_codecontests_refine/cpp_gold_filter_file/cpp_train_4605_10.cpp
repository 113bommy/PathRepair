#include <bits/stdc++.h>
using namespace std;
int n, m, Q, S, T, head[60], o = 1, dis[60], cc[60], pre[60], lst[60];
bool vis[60];
vector<pair<int, int> > vec;
struct edge {
  int to, link, w, c;
} e[5010];
void add_edge(int u, int v, int w, int c) {
  e[++o].to = v, e[o].link = head[u], head[u] = o, e[o].w = w, e[o].c = c;
  e[++o].to = u, e[o].link = head[v], head[v] = o, e[o].w = 0, e[o].c = -c;
}
queue<int> q;
bool spfa() {
  for (int i = 1; i <= n; i++) dis[i] = 2e9, pre[i] = 0;
  dis[S] = 0, q.push(S), vis[S] = true, cc[S] = 2e9;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = false;
    for (int i = head[u]; i; i = e[i].link) {
      if (!e[i].w || dis[e[i].to] <= dis[u] + e[i].c) continue;
      dis[e[i].to] = dis[u] + e[i].c, pre[e[i].to] = u, lst[e[i].to] = i,
      cc[e[i].to] = min(e[i].w, cc[u]);
      if (!vis[e[i].to]) q.push(e[i].to), vis[e[i].to] = true;
    }
  }
  return pre[T];
}
int main() {
  scanf("%d%d", &n, &m);
  S = 1, T = n;
  for (int i = 1, u, v, w; i <= m; i++)
    scanf("%d%d%d", &u, &v, &w), add_edge(u, v, 1, w);
  int Mx = 0, Mn = 0;
  while (spfa()) {
    int nw = T;
    int fl = cc[T], co = dis[T];
    while (nw != S) {
      e[lst[nw]].w -= fl;
      e[lst[nw] ^ 1].w += fl;
      nw = pre[nw];
    }
    Mx += fl, Mn += fl * co;
    vec.push_back(make_pair(Mx, Mn));
  }
  scanf("%d", &Q);
  while (Q--) {
    int x;
    scanf("%d", &x);
    long double ans = 2e9;
    for (int i = 0; i < vec.size(); i++)
      ans = min(ans, (long double)(vec[i].second + x) / vec[i].first);
    printf("%.12lf\n", (double)ans);
  }
}
