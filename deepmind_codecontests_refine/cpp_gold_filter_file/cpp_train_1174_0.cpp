#include <bits/stdc++.h>
using namespace std;
int read(int &x) { return scanf("%d", &x); }
int read(int &x, int &y) { return scanf("%d%d", &x, &y); }
int read(int &x, int &y, int &z) { return scanf("%d%d%d", &x, &y, &z); }
int read(long long &x) { return scanf("%lld", &x); }
int read(long long &x, long long &y) { return scanf("%lld%lld", &x, &y); }
int read(double &x) { return scanf("%lf", &x); }
char buff[2000010];
int read(string &s) {
  int r = scanf("%s", buff);
  s = buff;
  return r;
}
using namespace std;
struct Dist {
  int startingBlack;
  int startingWhite;
  Dist join(Dist dv, int color) {
    Dist d = *this;
    if (color == 0) {
      d.startingBlack = max(d.startingBlack, dv.startingBlack);
      d.startingWhite = max(d.startingWhite, dv.startingWhite);
    } else if (color == 1) {
      d.startingWhite = max(d.startingWhite, dv.startingWhite);
      d.startingWhite = max(d.startingWhite, dv.startingBlack + 1);
    } else if (color == 2) {
      d.startingBlack = max(d.startingBlack, dv.startingBlack);
      d.startingBlack = max(d.startingBlack, dv.startingWhite + 1);
    }
    return d;
  }
};
Dist depth[200010], farthest[200010];
Dist dfs(int u, int p, vector<vector<int> > &adj, vector<int> &C) {
  Dist d = {C[u] == 2, C[u] == 1};
  for (int v : adj[u]) {
    if (v == p) continue;
    Dist dv = dfs(v, u, adj, C);
    d = d.join(dv, C[u]);
  }
  depth[u] = d;
  return d;
}
template <class T>
vector<T> rev(vector<T> V) {
  reverse(V.begin(), V.end());
  return V;
}
vector<Dist> prefix(Dist st, vector<Dist> V, int c) {
  vector<Dist> pd;
  for (int i = 0; i < V.size(); ++i) {
    if (pd.size() == 0)
      pd.push_back(st.join(V[i], c));
    else
      pd.push_back(pd.back().join(V[i], c));
  }
  return pd;
}
void dfs2(int u, int p, vector<vector<int> > &adj, vector<int> &C, Dist dUp) {
  Dist d = {C[u] == 2, C[u] == 1};
  vector<Dist> ordered;
  for (int v : adj[u]) {
    if (v == p) {
      ordered.push_back(dUp);
      continue;
    } else {
      ordered.push_back(depth[v]);
    }
  }
  vector<Dist> pd = prefix(d, ordered, C[u]);
  vector<Dist> sd = rev(prefix(d, rev(ordered), C[u]));
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v == p) continue;
    Dist cd = d;
    if (i > 0) cd = cd.join(pd[i - 1], C[u]);
    if (i + 1 < sd.size()) cd = cd.join(sd[i + 1], C[u]);
    dfs2(v, u, adj, C, cd);
  }
  farthest[u] = depth[u].join(dUp, C[u]);
}
int main() {
  int TC = 1;
  read(TC);
  while (TC-- > 0) {
    int N;
    read(N);
    vector<vector<int> > adj(N);
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
      read(C[i]);
    }
    for (int i = 0; i < N - 1; ++i) {
      int u, v;
      read(u, v);
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(0, -1, adj, C);
    dfs2(0, -1, adj, C, (Dist){0, 0});
    int mn = N + 1;
    for (int i = 0; i < N; ++i) {
      Dist d = farthest[i];
      if (C[i] != 0) {
        mn = min(mn, max(d.startingWhite, d.startingBlack));
      }
    }
    if (mn == N + 1) {
      mn = 1;
    }
    cout << mn << endl;
  }
}
