#include <bits/stdc++.h>
using namespace std;
namespace SPFA {
vector<int> to[2005];
vector<int> flow[2005];
vector<int> cost[2005];
vector<int> pair[2005];
int len[2005];
int cap[2005];
int from[2005];
int edge[2005];
int insd[2005];
int F, T;
int Flow, Cost;
void init(int _f, int _t) {
  F = _f;
  T = _t;
}
void add(int u, int v, int w, int c) {
  pair[u].push_back(to[v].size());
  pair[v].push_back(to[u].size());
  to[u].push_back(v);
  to[v].push_back(u);
  flow[u].push_back(w);
  flow[v].push_back(0);
  cost[u].push_back(c);
  cost[v].push_back(-c);
}
bool SPFA() {
  memset(len, 1, sizeof(len));
  memset(cap, 0, sizeof(cap));
  queue<int> Q;
  Q.push(F);
  cap[F] = 1e9;
  len[F] = 0;
  insd[F] = true;
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    for (int i = 0; i < to[now].size(); i++) {
      int next = to[now][i];
      if (!flow[now][i]) continue;
      if (len[now] + cost[now][i] >= len[next]) continue;
      if (!insd[next]) Q.push(next);
      len[next] = len[now] + cost[now][i];
      cap[next] = min(cap[now], flow[now][i]);
      from[next] = now;
      edge[next] = i;
    }
    insd[now] = false;
  }
  if (!cap[T]) return false;
  int now = T;
  Flow += cap[T];
  Cost += cap[T] * len[T];
  while (now != F) {
    flow[from[now]][edge[now]] -= cap[T];
    flow[now][pair[from[now]][edge[now]]] += cap[T];
    now = from[now];
  }
  return true;
}
void get_ans() {
  while (SPFA())
    ;
}
}  // namespace SPFA
int n, m, x, y;
vector<int> to1[2005];
vector<int> to2[2005];
int fa1[2005];
int fa2[2005];
int lim1[2005];
int lim2[2005];
int bin1[2005];
int bin2[2005];
void dfs1(int x, int fa, int f) {
  fa1[x] = fa;
  if (!~lim1[x]) {
    SPFA::add(f + 500, x + 500, 1, 0);
    for (int i = 0; i < to1[x].size(); i++) {
      int N = to1[x][i];
      if (N ^ fa) dfs1(N, x, f);
    }
  } else {
    bin1[x] = lim1[x];
    bin1[f] -= lim1[x];
    if (bin1[f] < 0) {
      cout << "-1";
      exit(0);
    }
    SPFA::add(f, x, lim1[x], 0);
    for (int i = 0; i < to1[x].size(); i++) {
      int N = to1[x][i];
      if (N ^ fa) dfs1(N, x, x);
    }
    SPFA::add(x, x + 500, bin1[x], 0);
  }
}
void dfs2(int x, int fa, int f) {
  fa2[x] = fa;
  if (!~lim2[x]) {
    SPFA::add(x + 500, f + 500, 1, 0);
    for (int i = 0; i < to2[x].size(); i++) {
      int N = to2[x][i];
      if (N ^ fa) dfs2(N, x, f);
    }
  } else {
    bin2[x] = lim2[x];
    bin2[f] -= lim2[x];
    if (bin2[f] < 0) {
      cout << "-1";
      exit(0);
    }
    SPFA::add(x, f, lim2[x], 0);
    for (int i = 0; i < to2[x].size(); i++) {
      int N = to2[x][i];
      if (N ^ fa) dfs2(N, x, x);
    }
    SPFA::add(x + 500, x, bin2[x], 0);
  }
}
int main() {
  cin >> n >> x >> y;
  y += 1000;
  bin1[2001] = bin2[2002] = 2147483647;
  SPFA::init(2001, 2002);
  for (int i = 1; i <= n; i++) {
    int w;
    cin >> w;
    SPFA::add(i + 500, i + 1500, 1, -w);
    lim1[i] = lim2[i + 1000] = -1;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    to1[u].push_back(v);
    to1[v].push_back(u);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u += 1000, v += 1000;
    to2[u].push_back(v);
    to2[v].push_back(u);
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    lim1[a] = b;
  }
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    a += 1000;
    lim2[a] = b;
  }
  dfs1(x, 2001, 2001);
  dfs2(y, 2002, 2002);
  SPFA::get_ans();
  if (SPFA::Flow != lim1[x] or SPFA::Flow != lim2[y])
    cout << "-1\n";
  else
    cout << -SPFA::Cost;
}
