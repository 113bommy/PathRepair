#include <bits/stdc++.h>
using namespace std;
int atst[1001][1001];
int art[1001][1001];
set<int> krpr[1001];
int c[1001];
vector<int> kr[1001];
void dijk(int is, int deg) {
  multimap<int, int> pq;
  int* artp = art[is];
  artp[is] = 1;
  for (set<int>::iterator it = krpr[is].begin(); it != krpr[is].end(); it++) {
    artp[*it] = atst[is][*it];
    pq.insert(make_pair(atst[is][*it], *it));
  }
  while (!pq.empty()) {
    int v = pq.begin()->second;
    int d = pq.begin()->first;
    pq.erase(pq.begin());
    if (artp[v] != d) continue;
    if (d > deg) break;
    kr[is].push_back(v);
    for (set<int>::iterator it = krpr[v].begin(); it != krpr[v].end(); it++) {
      if (artp[*it] == 0 ||
          artp[*it] > d + atst[v][*it] && ((int)(d + atst[v][*it])) > 0) {
        artp[*it] = d + atst[v][*it];
        pq.insert(make_pair(artp[*it], *it));
      }
    }
  }
  pq.clear();
}
int main() {
  int i, n, m, x, y, u, v, w, t;
  scanf("%d%d%d%d", &n, &m, &x, &y);
  for (i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &w);
    if (atst[u][v] == 0 || atst[u][v] > w) atst[u][v] = atst[v][u] = w;
    krpr[u].insert(v);
    krpr[v].insert(u);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &t, c + i);
    dijk(i, t);
  }
  if (x == y) {
    printf("0\n");
    return 0;
  }
  multimap<long long, int> pq;
  long long dist[1001];
  fill(dist, dist + 1001, 0);
  dist[x] = 1;
  for (i = 0; i < kr[x].size(); i++) {
    dist[kr[x][i]] = c[x];
    pq.insert(make_pair(c[x], kr[x][i]));
  }
  while (!pq.empty()) {
    int v = pq.begin()->second;
    long long d = pq.begin()->first;
    pq.erase(pq.begin());
    if (dist[v] != d) continue;
    if (v == y) break;
    for (w = 0; w < kr[v].size(); w++) {
      if (dist[kr[v][w]] == 0 || dist[kr[v][w]] > d + c[v]) {
        dist[kr[v][w]] = d + c[v];
        pq.insert(make_pair(d + c[v], kr[v][w]));
      }
    }
  }
  if (dist[y] == 0)
    printf("-1\n");
  else
    printf("%I64D\n", dist[y]);
  return 0;
}
