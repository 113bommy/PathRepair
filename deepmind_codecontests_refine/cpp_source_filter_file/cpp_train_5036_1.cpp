#include <bits/stdc++.h>
using namespace std;
const int MAXV = 2e5 + 10;
const int MAXE = 2e5 + 10;
int v, e;
int wt[MAXV];
int deg_in[MAXV];
struct Edge {
  int t, w, id;
};
vector<Edge> E[MAXV];
int ans[MAXE];
int main() {
  scanf("%d%d", &v, &e);
  for (int i = 1; i <= e; ++i) {
    int s, t, w;
    scanf("%d%d%d", &s, &t, &w);
    wt[s] += w, wt[t] += w;
    E[s].push_back({t, w, i});
    E[t].push_back({s, w, -i});
  }
  for (int i = 1; i <= v; ++i) wt[i] >>= 1;
  static bool fucked[MAXV];
  static int Q[MAXV];
  int lQ = 0;
  fucked[Q[lQ++] = 1] = true;
  for (int i = 0; i < lQ; ++i) {
    int s = Q[i];
    for (auto e : E[s]) {
      int t, w, id;
      t = e.t, w = e.w, id = e.id;
      if (fucked[t]) continue;
      ans[abs(id)] = id < 0;
      deg_in[t] += w;
      if (deg_in[t] == wt[t]) fucked[Q[lQ++] = t] = true;
    }
  }
  for (int i = 1; i <= e; ++i) printf("%d\n", ans[i]);
  return 0;
}
