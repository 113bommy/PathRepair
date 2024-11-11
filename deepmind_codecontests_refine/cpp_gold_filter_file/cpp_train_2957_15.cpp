#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> V[maxn];
set<int> S;
int LL[maxn], RR[maxn];
void gao(int n) {
  int cnt = 0;
  set<int>::iterator it = S.begin();
  V[n].clear();
  while (it != S.end()) {
    V[n].push_back(*it);
    if (++cnt > 4) break;
    it++;
  }
}
map<int, int> M[maxn];
int N, f;
int dfs(int dep, int n) {
  if (dep == 0) return 1;
  S.erase(n);
  gao(n);
  for (int i = 0; i < V[n].size(); i++)
    if (M[n][V[n][i]])
      ;
    else {
      LL[dep] = n, RR[dep] = V[n][i];
      if (dfs(dep - 1, V[n][i])) return 1;
    }
  if (N > 2 && dep == 1 && M[n][f] == 0) {
    LL[dep] = n, RR[dep] = f;
    return 1;
  }
  S.insert(n);
  return 0;
}
int main() {
  int n, m, i, j, k, u, v;
  scanf("%d%d", &n, &m);
  N = m;
  for (i = 1; i <= m; i++) scanf("%d%d", &u, &v), M[u][v] = M[v][u] = 1;
  for (i = 1; i <= n; i++) S.insert(i);
  int ii = 0;
  for (i = 1; i <= min(n, 4); i++) {
    f = i;
    if (dfs(m, i)) {
      for (i = 1; i <= m; i++) printf("%d %d\n", LL[i], RR[i]);
      return 0;
    }
  }
  puts("-1");
}
