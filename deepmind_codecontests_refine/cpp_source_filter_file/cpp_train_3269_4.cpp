#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
int p[100100];
vector<int> inc[100100];
vector<int> vdu[100100];
bool proib[100100];
int dd[100100], du[100100];
int mk[100100];
int passo = 1;
void dfs(int no, int pai) {
  p[no] = pai;
  for (int i = 0; i < inc[no].size(); ++i) {
    if (inc[no][i] == pai) continue;
    dfs(inc[no][i], no);
  }
}
int dfs2(int no) {
  if (mk[no] == passo) return dd[no];
  dd[no] = -oo;
  mk[no] = passo;
  if (proib[no]) dd[no] = 0;
  for (int i = 0; i < inc[no].size(); ++i) {
    if (inc[no][i] == p[no]) continue;
    dd[no] = max(dd[no], dfs2(inc[no][i]) + 1);
  }
  if (dd[no] < -oo / 2) dd[no] = -oo;
  return dd[no];
}
int dfs3(int no) {
  if (mk[no] == passo) return du[no];
  du[no] = -oo;
  mk[no] = passo;
  if (no != p[no]) {
    if (proib[p[no]]) du[no] = 1;
    if (inc[p[no]].size() > 2) {
      if (dd[no] == vdu[p[no]][vdu[p[no]].size() - 1])
        du[no] = max(du[no], vdu[p[no]][vdu[p[no]].size() - 2] + 2);
      else
        du[no] = max(du[no], vdu[p[no]][vdu[p[no]].size() - 1] + 2);
    }
    du[no] = max(du[no], dfs3(p[no]) + 1);
  }
  if (du[no] < -oo / 2) du[no] = -oo;
  return du[no];
}
int n, m, d;
int main() {
  scanf("%d %d %d", &n, &m, &d);
  int aux;
  for (int i = 0; i < m; ++i) scanf("%d", &aux), proib[aux - 1] = true;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;
    inc[a].push_back(b), inc[b].push_back(a);
  }
  dfs(0, 0);
  memset(dd, -1, sizeof dd);
  memset(du, -1, sizeof du);
  passo++;
  dfs2(0);
  passo++;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < inc[i].size(); ++j)
      if (inc[i][j] != p[i]) vdu[i].push_back(dd[inc[i][j]]);
    sort(vdu[i].begin(), vdu[i].end());
  }
  for (int i = 0; i < n; ++i) dfs3(i);
  int rsp = 0;
  for (int i = 0; i < n; ++i) {
    if (dd[i] <= d && du[i] <= d) rsp++;
  }
  printf("%d\n", rsp);
  return 0;
}
