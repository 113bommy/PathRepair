#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 815;
struct Edge {
  int v, rev, c;
  long long koszt;
  Edge(int vv, int rrev, int cc, long long kkoszt)
      : v(vv), rev(rrev), c(cc), koszt(kkoszt) {}
  Edge() {}
};
vector<Edge> kraw[N];
int parent[N], parent_kraw[N];
long long used[N], dist[N], pot[N];
void AddEdge(int a, int b, int c, long long koszt) {
  kraw[a].push_back(Edge(b, (int)kraw[b].size() + (a == b), c, koszt));
  kraw[b].push_back(Edge(a, (int)kraw[a].size() - 1, 0, -koszt));
}
pair<int, long long> MinCostMaxFlow(int beg, int end, int n) {
  int res = 0;
  long long koszt = 0;
  for (int i = 0; i < (n); ++i) pot[i] = 0;
  while (1) {
    for (int i = 0; i < (n); ++i) dist[i] = INF, used[i] = 0;
    dist[beg] = 0;
    for (int k = 0; k < (n); ++k) {
      int best = -1;
      for (int i = 0; i < (n); ++i)
        if (!used[i] && (best == -1 || dist[i] < dist[best])) best = i;
      used[best] = 1;
      if (dist[best] == INF) break;
      for (__typeof((kraw[best]).begin()) it = (kraw[best]).begin();
           it != (kraw[best]).end(); ++it)
        if (it->c > 0) {
          long long x = it->koszt - pot[it->v] + pot[best];
          if (dist[it->v] > dist[best] + x) {
            dist[it->v] = dist[best] + x;
            parent[it->v] = best;
            parent_kraw[it->v] = it - kraw[best].begin();
          }
        }
    }
    if (dist[end] == INF) break;
    for (int i = 0; i < (n); ++i) dist[i] += pot[i], pot[i] = dist[i];
    int cap = 1000000;
    int x = end;
    do {
      cap = min(cap, kraw[parent[x]][parent_kraw[x]].c);
      x = parent[x];
    } while (x != beg);
    res += cap;
    x = end;
    do {
      koszt += kraw[parent[x]][parent_kraw[x]].koszt * (long long)cap;
      kraw[parent[x]][parent_kraw[x]].c -= cap;
      kraw[x][kraw[parent[x]][parent_kraw[x]].rev].c += cap;
      x = parent[x];
    } while (x != beg);
  }
  return make_pair(res, koszt);
}
const long long skala = 1000000000;
long long dajkoszt(pair<int, int> a, pair<int, int> b) {
  return (long long)(hypotl(a.first - b.first, a.second - b.second) * skala);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > v;
  for (int i = 0; i < (n); ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    v.push_back(make_pair(a, b));
  }
  for (int i = 0; i < (n); ++i) AddEdge(0, i + 1, 2, 0);
  for (int i = 0; i < (n); ++i) AddEdge(i + (n + 1), 2 * n + 1, 1, 0);
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (n); ++j)
      if (v[i].second > v[j].second)
        AddEdge(i + 1, j + (n + 1), 1, dajkoszt(v[i], v[j]));
  pair<int, long long> p = MinCostMaxFlow(0, 2 * n + 1, 2 * n + 2);
  if (p.first != n - 1)
    printf("-1\n");
  else
    printf("%.12Lf\n", (long double)p.second / skala);
  return 0;
}
