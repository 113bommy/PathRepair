#include <bits/stdc++.h>
using namespace std;
const int SOURCE = 0, SINK = 1;
struct edge {
  int to, idx, cap;
};
vector<vector<edge>> adj;
vector<int> lvl, ptr;
int totalflow;
int dfs(int n, int f) {
  if (n == SINK) {
    totalflow += f;
    return f;
  }
  if (lvl[n] == lvl[SINK]) return 0;
  while (ptr[n] < (int)adj[n].size()) {
    edge& e = adj[n][ptr[n]];
    ptr[n]++;
    if (lvl[e.to] == lvl[n] + 1 && e.cap > 0) {
      int nf = dfs(e.to, min(f, e.cap));
      if (nf) {
        e.cap -= nf;
        adj[e.to][e.idx].cap += nf;
        return nf;
      }
    }
  }
  return 0;
}
bool runMaxFlow() {
  lvl.assign(adj.size(), -1);
  ptr.assign(adj.size(), 0);
  lvl[SOURCE] = 0;
  queue<int> bfs;
  bfs.push(SOURCE);
  while (!bfs.empty()) {
    int t = bfs.front();
    bfs.pop();
    for (edge& e : adj[t]) {
      if (lvl[e.to] != -1 || e.cap <= 0) continue;
      lvl[e.to] = lvl[t] + 1;
      bfs.push(e.to);
    }
  }
  if (lvl[SINK] == -1) return false;
  while (dfs(SOURCE, 1 << 30)) {
  }
  return true;
}
void initMaxFlow(int nodes) {
  totalflow = 0;
  adj.clear();
  adj.resize(nodes);
}
void addEdge(int a, int b, int w) {
  adj[a].push_back(edge{b, (int)adj[b].size(), w});
  adj[b].push_back(edge{a, (int)adj[a].size() - 1, 0});
}
const int dr[] = {0, 0, -1, 1}, dc[] = {-1, 1, 0, 0};
int R, C, M, F, S, fw[22][22][22][22];
char gd[23][23];
struct scayger {
  int r, c, t, g;
} sg[22 * 22 * 2 + 1];
bool try1(long long t, bool sgm) {
  initMaxFlow(M + F + R * C * 2 + 3);
  for (int r = 0; r < int(R); r++)
    for (int c = 0; c < int(C); c++)
      addEdge(M + F + 3 + (r * C + c) * 2, M + F + 3 + (r * C + c) * 2 + 1, 1);
  for (int i = 0; i < int(M); i++) addEdge(0, 3 + i, 1);
  for (int i = 0; i < int(F); i++) addEdge(M + 3 + i, 1, 1);
  if (sgm)
    addEdge(0, 2, 1);
  else
    addEdge(2, 1, 1);
  for (int i = 0; i < int(S); i++) {
    scayger& s = sg[i];
    int g = s.g;
    if (g == 0) g = (sgm) ? 1 : 2;
    for (int r = 0; r < int(R); r++)
      for (int c = 0; c < int(C); c++) {
        long long d = fw[r][c][s.r][s.c];
        if (d == -1) continue;
        if (t >= d * s.t) {
          if (g == 1)
            addEdge(2 + i, M + F + 3 + (r * C + c) * 2, 1);
          else
            addEdge(M + F + 3 + (r * C + c) * 2 + 1, 2 + i, 1);
        }
      }
  }
  while (runMaxFlow()) {
  }
  return totalflow == S / 2;
}
bool tryit(long long t) { return try1(t, true) || try1(t, false); }
int main() {
  scanf("%d%d%d%d", &R, &C, &M, &F);
  for (int r = 0; r < int(R); r++) scanf("%s", gd[r]);
  S = M + F + 1;
  for (int i = 0; i < int(S); i++) {
    scayger& s = sg[i];
    scanf("%d%d%d", &s.r, &s.c, &s.t);
    s.r--;
    s.c--;
    if (i == 0)
      s.g = 0;
    else if (i <= M)
      s.g = 1;
    else
      s.g = 2;
  }
  memset(fw, -1, sizeof fw);
  for (int r = 0; r < int(R); r++)
    for (int c = 0; c < int(C); c++)
      if (gd[r][c] == '.') {
        for (int i = 0; i < int(4); i++) {
          int r2 = r + dr[i], c2 = c + dc[i];
          if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C || gd[r2][c2] == '#')
            continue;
          fw[r][c][r2][c2] = fw[r2][c2][r][c] = 1;
        }
        fw[r][c][r][c] = 0;
      }
  for (int kr = 0; kr < int(R); kr++)
    for (int kc = 0; kc < int(C); kc++)
      if (gd[kr][kc] == '.')
        for (int ir = 0; ir < int(R); ir++)
          for (int ic = 0; ic < int(C); ic++)
            if (gd[ir][ic] == '.')
              for (int jr = 0; jr < int(R); jr++)
                for (int jc = 0; jc < int(C); jc++)
                  if (gd[jr][jc] == '.') {
                    int &d1 = fw[ir][ic][kr][kc], &d2 = fw[kr][kc][jr][jc],
                        &d = fw[ir][ic][jr][jc];
                    if (d1 == -1 || d2 == -1) continue;
                    if (d == -1 || d1 + d2 < d) d = d1 + d2;
                  }
  if (S % 2 != 0 || !tryit(LLONG_MAX)) {
    puts("-1");
    return 0;
  }
  long long t0 = -1, t1 = 1000000000LL * (R + C);
  while (t1 - t0 > 1) {
    long long t = (t0 + t1) / 2;
    if (tryit(t))
      t1 = t;
    else
      t0 = t;
  }
  printf("%lld\n", t1);
}
