#include <bits/stdc++.h>
using namespace std;
template <class T>
string ToString(T t) {
  stringstream s;
  s << t;
  return s.str();
}
template <class T>
void ToOther(T& t, string a) {
  stringstream s(a);
  s >> t;
}
int n;
int p[1000005][22];
int dep[1000005];
vector<int> v[1000005];
void dfs(int parent, int x, int d) {
  p[x][0] = parent;
  dep[x] = d;
  for (int i = 0; i < v[x].size(); i++) {
    int t = v[x][i];
    if (t == parent) continue;
    dfs(x, t, d + 1);
  }
}
void init(int root) {
  dfs(-1, root, 0);
  for (int k = 0; k < 22 - 1; k++)
    for (int i = 0; i < n; i++) {
      if (p[i][k] == -1)
        p[i][k + 1] = -1;
      else
        p[i][k + 1] = p[p[i][k]][k];
    }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 0; i < 30; ++i)
    if ((dep[u] - dep[v]) >> i & 1) {
      u = p[u][i];
    }
  if (u == v) return u;
  for (int i = 22 - 1; i >= 0; --i)
    if (p[u][i] != p[v][i]) {
      u = p[u][i];
      v = p[v][i];
    }
  return p[u][0];
}
void update(int parent, int x) {
  p[x][0] = parent;
  dep[x] = dep[parent] + 1;
  for (int k = 0; k < 22 - 1; k++) {
    if (p[x][k] == -1)
      p[x][k + 1] = -1;
    else
      p[x][k + 1] = p[p[x][k]][k];
  }
}
int calc(int s, int e) {
  int t = lca(s, e);
  return dep[s] + dep[e] - dep[lca(s, e)] * 2;
}
int main() {
  v[0].push_back(1);
  v[0].push_back(2);
  v[0].push_back(3);
  n = 4;
  init(0);
  int s = 1;
  int e = 2;
  int r = 2;
  int Q;
  cin >> Q;
  while (Q--) {
    int t;
    scanf("%d", &t);
    t--;
    update(t, n++);
    update(t, n++);
    int Ls = calc(s, n - 1);
    int Le = calc(e, n - 1);
    if (Ls >= Le && Ls > r) {
      r = Ls;
      e = n - 1;
    }
    if (Le > Ls && Le > r) {
      r = Le;
      s = n - 1;
    }
    printf("%###d\n", r);
  }
}
