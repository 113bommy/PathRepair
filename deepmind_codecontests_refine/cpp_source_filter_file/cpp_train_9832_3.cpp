#include <bits/stdc++.h>
using namespace std;
struct kraw {
  int a, c;
};
struct kraw2 {
  int a, b, c, nr;
};
bool por(kraw2 a, kraw2 b) {
  if (a.c < b.c) return true;
  if (a.c > b.c) return false;
  if (a.nr < b.nr) return true;
  return false;
}
vector<int> f;
int nry = 0;
void dfs(int akt, int pop, vector<vector<kraw> >& G, vector<int>& oj,
         vector<int>& wlk, vector<int>& nr, vector<int>& odl) {
  oj[akt] = pop;
  nr[akt] = nry;
  ++nry;
  for (int i = 0; i < G[akt].size(); ++i) {
    if (G[akt][i].a != pop) {
      odl[G[akt][i].a] = odl[akt] + 1;
      dfs(G[akt][i].a, akt, G, oj, wlk, nr, odl);
    }
  }
  wlk[akt] = 1;
  for (int i = 0; i < G[akt].size(); ++i)
    if (G[akt][i].a != pop) wlk[akt] += wlk[G[akt][i].a];
}
bool Parent(int a, int b, vector<int>& nr, vector<int>& wlk) {
  if (nr[b] >= nr[a] && nr[b] <= nr[a] + wlk[a] - 1) return true;
  return false;
}
int LCA(vector<vector<int> >& P, int a, int b, vector<int>& nr,
        vector<int>& wlk) {
  if (Parent(a, b, nr, wlk)) return a;
  if (Parent(b, a, nr, wlk)) return b;
  for (int i = 16; i >= 0; --i)
    if (!Parent(P[i][a], b, nr, wlk)) a = P[i][a];
  return P[0][a];
}
int Daj(int a, int odl, vector<vector<int> >& maxy, vector<vector<int> >& P) {
  int odp = 0;
  for (int i = 16; i >= 0; --i) {
    if (odl >= (1 << i)) {
      odp = max(odp, maxy[i][a]);
      a = P[i][a];
      odl -= (1 << i);
    }
  }
  return odp;
}
void Stworz(int n) {
  for (int i = 0; i < n; ++i) f.push_back(i);
}
int Find(int a) {
  if (f[a] == a) return a;
  int fa = Find(f[a]);
  f[a] = fa;
  return fa;
}
void Union(int a, int b) {
  int fa = Find(a);
  int fb = Find(b);
  f[fb] = fa;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  Stworz(n);
  vector<vector<kraw> > G(n);
  int m;
  cin >> m;
  vector<kraw2> K(m);
  for (int i = 0; i < m; ++i) {
    cin >> K[i].a >> K[i].b >> K[i].c;
    K[i].nr = i;
    --K[i].a;
    --K[i].b;
  }
  sort(K.begin(), K.end(), por);
  int mst = 0, il_kraw = 0;
  for (int i = 0; i < m; ++i) {
    int a = K[i].a, b = K[i].b, c = K[i].c;
    if (Find(a) != Find(b)) {
      Union(a, b);
      mst += c;
      ++il_kraw;
      G[a].push_back({b, c});
      G[b].push_back({a, c});
    }
  }
  int q;
  cin >> q;
  vector<int> a(q), b(q);
  for (int i = 0; i < q; ++i) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
  }
  if (il_kraw < n - 1) {
    set<int> S;
    for (int i = 0; i < n; ++i) S.insert(Find(i));
    if (S.size() >= 3) {
      for (int i = 0; i < q; ++i) cout << "-1" << endl;
    } else {
      for (int i = 0; i < q; ++i) {
        if (Find(a[i]) != Find(b[i]))
          cout << mst << endl;
        else
          cout << "-1" << endl;
      }
    }
  } else {
    vector<int> oj(n), wlk(n), nr(n), odl(n);
    odl[0] = 0;
    dfs(0, -1, G, oj, wlk, nr, odl);
    vector<vector<int> > P(17, vector<int>(n));
    P[0][0] = 0;
    for (int i = 1; i < n; ++i) P[0][i] = oj[i];
    for (int i = 1; i < 17; ++i)
      for (int j = 0; j < n; ++j) P[i][j] = P[i - 1][P[i - 1][j]];
    vector<vector<int> > maxy(17, vector<int>(n));
    maxy[0][0] = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < G[i].size(); ++j)
        if (oj[G[i][j].a] == i) maxy[0][G[i][j].a] = G[i][j].c;
    for (int i = 1; i < 17; ++i)
      for (int j = 0; j < n; ++j)
        maxy[i][j] = max(maxy[i - 1][j], maxy[i - 1][P[i - 1][j]]);
    for (int i = 0; i < q; ++i) {
      int lca = LCA(P, a[i], b[i], nr, wlk);
      cout << mst - max(Daj(a[i], odl[a[i]] - odl[lca], maxy, P),
                        Daj(b[i], odl[b[i]] - odl[lca], maxy, P))
           << endl;
    }
  }
  return 0;
}
