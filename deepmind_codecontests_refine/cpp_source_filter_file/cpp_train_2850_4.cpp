#include <bits/stdc++.h>
using namespace std;
const int MAXN = (2 << 17);
struct edge {
  int from, to, idx, cap, rev;
};
struct vertex {
  int vv, diff;
  vertex(){};
  vertex(int _vv, int _diff) {
    vv = _vv;
    diff = _diff;
  }
  bool operator<(vertex t1) const { return diff > t1.diff; }
};
int in[MAXN];
int maxCap[MAXN];
int inCap[MAXN];
int used[MAXN], N, M;
edge E[MAXN];
vector<edge> v[MAXN];
priority_queue<vertex> q;
void scan() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; ++i) {
    scanf("%d%d%d", &E[i].from, &E[i].to, &E[i].cap);
    E[i].idx = i;
    E[i].rev = 0;
    v[E[i].from].push_back(E[i]);
    E[i].rev = 1;
    swap(E[i].from, E[i].to);
    v[E[i].from].push_back(E[i]);
    maxCap[E[i].from] += E[i].cap;
    maxCap[E[i].to] += E[i].cap;
    E[i].rev = -1;
  }
}
void dijkstra() {
  q.push(vertex(1, 0));
  while (!q.empty()) {
    vertex vrt = q.top();
    q.pop();
    int i = vrt.vv;
    if (used[i] || i == N) continue;
    used[i] = 1;
    for (int j = 0; j < v[i].size(); ++j)
      if (!used[v[i][j].to]) {
        inCap[v[i][j].to] += v[i][j].cap;
        E[v[i][j].idx].rev = v[i][j].rev;
        q.push(vertex(v[i][j].to, maxCap[v[i][j].to] - inCap[v[i][j].to]));
      }
  }
}
void solve() {
  dijkstra();
  for (int i = 0; i < M; ++i) {
    if (E[i].rev == -1) E[i].rev = 0;
    printf("%d\n", E[i].rev);
  }
}
int main() {
  scan();
  solve();
}
