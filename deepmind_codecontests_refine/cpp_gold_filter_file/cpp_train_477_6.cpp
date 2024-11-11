#include <bits/stdc++.h>
using namespace std;
int n, P[100006], S[100006], fst[100006], t, u, v, q, nr, NRA[100006];
bool R[100006];
struct edge {
  int nod;
  bool p, s;
};
vector<edge> V[100006];
vector<pair<int, int> > E;
pair<int, int> rmq[21][100006 * 2];
void dfs(int nod, int nr) {
  NRA[nod] = nr;
  for (auto it : V[nod]) {
    P[it.nod] = P[nod] + it.p;
    S[it.nod] = S[nod] + it.s;
    dfs(it.nod, nr);
  }
}
void euler(int nod, int niv) {
  fst[nod] = E.size();
  E.push_back({nod, niv});
  for (auto it : V[nod]) {
    euler(it.nod, niv + 1);
    E.push_back({nod, niv});
  }
}
int LCA(int a, int b) {
  int x, y = abs(fst[b] - fst[a]);
  x = log2(y);
  if (rmq[x][min(fst[a], fst[b])].second <
      rmq[x][max(fst[a], fst[b]) - (1 << x) + 1].second)
    return rmq[x][min(fst[a], fst[b])].first;
  return rmq[x][max(fst[a], fst[b]) - (1 << x) + 1].first;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    if (x == -1) {
      R[i] = true;
      continue;
    }
    V[x].push_back({i, (y == 1), (y == 0)});
  }
  for (int i = 1; i <= n; i++)
    if (R[i] == true) {
      dfs(i, ++nr);
      euler(i, 1);
    }
  int mx = log2(E.size());
  for (int i = 0; i <= mx; i++)
    for (int j = 0; j < E.size() - (1 << i) + 1; j++) {
      if (i == 0) {
        rmq[i][j] = E[j];
        continue;
      }
      if (rmq[i - 1][j].second > rmq[i - 1][j + (1 << (i - 1))].second)
        rmq[i][j] = rmq[i - 1][j + (1 << (i - 1))];
      else
        rmq[i][j] = rmq[i - 1][j];
    }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> t >> u >> v;
    if (t == 1) {
      if (NRA[v] == NRA[u] && LCA(v, u) == u && v != u &&
          S[u] - S[v] == E[fst[u]].second - E[fst[v]].second)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      int x;
      if (NRA[v] == NRA[u]) x = LCA(v, u);
      if (NRA[v] == NRA[u] && v != u && x != v &&
          P[x] - P[v] == E[fst[x]].second - E[fst[v]].second &&
          S[x] - S[u] == E[fst[x]].second - E[fst[u]].second)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
