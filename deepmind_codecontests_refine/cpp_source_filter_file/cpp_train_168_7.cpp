#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int nr, c, vaz[100010], v1[100010], val[100010], vaz1[100010], vaz2[100010];
vector<int> v[100010];
vector<int> vt[100010];
vector<int> r[100010];
void dfs(int nod) {
  vaz[nod] = 1;
  for (int i = 0; i < v[nod].size(); i++)
    if (vaz[v[nod][i]] == 0) dfs(v[nod][i]);
  v1[++nr] = nod;
}
void dfs1(int nod) {
  vaz[nod] = 0;
  r[c].push_back(nod);
  vaz1[nod] = c;
  for (int i = 0; i < vt[nod].size(); i++)
    if (vaz[vt[nod][i]] == 1) dfs1(vt[nod][i]);
}
int main() {
  int n, m, h, x, y;
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    if ((val[x] + 1) % h == val[y]) {
      v[x].push_back(y);
      vt[y].push_back(x);
    } else if ((val[y] + 1) % h == val[x]) {
      v[y].push_back(x);
      vt[x].push_back(y);
    }
  }
  for (int i = 1; i <= n; i++)
    if (vaz[i] == 0) dfs(i);
  for (int i = nr; i >= 1; i--)
    if (vaz[v1[i]] == 1) {
      c++;
      dfs1(v1[i]);
    }
  int sol = inf;
  for (int i = 1; i <= c; i++) {
    int a = r[i].size(), p = 0;
    for (int j = 0; j < r[i].size(); j++) {
      int nod = r[i][j];
      for (int k = 0; k < v[nod].size(); k++)
        if (vaz1[v[nod][k]] != i) {
          p = 1;
          break;
        }
      if (p == 1) break;
    }
    if (p == 0) {
      vaz2[i] = 1;
      sol = min(sol, a);
    }
  }
  if (sol < inf) printf("%d\n", sol);
  for (int i = 1; i <= c; i++)
    if (vaz2[i] == 1 && r[i].size() == sol) {
      for (int j = 0; j < r[i].size(); j++) printf("%d ", r[i][j]);
      return 0;
    }
  printf("%d\n", n);
  for (int i = 1; i <= n; i++) printf("%d ", i);
  return 0;
}
