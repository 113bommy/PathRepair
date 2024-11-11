#include <bits/stdc++.h>
using namespace std;
const int MAX = 60005;
const int S = 0, T = 1;
struct stre {
  int node, kap, poz;
};
vector<pair<int, int> > V[MAX];
int bio[MAX];
int n, e;
vector<vector<int> > Ciklusi;
int kolko[MAX];
map<pair<int, int>, int> Boja;
int postoji[MAX];
int pozboj[MAX];
namespace Dinic {
const int MAXV = MAX;
const int MAXE = MAX;
const long long oo = 1e18;
int V, E;
int last[MAXV], dist[MAXV], curr[MAXV];
int next[MAXE], adj[MAXE];
long long cap[MAXE];
void init(int n) {
  V = n;
  E = 0;
  for (int i = 0; i < V; i++) last[i] = -1;
}
void edge(int x, int y, long long c1, long long c2) {
  assert(x < V && y < V);
  adj[E] = y;
  cap[E] = c1;
  next[E] = last[x];
  last[x] = E++;
  adj[E] = x;
  cap[E] = c2;
  next[E] = last[y];
  last[y] = E++;
}
long long push(int x, int sink, long long flow) {
  if (x == sink) return flow;
  for (int &e = curr[x]; e != -1; e = next[e]) {
    int y = adj[e];
    if (cap[e] && dist[x] + 1 == dist[y])
      if (long long f = push(y, sink, min(flow, cap[e])))
        return cap[e] -= f, cap[e ^ 1] += f, f;
  }
  return 0;
}
long long run(int src, int sink) {
  long long ret = 0;
  for (;;) {
    for (int i = 0; i < V; i++) curr[i] = last[i];
    for (int i = 0; i < V; i++) dist[i] = -1;
    queue<int> Q;
    Q.push(src), dist[src] = 0;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int e = last[x]; e != -1; e = next[e]) {
        int y = adj[e];
        if (cap[e] && dist[y] == -1) Q.push(y), dist[y] = dist[x] + 1;
      }
    }
    if (dist[sink] == -1) break;
    while (long long f = push(src, sink, oo)) ret += f;
  }
  return ret;
}
}  // namespace Dinic
vector<int> Stek;
void UbaciCik(int node) {
  vector<int> Tmp;
  for (int i = (int)Stek.size() - 1; i >= 0; i--) {
    Tmp.push_back(Stek[i]);
    if (Stek[i] == node) break;
  }
  vector<int> C;
  for (int i = 0; i < (int)Tmp.size(); i++)
    C.push_back(Boja[pair<int, int>(Tmp[i], Tmp[(i + 1) % Tmp.size()])]);
  Ciklusi.push_back(C);
}
int br = 0;
void Dfs(int node, int prosli) {
  bio[node] = 2;
  Stek.push_back(node);
  for (auto it : V[node]) {
    br++;
    assert(br < 1e7);
    if (bio[it.first] == 2 && it.first != prosli)
      UbaciCik(it.first);
    else if (!bio[it.first])
      Dfs(it.first, node);
  }
  bio[node] = 1;
  Stek.pop_back();
}
void StaviEdge(int a, int b, int c) { Dinic::edge(a, b, c, 0); }
int main() {
  scanf("%d%d", &n, &e);
  for (int i = 0; i < e; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    c--;
    V[a].push_back(pair<int, int>(b, c));
    V[b].push_back(pair<int, int>(a, c));
    Boja[pair<int, int>(a, b)] = c;
    Boja[pair<int, int>(b, a)] = c;
    kolko[c]++;
    postoji[c] = 1;
  }
  for (int i = 0; i < n; i++)
    if (!bio[i]) Dfs(i, -1);
  for (auto it : Ciklusi)
    for (auto it2 : it) kolko[it2]--;
  int rje = 0;
  for (int i = 0; i < MAX; i++)
    if (kolko[i]) rje++;
  int brnode = 2;
  Dinic::init(MAX);
  for (int i = 0; i < MAX; i++)
    if (postoji[i] && !kolko[i]) {
      pozboj[i] = brnode;
      StaviEdge(brnode++, T, 1);
    }
  for (auto it : Ciklusi) {
    for (auto it2 : it)
      if (!kolko[it2]) {
        StaviEdge(brnode, pozboj[it2], 1);
      }
    StaviEdge(S, brnode++, (int)it.size() - 1);
  }
  printf("%lld\n", rje + Dinic::run(S, T));
  return 0;
}
