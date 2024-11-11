#include <bits/stdc++.h>
using namespace std;
const int N = 55555;
const int Q = 255555;
const int M = 401000;
char op[Q];
int qa[Q], qb[Q], ua[M], ub[M];
int from_small[N], n, m, nq, deg[N], on, first_on[N], edge_state[M],
    dot_state[N];
vector<pair<int, int> > edge;
vector<pair<int, int> > G[N];
int get_edge_id(pair<int, int> z) {
  if (z.first > z.second) swap(z.first, z.second);
  return lower_bound(edge.begin(), edge.end(), z) - edge.begin();
}
void modify_dot(int u, int st) {
  dot_state[u] = st;
  int dt = st == 1 ? 1 : -1;
  for (__typeof((G[u]).begin()) it = (G[u]).begin(); it != (G[u]).end(); it++) {
    int v = it->first;
    int id = it->second;
    if (!edge_state[id]) continue;
    from_small[v] += dt;
  }
}
void modify_edge(int u, int v, int st) {
  int id = get_edge_id(pair<int, int>(u, v));
  edge_state[id] = st;
  if (deg[u] > deg[v]) swap(u, v);
  if (dot_state[u] == 1) {
    from_small[v] += st == 1 ? 1 : -1;
  }
}
int query_dot(int u) {
  int ret = from_small[u];
  for (__typeof((G[u]).begin()) it = (G[u]).begin(); it != (G[u]).end(); it++) {
    int v = it->first;
    int id = it->second;
    if (edge_state[id] == 0) continue;
    ret += dot_state[v];
  }
  return ret;
}
void work() {
  sort(edge.begin(), edge.end());
  edge.erase(unique(edge.begin(), edge.end()), edge.end());
  int sz = (int)edge.size();
  for (int i = 0; i < sz; i++) {
    deg[edge[i].first]++;
    deg[edge[i].second]++;
  }
  for (int i = 0; i < sz; i++) {
    int u = edge[i].first;
    int v = edge[i].second;
    if (deg[u] > deg[v]) swap(u, v);
    G[u].push_back(pair<int, int>(v, i));
  }
  for (int i = 0; i < m; i++) {
    int id = get_edge_id(pair<int, int>(ua[i], ub[i]));
    edge_state[id] = 1;
  }
  for (int i = 0; i < on; i++) {
    modify_dot(first_on[i], 1);
  }
  for (int i = 0; i < nq; i++) {
    int u = qa[i];
    int v = qb[i];
    if (op[i] == 'O') {
      modify_dot(u, 1);
    } else if (op[i] == 'F') {
      modify_dot(u, 0);
    } else if (op[i] == 'A') {
      modify_edge(u, v, 1);
    } else if (op[i] == 'D') {
      modify_edge(u, v, 0);
    } else {
      printf("%d\n", query_dot(u));
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &nq);
  scanf("%d", &on);
  for (int i = 0; i < on; i++) {
    scanf("%d", &first_on[i]);
    first_on[i]--;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &ua[i], &ub[i]);
    ua[i]--;
    ub[i]--;
    if (ua[i] > ub[i]) swap(ua[i], ub[i]);
    edge.push_back(pair<int, int>(ua[i], ub[i]));
  }
  for (int i = 0; i < nq; i++) {
    char s[3];
    scanf("%s", s);
    op[i] = s[0];
    if (op[i] == 'A' || op[i] == 'D') {
      scanf("%d%d", &qa[i], &qb[i]);
      qa[i]--;
      qb[i]--;
      if (qa[i] > qb[i]) swap(qa[i], qb[i]);
      edge.push_back(pair<int, int>(qa[i], qb[i]));
    } else {
      scanf("%d", &qa[i]);
      qa[i]--;
    }
  }
  work();
  return 0;
}
