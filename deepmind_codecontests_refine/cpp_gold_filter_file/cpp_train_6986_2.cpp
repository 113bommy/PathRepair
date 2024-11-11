#include <bits/stdc++.h>
using namespace std;
void die() {
  cout << -1 << endl;
  exit(0);
}
const int limit = 1005;
int n;
int flujo[limit][limit], capacidad[limit][limit], coste[limit][limit];
int potencial[limit], dist[limit], anterior[limit];
vector<int> g[limit];
int esperado;
const int infinito = 1000000000;
int ini = limit - 2, fin = limit - 1;
int maxflowmincost() {
  int totalflujo = 0;
  int totalcoste = 0;
  for (;;) {
    for (int i = 0; i < n; i++) dist[i] = infinito;
    dist[ini] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > >
        q;
    q.push(pair<int, int>(0, ini));
    while (not q.empty()) {
      pair<int, int> p = q.top();
      q.pop();
      int u = p.second;
      int du = p.first;
      if (du == dist[u]) {
        vector<int> &ar = g[u];
        for (int i = 0; i < int(ar.size()); i++) {
          int v = ar[i];
          if (flujo[u][v] >= 0 and capacidad[u][v] > flujo[u][v] and
              dist[v] > du + coste[u][v] + potencial[u] - potencial[v]) {
            dist[v] = du + coste[u][v] + potencial[u] - potencial[v];
            q.push(pair<int, int>(dist[v], v));
            anterior[v] = u;
          } else if (flujo[u][v] < 0 and
                     dist[v] > du - coste[v][u] + potencial[u] - potencial[v]) {
            dist[v] = du - coste[v][u] + potencial[u] - potencial[v];
            q.push(pair<int, int>(dist[v], v));
            anterior[v] = u;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) potencial[i] += dist[i];
    if (dist[fin] == infinito) {
      if (totalflujo == esperado)
        return totalcoste;
      else
        die();
    }
    int u = fin;
    int minimo = infinito;
    while (u != ini) {
      int antu = anterior[u];
      if (flujo[antu][u] >= 0)
        minimo = min(minimo, capacidad[antu][u] - flujo[antu][u]);
      else
        minimo = min(minimo, -flujo[antu][u]);
      u = antu;
    }
    totalflujo += minimo;
    u = fin;
    while (u != ini) {
      int antu = anterior[u];
      if (flujo[antu][u] >= 0)
        totalcoste += coste[antu][u] * minimo;
      else
        totalcoste -= coste[u][antu] * minimo;
      flujo[antu][u] += minimo;
      flujo[u][antu] -= minimo;
      u = antu;
    }
  }
}
void anyade(int u, int v, int c, int cost) {
  capacidad[u][v] = c;
  g[u].push_back(v);
  g[v].push_back(u);
  coste[u][v] = cost;
}
void precompute(vector<int> g[limit], int father[limit], int numnodes[limit],
                int u, int p) {
  numnodes[u] = 1;
  father[u] = p;
  vector<int> &ar = g[u];
  vector<int> nextar;
  for (int i = 0; i < int(ar.size()); i++) {
    int v = ar[i];
    if (v != p) {
      nextar.push_back(v);
      precompute(g, father, numnodes, v, u);
      numnodes[u] += numnodes[v];
    }
  }
  ar = nextar;
}
void read(vector<int> g[limit], int father[limit], int numnodes[limit],
          int root) {
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  precompute(g, father, numnodes, root, 0);
}
int precomputequeries(vector<int> g[limit], int isselect[limit],
                      int numselect[limit], int u) {
  vector<int> &ar = g[u];
  int ret = 0;
  for (int i = 0; i < int(ar.size()); i++) {
    int v = ar[i];
    ret += precomputequeries(g, isselect, numselect, v);
  }
  if (isselect[u]) {
    if (numselect[u] < ret) die();
    numselect[u] -= ret;
    return numselect[u] + ret;
  }
  return ret;
}
void readqueries(vector<int> g[limit], int isselect[limit],
                 int numselect[limit], int root) {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, k;
    cin >> u >> k;
    isselect[u] = 1;
    numselect[u] = k;
  }
  precomputequeries(g, isselect, numselect, root);
}
int getancestor(int u, int father[limit], int isselect[limit],
                int numselect[limit]) {
  while (u != 0) {
    if (isselect[u]) {
      if (numselect[u] > 0) return u;
      return 0;
    }
    u = father[u];
  }
  return u;
}
int root[2];
vector<int> G[2][limit];
int father[2][limit];
int a[limit];
int numelem[2][limit];
int numnodes[2][limit];
int isselect[2][limit];
int numselect[2][limit];
int sol;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> root[0] >> root[1];
  for (int u = 1; u <= n; u++) cin >> a[u];
  for (int i = 0; i < 2; i++) read(G[i], father[i], numnodes[i], root[i]);
  for (int i = 0; i < 2; i++)
    readqueries(G[i], isselect[i], numselect[i], root[i]);
  int esperadoout = 0;
  for (int u = 1; u <= n; u++) {
    int val = a[u];
    if (isselect[0][u]) {
      anyade(ini, u, numselect[0][u], 0);
      esperado += numselect[0][u];
    }
    if (isselect[1][u]) {
      anyade(500 + u, fin, numselect[1][u], 0);
      esperadoout += numselect[1][u];
    }
    anyade(u, 500 + u, 1, 100000 - val);
    int p0 = getancestor(u, father[0], isselect[0], numselect[0]);
    int p1 = getancestor(u, father[1], isselect[1], numselect[1]);
    if (p0 != u) anyade(p0, u, 1, 0);
    if (p1 != u) anyade(500 + u, 500 + p1, 1, 0);
  }
  n = limit;
  if (esperado != esperadoout) die();
  sol = maxflowmincost();
  sol = esperado * 100000 - sol;
  cout << sol << endl;
}
