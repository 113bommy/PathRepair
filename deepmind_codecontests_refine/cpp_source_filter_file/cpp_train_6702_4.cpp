#include <bits/stdc++.h>
using namespace std;
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
struct Graph {
  vector<vector<int> > es, inv, fs;
  vector<vector<double> > ps;
  int n;
  void build(int _n) {
    n = _n;
    es = inv = fs = vector<vector<int> >(n);
    ps = vector<vector<double> >(n);
  }
  void adde(int s, int t, int c, double p) {
    es[s].push_back(t), es[t].push_back(s);
    inv[s].push_back(((int)(es[t]).size()) - 1),
        inv[t].push_back(((int)(es[s]).size()) - 1);
    ps[s].push_back(p), ps[t].push_back(-p);
    fs[s].push_back(c), fs[t].push_back(0);
  }
  vector<double> dist;
  vector<int> js, used;
  vector<int> take, prevEdgeId;
  pair<int, double> flow(int S, int T) {
    dist.resize(n);
    js.resize(n);
    used.resize(n);
    take.resize(n);
    prevEdgeId.resize(n);
    for (int i = 0; i < n; i++) dist[i] = (1e18);
    dist[S] = 0;
    while (1) {
      bool ch = 0;
      for (int i = 0; i < n; i++) {
        for (int it = 0; it < ((int)(es[i]).size()); it++) {
          int u = es[i][it];
          if (fs[i][it] && dist[u] > dist[i] + ps[i][it]) {
            dist[u] = dist[i] + ps[i][it], ch = 1;
          }
        }
      }
      if (!ch) break;
    }
    for (int i = 0; i < n; i++) js[i] = dist[i];
    pair<int, double> res(0, 0);
    while (1) {
      for (int i = 0; i < n; i++) dist[i] = (1e18), used[i] = 0, take[i] = 0;
      dist[S] = 0, take[S] = 2 * n;
      for (int iter = 0; iter < n; iter++) {
        int v = -1;
        for (int i = 0; i < n; i++)
          if (!used[i] && (v == -1 || (dist[v] > dist[i]))) v = i;
        if (v == -1) break;
        used[v] = 1;
        for (int it = 0; it < ((int)(es[v]).size()); it++) {
          int u = es[v][it];
          if (fs[v][it] && dist[u] > dist[v] + ps[v][it] + js[v] - js[u]) {
            dist[u] = dist[v] + ps[v][it] + js[v] - js[u];
            take[u] = min(take[v], fs[v][it]);
            prevEdgeId[u] = inv[v][it];
          }
        }
      }
      if (dist[T] >= (1e18) / 2) break;
      int push = take[T];
      res.first += push;
      res.second += push * (dist[T] + js[T]);
      for (int v = T; v != S; v = es[v][prevEdgeId[v]]) {
        fs[v][prevEdgeId[v]] += push;
        fs[es[v][prevEdgeId[v]]][inv[v][prevEdgeId[v]]] -= push;
      }
      for (int i = 0; i < n; i++) js[i] += dist[i];
    }
    return res;
  }
} g;
const int maxn = 400;
pair<int, int> points[maxn];
int main() {
  srand(rdtsc());
  int n;
  while (scanf("%d", &n) >= 1) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &points[i].second, &points[i].first);
    }
    sort(points, points + n);
    reverse(points, points + n);
    g.build(2 * n + 2);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (points[i].first <= points[j].first) continue;
        g.adde(i + 2, j + n + 2, 1,
               sqrt(0.0 +
                    ((points[i].first - points[j].first) *
                     (points[i].first - points[j].first)) +
                    ((points[i].second - points[j].second) *
                     (points[i].second - points[j].second))));
      }
    }
    for (int i = 0; i < n; i++) {
      g.adde(0, i + 2, 2, 0);
      g.adde(i + n + 2, 1, 1, 0);
    }
    pair<int, double> res = g.flow(0, 1);
    if (res.first != n - 1)
      printf("-1\n");
    else {
      printf("%.18lf\n", res.second);
    }
  }
  return 0;
}
