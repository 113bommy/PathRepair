#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
template <typename Cap, typename Cost, int V, int E>
struct MinCostFlow {
  int last[V + 1], nx[2 * E + 2], ver[2 * E + 2], pr[V + 1], S, T, ec;
  Cap cap[2 * E + 2], curcap[V + 1];
  Cost cost[2 * E + 2], ds[2 * E + 2];
  queue<pair<Cost, Cap> > q;
  inline void reset() {
    memset(last, -1, sizeof(last));
    ec = 0;
    while (!q.empty()) q.pop();
  }
  inline void addEdge(int v, int w, int cp, int cs) {
    ver[ec] = w;
    cap[ec] = cp;
    cost[ec] = cs;
    nx[ec] = last[v];
    last[v] = ec++;
    ver[ec] = v;
    cap[ec] = 0;
    cost[ec] = -cs;
    nx[ec] = last[w];
    last[w] = ec++;
  }
  inline bool dijkstra() {
    memset(pr, -1, sizeof(pr));
    memset(ds, 63, sizeof(ds));
    memset(curcap, 0, sizeof(curcap));
    Cost inf;
    memset(&inf, 63, sizeof(inf));
    curcap[S] = inf;
    ds[S] = 0;
    while (!q.empty()) q.pop();
    q.push(make_pair(0, S));
    pr[S] = -1;
    while (!q.empty()) {
      int v = q.front().second;
      if (q.front().first != ds[v]) {
        q.pop();
        continue;
      }
      q.pop();
      for (int w = last[v]; w >= 0; w = nx[w]) {
        if (cap[w] && ds[v] + cost[w] < ds[ver[w]]) {
          pr[ver[w]] = w;
          ds[ver[w]] = ds[v] + cost[w];
          q.push(make_pair(ds[ver[w]], ver[w]));
          if (cap[w] < curcap[v])
            curcap[ver[w]] = cap[w];
          else
            curcap[ver[w]] = curcap[v];
        }
      }
    }
    return curcap[T] > 0;
  }
  inline pair<Cap, Cost> minCostFlow() {
    Cap fl = 0;
    Cost cs = 0;
    while (dijkstra()) {
      Cap add = curcap[T];
      fl += add;
      cs += ds[T] * add;
      int a = T, b = pr[T];
      while (b != -1) {
        cap[b] -= add;
        cap[b ^ 1] += add;
        a = ver[b ^ 1];
        b = pr[a];
      }
    }
    return make_pair(fl, cs);
  }
};
int a, b, c, d, n, m, k;
MinCostFlow<int, int, 6500, 200002> q;
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
int mas[82][82];
int main() {
  scanf("%d%d", &n, &m);
  for (int _n((n)-1), i(0); i <= _n; i++) {
    for (int _n((m)-1), j(0); j <= _n; j++) {
      scanf("%d", &mas[i][j]);
    }
  }
  q.reset();
  q.S = n * m;
  q.T = q.S + 1;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    for (int _n((m)-1), j(0); j <= _n; j++) {
      if ((i + j) % 2) continue;
      for (int _n((4) - 1), z(0); z <= _n; z++) {
        int ni = i + di[z];
        int nj = j + dj[z];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        c = 1;
        if (mas[ni][nj] == mas[i][j]) c = 0;
        q.addEdge(i * m + j, ni * m + nj, 1, c);
      }
    }
  }
  for (int _n((n)-1), i(0); i <= _n; i++) {
    for (int _n((m)-1), j(0); j <= _n; j++) {
      if ((i + j) % 2)
        q.addEdge(i * m + j, q.T, 1, 0);
      else
        q.addEdge(q.S, i * m + j, 1, 0);
    }
  }
  pair<int, int> t = q.minCostFlow();
  printf("%d\n", t.second);
}
