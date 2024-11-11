#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5;
const long long MAXP = 18;
const long long MAXKEEP = 10;
vector<long long> adj[MAXN];
vector<long long> dansVilles[MAXN];
long long par[MAXP][MAXN];
vector<long long> dansVilleUp[MAXP][MAXN];
long long depth[MAXN];
long long nbSommets, nbPersonnes, nbRequetes;
void dfs(long long iNoeud, long long iPere) {
  par[0][iNoeud] = iPere;
  for (long long iFrere : adj[iNoeud])
    if (iFrere != iPere) {
      depth[iFrere] = depth[iNoeud] + 1;
      dfs(iFrere, iNoeud);
    }
}
vector<long long> fusion(vector<long long> &lhs, vector<long long> &rhs) {
  long long iL(0), iR(0);
  vector<long long> ret;
  ret.reserve(MAXKEEP);
  while ((iL < (long long)lhs.size() or iR < (long long)rhs.size()) and
         (long long) ret.size() < MAXKEEP) {
    if (iL == (long long)lhs.size())
      ret.push_back(rhs[iR++]);
    else if (iR == (long long)rhs.size())
      ret.push_back(lhs[iL++]);
    else if (lhs[iL] < rhs[iR])
      ret.push_back(lhs[iL++]);
    else if (lhs[iL] > rhs[iR])
      ret.push_back(rhs[iR++]);
    else
      ret.push_back(lhs[iL++]), iR++;
  }
  return ret;
}
void init() {
  for (long long i = 0; i < nbSommets; ++i)
    dansVilleUp[0][i] = dansVilles[par[0][i]];
  for (long long p = 0; p < MAXP - 1; ++p)
    for (long long i = 0; i < nbSommets; ++i) {
      par[p + 1][i] = par[p][par[p][i]];
      dansVilleUp[p + 1][i] =
          fusion(dansVilleUp[p][i], dansVilleUp[p][par[p][i]]);
    }
}
signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> nbSommets >> nbPersonnes >> nbRequetes;
  for (long long iSommet = 0; iSommet < nbSommets - 1; ++iSommet) {
    long long u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (long long iPer = 0; iPer < nbPersonnes; ++iPer) {
    long long ville;
    cin >> ville;
    --ville;
    if ((long long)dansVilles[ville].size() < MAXKEEP)
      dansVilles[ville].push_back(iPer);
  }
  dfs(0, 0);
  init();
  while (nbRequetes--) {
    long long u, v, keep;
    cin >> u >> v >> keep;
    --u, --v;
    if (depth[u] < depth[v]) swap(u, v);
    vector<long long> sol = fusion(dansVilles[u], dansVilles[v]);
    long long diff = depth[u] - depth[v];
    for (long long p(0); p < MAXP; ++p)
      if ((1 << p) & diff) {
        sol = fusion(sol, dansVilleUp[p][u]);
        u = par[p][u];
      }
    for (long long p(MAXP - 1); p >= 0; --p)
      if (par[p][u] != par[p][v]) {
        sol = fusion(sol, dansVilleUp[p][u]);
        sol = fusion(sol, dansVilleUp[p][v]);
        u = par[p][u], v = par[p][v];
      }
    if (u != v) sol = fusion(sol, dansVilleUp[0][u]);
    if ((long long)sol.size() > keep) sol.resize(keep);
    cout << sol.size() << ' ';
    for (auto v : sol) cout << v + 1 << ' ';
    cout << '\n';
  }
}
