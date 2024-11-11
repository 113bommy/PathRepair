#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, m, f[N], id[N], dfn[N], tim, fa[N], fe[N], u[N], v[N], w[N];
bool in[N];
vector<pair<int, int> > E[N];
void dfs(int u) {
  dfn[u] = ++tim;
  for (auto e : E[u]) {
    int v = e.first;
    if (v != fa[u]) {
      if (!dfn[v])
        fa[v] = u, fe[v] = e.second, dfs(v);
      else if (dfn[v] > dfn[u]) {
        int x = v;
        vector<int> vec = {e.second};
        do vec.push_back(fe[x]), x = fa[x];
        while (x != u);
        rotate(vec.begin(), min_element(vec.begin(), vec.end()), vec.end());
        int p = max_element(vec.begin(), vec.end()) - vec.begin();
        bool fl = 1;
        for (int i = 0; i < p && fl; i++)
          if (vec[i] > vec[i + 1]) fl = 0;
        for (int i = p; i < int(vec.size()) && fl; i++)
          if (vec[i] < vec[i + 1]) fl = 0;
        if (fl) id[vec[0]] = vec[p];
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    u[i] = gi(), v[i] = gi(), E[u[i]].push_back(make_pair(v[i], i)),
    E[v[i]].push_back(make_pair(u[i], i));
  dfs(1);
  for (int i = 1; i <= n; i++) f[i] = 1;
  for (int i = m; i; i--) {
    w[i] = f[u[i]] + f[v[i]];
    f[u[i]] = f[v[i]] = w[i] - w[id[i]];
  }
  for (int i = 1; i <= n; i++) cout << f[i] - 1 << ' ';
  return 0;
}
