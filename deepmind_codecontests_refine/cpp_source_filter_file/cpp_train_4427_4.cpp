#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
long long n, m;
vector<pair<pair<long long, long long>, pair<long long, long long>>> edges;
vector<long long> parent, tam;
long long cc, mst;
vector<bool> enMST;
vector<vector<pair<long long, long long>>> adj;
long long raiz, reloj, l;
vector<long long> tin, tout, altura;
vector<vector<long long>> up, sparseMax;
vector<long long> respuesta;
void make_set() {
  parent.resize(n + 1);
  tam.assign(n + 1, 1);
  for (long long i = 1; i <= n; ++i) parent[i] = i;
}
long long find_set(long long v) {
  if (parent[v] == v) return v;
  return parent[v] = find_set(parent[v]);
}
bool union_sets(long long a, long long b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (tam[a] < tam[b]) swap(a, b);
    parent[b] = a;
    tam[a] += tam[b];
    return true;
  }
  return false;
}
void dfs(long long p, long long a, long long wPA, long long h) {
  tin[a] = reloj++;
  altura[a] = h;
  up[a][0] = p;
  for (long long i = 1; i <= l; ++i) up[a][i] = up[up[a][i - 1]][i - 1];
  sparseMax[a][0] = wPA;
  for (long long i = 1; i <= l; ++i)
    sparseMax[a][i] = max(sparseMax[a][i - 1], sparseMax[up[a][i - 1]][i - 1]);
  for (auto e : adj[a])
    if (e.first != p) dfs(a, e.first, e.second, h + 1);
  tout[a] = reloj++;
}
void precomputo() {
  srand(time(0));
  raiz = (rand() % n) + 1;
  reloj = 0;
  l = ceil(log2(n));
  tin.resize(n + 1);
  tout.resize(n + 1);
  altura.resize(n + 1);
  up.resize(n + 1, vector<long long>(l + 1));
  sparseMax.resize(n + 1, vector<long long>(l + 1));
  dfs(raiz, raiz, -INF, 0);
}
bool esPadre(long long a, long long b) {
  return (tin[a] <= tin[b] && tout[b] <= tout[a]);
}
long long lca(long long a, long long b) {
  if (esPadre(a, b)) return a;
  if (esPadre(b, a)) return b;
  for (long long i = l; i >= 0; --i)
    if (!esPadre(up[a][i], b)) a = up[a][i];
  return up[a][0];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  edges.resize(m + 1);
  edges[0] = {{0, 0}, {0, 0}};
  for (long long i = 1; i <= m; ++i) {
    cin >> edges[i].second.first >> edges[i].second.second >>
        edges[i].first.first;
    edges[i].first.second = i;
  }
  sort(begin(edges), end(edges));
  make_set();
  cc = n;
  mst = 0;
  enMST.assign(m + 1, false);
  adj.resize(n + 1);
  for (auto e : edges) {
    if (cc == 1) break;
    if (union_sets(e.second.first, e.second.second)) {
      --cc;
      mst += e.first.first;
      enMST[e.first.second] = true;
      adj[e.second.first].push_back({e.second.second, e.first.first});
      adj[e.second.second].push_back({e.second.first, e.first.first});
    }
  }
  precomputo();
  respuesta.resize(m + 1);
  for (auto e : edges) {
    if (enMST[e.first.second]) {
      respuesta[e.first.second] = mst;
      continue;
    }
    long long viejaW = -INF;
    long long nuevaW = e.first.first, ie = e.first.second;
    long long a = e.second.first, b = e.second.second;
    long long lcaAB = lca(a, b);
    for (long long i = l; i >= 0; --i) {
      if (altura[up[a][l]] <= altura[lcaAB]) {
        viejaW = max(viejaW, sparseMax[a][l]);
        a = up[a][l];
      }
      if (altura[up[b][l]] <= altura[lcaAB]) {
        viejaW = max(viejaW, sparseMax[b][l]);
        b = up[b][l];
      }
    }
    respuesta[ie] = mst + nuevaW - viejaW;
  }
  for (long long i = 1; i <= m; ++i) cout << respuesta[i] << '\n';
  return 0;
}
