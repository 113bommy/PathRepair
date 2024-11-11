#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int d[200000][2];
vector<int> e[200000];
int gr[200000], gc;
int dep[200000], up[200000];
int fa[200000][18];
vector<pair<int, bool>> tr[200000];
void dfs(int p, int pri, int prp) {
  gr[p] = gc;
  fa[p][0] = prp;
  if (prp != -1) dep[p] = dep[prp] + 1;
  up[p] = dep[p];
  for (auto i : e[p]) {
    if (i == pri) continue;
    int q = d[i][0] + d[i][1] - p;
    if (gr[q] == -1) {
      dfs(q, i, p);
      if (up[p] > up[q]) up[p] = up[q];
      tr[p].push_back(make_pair(q, dep[p] < up[q]));
    } else if (up[p] > dep[q])
      up[p] = dep[q];
  }
}
int c[200000][2];
bool res;
pair<int, int> dfs2(int p) {
  auto r = make_pair(c[p][0], c[p][1]);
  for (auto i : tr[p]) {
    auto re = dfs2(i.first);
    if (i.second && re.first > 0 && re.second > 0) res = false;
    r.first += re.first;
    r.second += re.second;
  }
  return r;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &d[i][0], &d[i][1]);
    d[i][0]--;
    d[i][1]--;
    e[d[i][0]].push_back(i);
    e[d[i][1]].push_back(i);
  }
  memset(gr, -1, sizeof(gr));
  for (int f = 0; f < n; f++) {
    if (gr[f] != -1) continue;
    dfs(f, -1, -1);
    gc++;
  }
  for (int i = 1; i < 18; i++) {
    for (int j = 0; j < n; j++) {
      if (fa[j][i - 1] != -1)
        fa[j][i] = fa[fa[j][i - 1]][i - 1];
      else
        fa[j][i] = -1;
    }
  }
  res = true;
  for (int i = 0; i < q; i++) {
    int j, k;
    scanf("%d%d", &j, &k);
    j--;
    k--;
    if (gr[j] != gr[k]) return !printf("No");
    c[j][0]++;
    c[k][1]++;
    if (dep[j] > dep[k]) swap(j, k);
    for (int l = 18 - 1; l >= 0; l--) {
      if ((dep[k] - dep[j]) & (1 << l)) k = fa[k][l];
    }
    for (int l = 18 - 1; l >= 0; l--) {
      if (fa[j][l] != fa[k][l]) {
        j = fa[j][l];
        k = fa[k][l];
      }
    }
    if (j != k) {
      j = fa[j][0];
      k = fa[k][0];
    }
    c[j][0]--;
    c[k][1]--;
  }
  dfs2(0);
  printf("%s", res ? "Yes" : "No");
  return 0;
}
