#include <bits/stdc++.h>
using namespace std;
int read();
const int N = 1e5 + 5, NN = N * 2, MM = (N * 5) * 2, INF = 0x7fffffff;
void nos() {
  puts("-1");
  exit(0);
}
int n, m, x[N], y[N], S, T, SS, TT, ans[N];
long long R, B, sum;
vector<int> vx, vy;
int nn, mm, cnt[NN], cond[NN];
int getid(int x, vector<int> &v) {
  return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
int eds = 1, fir[NN], nxt[MM], to[MM], fl[MM];
void addedge(int u, int v, int f) {
  to[++eds] = v;
  fl[eds] = f;
  nxt[eds] = fir[u];
  fir[u] = eds;
}
void addflow(int u, int v, int f) {
  addedge(u, v, f);
  addedge(v, u, 0);
}
int iot[N];
void addFlow(int u, int v, int f1, int f2) {
  if (f1 > f2) nos();
  if (u == S) sum += f2;
  addflow(u, v, f2 - f1);
  iot[u] -= f1;
  iot[v] += f1;
}
void build() {
  addFlow(T, S, 0, INF);
  for (int i = (1); i <= (T); ++i)
    if (iot[i] < 0)
      addflow(i, TT, -iot[i]);
    else
      addflow(SS, i, iot[i]);
}
int d[NN], cur[NN];
int bfs(int S, int T) {
  queue<int> q;
  for (int i = (1); i <= (::TT); ++i) d[i] = -1, cur[i] = fir[i];
  q.push(S);
  d[S] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = fir[u], v; v = to[i], i; i = nxt[i])
      if (fl[i] && d[v] == -1) d[v] = d[u] + 1, q.push(v);
  }
  return d[T] != -1;
}
int dinic(int u, int flow, int goal) {
  if (u == goal) return flow;
  int rest = flow;
  for (int &i = cur[u], v; i; i = nxt[i])
    if (fl[i] && d[v = to[i]] == d[u] + 1) {
      int res = dinic(v, min(rest, fl[i]), goal);
      if (res)
        rest -= res, fl[i] -= res, fl[i ^ 1] += res;
      else
        d[v] = -1;
      if (!rest) return flow;
    }
  return flow - rest;
}
int Maxflow() {
  while (bfs(SS, TT)) dinic(SS, INF, TT);
  for (int i = fir[SS], u; u = to[i], i; i = nxt[i])
    if (fl[i]) return -1;
  while (bfs(S, T)) dinic(S, INF, T);
  for (int i = fir[S], u; u = to[i], i; i = nxt[i])
    if (u != T) sum -= fl[i];
  return sum;
}
int main() {
  scanf("%d%d%lld%lld", &n, &m, &R, &B);
  for (int i = (1); i <= (n); ++i) {
    scanf("%d%d", x + i, y + i);
    vx.push_back(x[i]);
    vy.push_back(y[i]);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  sort(vy.begin(), vy.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  nn = vx.size();
  mm = vy.size();
  S = nn + mm + 1;
  T = S + 1;
  SS = T + 1;
  TT = SS + 1;
  for (int i = (1); i <= (n); ++i) {
    int idx = getid(x[i], vx);
    int idy = getid(y[i], vy) + nn;
    ++cnt[idx];
    ++cnt[idy];
    addFlow(idx, idy, 0, 1);
    ans[i] = eds - 1;
  }
  for (int i = (1); i <= (nn + mm); ++i) cond[i] = cnt[i];
  for (int i = (1); i <= (m); ++i) {
    static int op, l, d;
    scanf("%d%d%d", &op, &l, &d);
    if (op == 1) {
      int id = getid(l, vx);
      if (id > vx.size() || vx[id - 1] != l) continue;
      cond[id] = min(cond[id], d);
    } else {
      int id = getid(l, vy);
      if (id > vy.size() || vy[id - 1] != l) continue;
      id += nn;
      cond[id] = min(cond[id], d);
    }
  }
  for (int i = (1); i <= (nn); ++i)
    addFlow(S, i, (cnt[i] - cond[i] + 1) / 2, (cnt[i] + cond[i]) / 2);
  for (int i = (nn + 1); i <= (nn + mm); ++i)
    addFlow(i, T, (cnt[i] - cond[i] + 1) / 2, (cnt[i] + cond[i]) / 2);
  build();
  int res = Maxflow();
  if (res == -1)
    nos();
  else {
    printf("%lld\n", max(R, B) * n - res * (max(R, B) - min(R, B)));
    if (R < B)
      for (int i = (1); i <= (n); ++i) putchar(fl[ans[i]] == 0 ? 'r' : 'b');
    else
      for (int i = (1); i <= (n); ++i) putchar(fl[ans[i]] == 0 ? 'b' : 'r');
  }
  return 0;
}
