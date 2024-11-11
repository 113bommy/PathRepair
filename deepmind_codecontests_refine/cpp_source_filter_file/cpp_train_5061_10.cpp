#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int n, m, match[100005], dist[100005];
int nod, edg, start, thresh;
vector<pair<int, int> > gr[605];
int val[605], km[605];
int doori[605][605];
void reset() {
  int i;
  for (i = 0; i <= n + m + 1; i++) {
    v[i].clear();
    match[i] = 0;
    dist[i] = 0;
  }
}
bool bfs() {
  int i, u;
  queue<int> Q;
  for (i = 1; i <= n; i++) {
    if (match[i] == 0) {
      dist[i] = 0;
      Q.push(i);
    } else
      dist[i] = INT_MAX;
  }
  dist[0] = INT_MAX;
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    if (u != 0) {
      for (i = 0; i < v[u].size(); i++) {
        int ed = v[u][i];
        if (dist[match[ed]] == INT_MAX) {
          dist[match[ed]] = dist[u] + 1;
          Q.push(match[ed]);
        }
      }
    }
  }
  return (dist[0] != INT_MAX);
}
bool dfs(int u) {
  int i;
  if (u == 0) return true;
  for (i = 0; i < v[u].size(); i++) {
    int ed = v[u][i];
    if (dist[match[ed]] == dist[u] + 1 && dfs(match[ed])) {
      match[ed] = u;
      match[u] = ed;
      return true;
    }
  }
  dist[u] = INT_MAX;
  return false;
}
int hopcroft_karp() {
  int matching = 0, i;
  while (bfs())
    for (i = 1; i <= n; i++)
      if (match[i] == 0 && dfs(i)) matching++;
  return matching;
}
int solve(int x) {
  n = start, m = nod;
  reset();
  for (int i = 1; i <= start; i++) {
    for (int j = 1; j <= nod; j++) {
      if (doori[val[i]][j] <= x) v[i].push_back(start + j);
    }
  }
  if (hopcroft_karp() >= thresh) return 1;
  return 0;
}
void dijkishtra(int s) {
  km[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  pq.push(make_pair(0, s));
  while (!pq.empty()) {
    pair<int, int> y = pq.top();
    pq.pop();
    int ed = y.second, w = y.first;
    for (int i = 0; i < gr[ed].size(); i++) {
      pair<int, int> child = gr[ed][i];
      if (km[child.first] > w + child.second) {
        km[child.first] = w + child.second;
        pq.push(make_pair(km[child.first], child.first));
      }
    }
  }
}
int main() {
  scanf("%d", &nod), scanf("%d", &edg);
  scanf("%d", &start), scanf("%d", &thresh);
  for (int i = 1; i <= start; i++) scanf("%d", &val[i]);
  for (int i = 0; i < edg; i++) {
    int p, q, r;
    scanf("%d", &p), scanf("%d", &q);
    scanf("%d", &r);
    gr[p].push_back(make_pair(q, r));
    gr[q].push_back(make_pair(p, r));
  }
  for (int i = 1; i <= start; i++) {
    for (int j = 0; j <= nod; j++) km[j] = INT_MAX;
    dijkishtra(val[i]);
    for (int j = 1; j <= nod; j++) doori[val[i]][j] = km[j];
  }
  int low = 0, high = 1731311, ans;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (solve(mid)) {
      ans = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
