#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1000000007;
const double pi = 3.1415926535897932, eps = 1e-6;
const int gn = 10020, gm = 60005;
struct edge {
  int v, fl, ca, nxt;
};
struct dinic_ {
  int dis[gn], hd[gn], cnt = 0;
  edge e[2 * gm];
  bool vis[gn], viss[gn];
  int dn, dm;
  void init(int x) {
    dn = x;
    for (int(i) = (0); (i) <= (dn); (i)++) hd[i] = -1;
  }
  void adde(int x, int y, int ca) {
    e[cnt].nxt = hd[x];
    e[cnt].ca = ca;
    e[cnt].v = y;
    hd[x] = cnt;
    cnt++;
    dm++;
  }
  void link(int x, int y, int ca) {
    adde(x, y, ca);
    adde(y, x, 0);
  }
  void bfs(int s) {
    queue<int> q;
    q.push(s);
    for (int(i) = (0); (i) <= (dn); (i)++) vis[i] = 0, dis[i] = inf;
    dis[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
      int c = q.front();
      q.pop();
      for (int i = hd[c]; i != -1; i = e[i].nxt) {
        if (e[i].ca - e[i].fl <= 0) continue;
        int to = e[i].v;
        if (!vis[to]) {
          vis[to] = 1;
          dis[to] = dis[c] + 1;
          q.push(to);
        }
      }
    }
  }
  int dfs(int x, int end, int minv) {
    if (x == end) return minv;
    viss[x] = 1;
    int res = 0;
    for (int i = hd[x]; i != -1; i = e[i].nxt) {
      int to = e[i].v, cap = e[i].ca, flo = e[i].fl;
      if (cap > flo && dis[to] == dis[x] + 1 && !viss[to]) {
        res = dfs(to, end, min(minv, cap - flo));
        if (res > 0) {
          e[i].fl += res;
          e[i ^ 1].fl -= res;
          return res;
        }
      }
    }
    return res;
  }
  int work(int S, int T) {
    bfs(S);
    int flow = 0;
    while (dis[T] != inf) {
      int cur = 0;
      for (int(i) = (0); (i) <= (dn); (i)++) viss[i] = 0;
      while ((cur = dfs(S, T, inf)) > 0) {
        flow += cur;
        for (int(i) = (0); (i) <= (dn); (i)++) viss[i] = 0;
      }
      bfs(S);
    }
    return flow;
  }
} dinic;
int n, b, q;
pair<int, int> a[10005];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> b >> q;
  q++;
  dinic.init(7 + q);
  int S = 0, T = 6 + q;
  for (int(i) = (1); (i) <= (5); (i)++) dinic.link(S, i, n / 5);
  for (int(i) = (1); (i) < (q); (i)++) {
    int x, y;
    cin >> x >> y;
    a[i] = make_pair(x, y);
  }
  a[q] = make_pair(b, n);
  sort(a + 1, a + q + 1);
  for (int(i) = (1); (i) <= (q); (i)++) {
    int y = a[i].first, x = a[i - 1].first, u = a[i].second,
        v = a[i - 1].second;
    for (int(j) = (1); (j) <= (5); (j)++) {
      int num = (y - j + 5) / 5 - (x - j + 5) / 5;
      dinic.link(j, i + 5, num);
    }
    if (u < v) {
      cout << "unfair" << '\n';
      return 0;
    }
    dinic.link(i + 5, T, u - v);
  }
  int cur = dinic.work(S, T);
  if (cur == n)
    cout << "fair" << '\n';
  else
    cout << "unfair" << '\n';
  return 0;
}
