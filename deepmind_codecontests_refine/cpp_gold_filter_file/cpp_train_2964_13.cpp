#include <bits/stdc++.h>
using namespace std;
const int limite = 1000000;
int n;
vector<pair<int, int> > g[limite];
long long int numnodos[limite];
long long int precomputo[limite];
int nc = 0, lenc = 0;
int c[limite];
long long int d[limite];
int cc[limite];
int dd[limite];
int visto[limite];
bool buscaciclo(int u, int p, int prof) {
  if (visto[u]) {
    int icc = prof - 1;
    while (cc[icc] != u) icc--;
    for (int i = icc; i < prof; i++) {
      c[i - icc] = cc[i];
      d[i - icc] = dd[i];
      nc++;
      lenc += dd[i];
    }
    return true;
  }
  visto[u] = 1;
  cc[prof] = u;
  vector<pair<int, int> > &ar = g[u];
  for (int i = 0; i < int(ar.size()); i++) {
    int v = ar[i].first;
    dd[prof] = ar[i].second;
    if (v != p and buscaciclo(v, u, prof + 1)) return true;
  }
  return false;
}
void eliminaadyacente(int u, int elim) {
  vector<pair<int, int> > &ar = g[u];
  vector<pair<int, int> > nextar;
  for (int i = 0; i < int(ar.size()); i++)
    if (elim != ar[i].first) nextar.push_back(ar[i]);
  ar = nextar;
}
void quitapadre(int u, int p) {
  vector<pair<int, int> > &ar = g[u];
  vector<pair<int, int> > nextar;
  for (int i = 0; i < int(ar.size()); i++) {
    int v = ar[i].first;
    if (v != p) {
      nextar.push_back(ar[i]);
      quitapadre(v, u);
    }
  }
  ar = nextar;
}
void precomputa(int u) {
  vector<pair<int, int> > &ar = g[u];
  numnodos[u] = 1;
  for (int i = 0; i < int(ar.size()); i++) {
    int v = ar[i].first;
    long long int t = ar[i].second;
    precomputa(v);
    numnodos[u] += numnodos[v];
    precomputo[u] += precomputo[v] + numnodos[v] * t;
  }
}
long long int precomputodebajo(int ic) {
  int u = c[ic];
  vector<pair<int, int> > &ar = g[u];
  long long int pre = 0;
  for (int i = 0; i < int(ar.size()); i++) {
    int v = ar[i].first;
    long long int t = ar[i].second;
    if (v != c[(ic + 1) % nc] and v != c[(ic - 1 + nc) % nc])
      pre += precomputo[v] + numnodos[v] * t;
  }
  return pre;
}
long long int numnodosdebajo(int ic) {
  int u = c[ic];
  vector<pair<int, int> > &ar = g[u];
  long long int num = 0;
  for (int i = 0; i < int(ar.size()); i++) {
    int v = ar[i].first;
    if (v != c[(ic + 1) % nc] and v != c[(ic - 1 + nc) % nc])
      num += numnodos[v];
  }
  return num;
}
long long int sol[limite];
void calcula(int u, long long int computoabove) {
  vector<pair<int, int> > &ar = g[u];
  sol[u] = computoabove + precomputo[u];
  for (int i = 0; i < int(ar.size()); i++) {
    int v = ar[i].first;
    long long int t = ar[i].second;
    calcula(v,
            sol[u] - (precomputo[v] + numnodos[v] * t) + (n - numnodos[v]) * t);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    g[u].push_back(pair<int, int>(v, t));
    g[v].push_back(pair<int, int>(u, t));
  }
  buscaciclo(1, 0, 0);
  eliminaadyacente(c[0], c[1]);
  eliminaadyacente(c[1], c[0]);
  quitapadre(c[0], 0);
  precomputa(c[0]);
  int ri = 0;
  int lenri = 0;
  long long int nodri = numnodosdebajo(0) + 1;
  long long int computori = precomputodebajo(0);
  long long int computole = precomputo[c[0]] - computori;
  for (int i = 0; i < nc; i++) {
    int u = c[i];
    while (2 * (lenri + d[ri]) <= lenc) {
      lenri += d[ri];
      ri = (ri + 1) % nc;
      long long int comp = precomputodebajo(ri);
      long long int numn = numnodosdebajo(ri);
      nodri += numn + 1;
      computori += comp + (numn + 1) * lenri;
      computole -= comp + (numn + 1) * (lenc - lenri);
    }
    sol[u] = computori + computole;
    vector<pair<int, int> > &ar = g[u];
    for (int j = 0; j < int(ar.size()); j++) {
      int v = ar[j].first;
      long long int t = ar[j].second;
      if (v != c[(i + 1) % nc] and v != c[(i - 1 + nc) % nc])
        calcula(v, computori + computole - (precomputo[v] + numnodos[v] * t) +
                       (n - numnodos[v]) * t);
    }
    long long int comp = precomputodebajo(i);
    long long int numn = numnodosdebajo(i);
    computori -= comp;
    nodri -= numn + 1;
    computori -= nodri * d[i];
    computole += comp + (n - nodri) * d[i];
    lenri -= d[i];
  }
  for (int u = 1; u <= n; u++) {
    if (u > 1) cout << " ";
    cout << sol[u];
  }
  cout << endl;
}
