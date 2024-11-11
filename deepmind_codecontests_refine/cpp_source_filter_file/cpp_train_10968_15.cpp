#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
template <typename T, typename TT>
ostream &operator<<(ostream &s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream &operator<<(ostream &s, vector<T> t) {
  for (int(i) = 0; (i) < (((int)((t).size()))); ++(i)) s << t[i] << " ";
  return s;
}
vector<int> bellmanFord(int n, vector<pair<int, int> > *adj, int src) {
  vector<int> dist(n + 1, 1001001001);
  dist[src] = 0;
  for (int(it) = 0; (it) < (n); ++(it)) {
    bool changed = 0;
    for (int(v) = 1; (v) <= (n); ++(v))
      for (typeof(adj[v].begin()) x = adj[v].begin(); x != adj[v].end(); x++) {
        if (dist[v] + x->second < dist[x->first]) {
          dist[x->first] = dist[v] + x->second;
          changed = 1;
        }
      }
    if (!changed) return dist;
  }
  return vector<int>();
}
vector<int> bfs1(int n, int source, vector<int> *adj) {
  vector<int> odl(n + 1, -1);
  deque<int> q;
  q.push_back(source);
  odl[source] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (typeof(adj[v].begin()) it = adj[v].begin(); it != adj[v].end(); it++)
      if (odl[*it] == -1) {
        odl[*it] = odl[v] + 1;
        q.push_back(*it);
      }
  }
  return odl;
}
vector<pair<int, int> > adjbf[1007];
vector<int> adj[1007], adjtr[1007];
int main() {
  int(n), (m);
  scanf("%d %d", &(n), &(m));
  vector<pair<int, int> > edges;
  for (int(j) = 1; (j) <= (m); ++(j)) {
    int(a), (b);
    scanf("%d %d", &(a), &(b));
    edges.push_back(make_pair(a, b));
    adj[a].push_back(b);
    adjtr[b].push_back(a);
  }
  vector<int> from1 = bfs1(n, 1, adj), ton = bfs1(n, n, adjtr);
  for (int(j) = 1; (j) <= (m); ++(j)) {
    int a = edges[j - 1].first, b = edges[j - 1].second;
    if (from1[a] != -1 && ton[a] != -1 && from1[b] != -1 && ton[b] != -1) {
      adjbf[a].push_back(make_pair(b, 2));
      adjbf[b].push_back(make_pair(a, -1));
    }
  }
  vector<int> dist = bellmanFord(n, adjbf, 1);
  if (dist.empty()) {
    printf("No\n");
  } else {
    printf("Yes\n");
    for (int(j) = 1; (j) <= (m); ++(j)) {
      int a = edges[j - 1].first, b = edges[j - 1].second;
      if (from1[a] != -1 && ton[a] != -1 && from1[b] != -1 && ton[b] != -1) {
        pisz(dist[a] - dist[b]);
      } else {
        pisz(1);
      }
    }
  }
}
