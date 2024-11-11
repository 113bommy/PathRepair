#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v;
  long long w;
  edge(int a = 0, int b = 0, long long c = 0) {
    u = a;
    v = b;
    w = c;
  }
  friend bool operator<(edge a, edge b) { return a.w < b.w; }
};
const int MAX = 100 * 1000;
vector<int> adj[MAX + 10];
vector<int> w[MAX + 10];
bool mrk[MAX + 10];
bool port[MAX + 10];
edge E2[MAX + 10];
edge E[MAX + 10];
int p[MAX + 10];
long long d[MAX + 10];
int n, m, k;
int head;
void read() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    adj[v].push_back(u);
    adj[u].push_back(v);
    w[v].push_back(c);
    w[u].push_back(c);
    E2[i] = edge(u, v, c);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int tmp;
    cin >> tmp;
    port[tmp - 1] = true;
  }
}
void dij() {
  priority_queue<pair<long long, pair<int, int> >,
                 vector<pair<long long, pair<int, int> > >,
                 greater<pair<long long, pair<int, int> > > >
      heap;
  for (int i = 0; i < n; i++)
    if (port[i])
      heap.push(pair<long long, pair<int, int> >(0, pair<int, int>(i, i)));
  while (!heap.empty()) {
    int v, par;
    long long l;
    do {
      if (heap.empty()) return;
      l = heap.top().first;
      v = heap.top().second.first;
      par = heap.top().second.second;
      heap.pop();
    } while (mrk[v]);
    mrk[v] = true;
    p[v] = par;
    d[v] = l;
    for (int i = 0; i < ((int)adj[v].size()); i++)
      if (!mrk[(adj[v][i])])
        heap.push(pair<long long, pair<int, int> >(
            l + w[v][i], pair<int, int>((adj[v][i]), par)));
  }
}
void make_NG() {
  for (int i = 0; i < m; i++)
    if (p[E2[i].u] != p[E2[i].v])
      E[head++] =
          edge(p[E2[i].u], p[E2[i].v], d[E2[i].u] + d[E2[i].v] + E2[i].w);
}
int par[MAX + 10];
int sz[MAX + 10];
void clear() {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
}
int find_P(int a) {
  if (a == par[a]) return a;
  return par[a] = find_P(par[a]);
}
void join(int u, int v) {
  u = find_P(u);
  v = find_P(v);
  if (u == v) return;
  if (sz[v] > sz[u]) swap(u, v);
  sz[u] += sz[v];
  par[v] = u;
}
long long kruskal() {
  long long ret = 0;
  clear();
  sort(E, E + head);
  for (int i = 0; i < head; i++)
    if (find_P(E[i].u) != find_P(E[i].v)) {
      join(E[i].u, E[i].v);
      ret += E[i].w;
    }
  return ret;
}
int main() {
  read();
  dij();
  make_NG();
  cout << kruskal() + d[0] << endl;
  return 0;
}
