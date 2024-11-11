#include <bits/stdc++.h>
using namespace std;
struct Arr {
  int x, l;
} p[400];
map<int, int> de;
vector<int> s[400];
int f[400][400][2], org[400], pos[400], ri[400], dsz, n;
bool cmp(const Arr &a, const Arr &b) { return a.x < b.x; }
int dfs(int i, int j, bool d) {
  if (i > dsz) return 0;
  if (j < i) j = i, d = false;
  if (f[i][j][d] != -1) return f[i][j][d];
  int &w = f[i][j][d];
  w = dfs(i + 1, j, d);
  if ((!d || i < j) && ri[i] > j) {
    w = max(w, dfs((d ? j : j) + 1, ri[i], false) + org[ri[i]] - org[j]);
  }
  for (int k : s[i])
    if (pos[k] > j)
      w = max(w, dfs((d ? j : j) + 1, pos[k], true) + p[k].x - org[j]);
  return w;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &p[i].x, &p[i].l);
    de[p[i].x - p[i].l] = 0;
    de[p[i].x] = 0;
    de[p[i].x + p[i].l] = 0;
  }
  for (pair<const int, int> &w : de) org[w.second = ++dsz] = w.first;
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    s[de[p[i].x - p[i].l]].push_back(i);
    pos[i] = de[p[i].x];
    ri[pos[i]] = de[p[i].x + p[i].l];
  }
  memset(f, -1, sizeof(f));
  printf("%d\n", dfs(1, 1, 0));
  return 0;
}
