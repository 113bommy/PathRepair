#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;
int head[N], pnt[M], cap[M], nxt[M], cnt;
void add_edge(int u, int v, int w) {
  pnt[cnt] = v;
  cap[cnt] = w;
  nxt[cnt] = head[u];
  head[u] = cnt++;
}
void add_double(int u, int v, int w1, int w2 = 0) {
  add_edge(u, v, w1);
  add_edge(v, u, w2);
}
int lev[N], cur[N];
bool bfs(int s, int t) {
  queue<int> q;
  memset(lev, 0, sizeof lev);
  q.push(s);
  lev[s] = 1;
  while (q.size() && !lev[t]) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; ~i; i = nxt[i]) {
      int v = pnt[i];
      if (cap[i] > 0 && !lev[v]) {
        lev[v] = lev[u] + 1;
        q.push(v);
      }
    }
  }
  return lev[t];
}
int dfs(int u, int t, int delta) {
  if (u == t || !delta) return delta;
  int ret = 0;
  for (int i = cur[u]; ~i; i = nxt[i]) {
    int v = pnt[i];
    if (cap[i] > 0 && lev[v] == lev[u] + 1) {
      int d = dfs(v, t, min(delta, cap[i]));
      cur[u] = i;
      ret += d;
      delta -= d;
      cap[i] -= d;
      cap[i ^ 1] += d;
      if (delta == 0) return ret;
    }
  }
  lev[u] = 0;
  return ret;
}
int dinic(int s, int t) {
  int ret = 0;
  while (bfs(s, t)) {
    for (int i = s; i <= t; ++i) cur[i] = head[i];
    ret += dfs(s, t, INF);
  }
  return ret;
}
int n, b, q;
int main() {
  ios_base::sync_with_stdio(0);
  while (scanf("%d%d%d", &n, &b, &q) == 3) {
    cnt = 0;
    memset(head, -1, sizeof head);
    vector<pair<int, int> > v;
    v.push_back({b, n});
    while (q--) {
      int x, y;
      scanf("%d%d", &x, &y);
      v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int s = 0, t = 5 + v.size() + 1;
    for (int i = 1; i <= 5; ++i) add_double(s, i, n / 5);
    pair<int, int> pre = {0, 0};
    bool ok = true;
    for (int i = 0; i < v.size(); ++i) {
      auto& cur = v[i];
      int sz = cur.first - pre.first, cnt = cur.second - pre.second;
      if (cnt < 0 || sz < cnt) {
        ok = false;
        break;
      }
      add_double(6 + i, t, cnt);
      for (int j = 1; j <= 5; ++j) {
        int w = (cur.first + 5 - j) / 5 - (pre.first + 5 - j) / 5;
        add_double(j, 6 + i, w);
      }
      pre = cur;
    }
    if (!ok || dinic(s, t) != n)
      puts("unfair");
    else
      puts("fair");
  }
  return 0;
}
