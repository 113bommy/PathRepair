#include <bits/stdc++.h>
using namespace std;
std::vector<int> v[1 << 17];
vector<pair<int, int> > dif[1 << 17];
int c[1 << 17], vi[1 << 17], curCol = 0, col[1 << 17];
void dfs(int cur) {
  int j, l = v[cur].size();
  col[cur] = curCol;
  vi[cur] = 1;
  for (j = 0; j < l; j++) {
    int ne = v[cur][j];
    if (!vi[ne] && c[cur] == c[ne]) dfs(ne);
    if (c[cur] != c[ne]) dif[col[cur]].push_back(make_pair(cur, ne));
  }
}
int main() {
  int n, i, a, b;
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++)
    scanf("%d%d", &a, &b), a--, b--, v[a].push_back(b), v[b].push_back(a);
  for (i = 0; i < n; i++) scanf("%d", &c[i]);
  for (i = 0; i < n; i++)
    if (!vi[i]) ++curCol, dfs(i);
  for (i = 0; i < n; i++) {
    int j, l = v[i].size(), f = 0, cn = 0;
    for (j = 0; j < l; j++) {
      int ne = v[i][j];
      if (c[ne] != c[i]) cn++;
    }
    for (j = 0; j < l; j++) {
      int ne = v[i][j];
      if (dif[col[ne]].size() > 0) {
        if (dif[col[ne]].size() > 1) {
          if (col[ne] == col[i] && dif[col[ne]].size() != cn)
            f = 1;
          else if (col[ne] != col[i])
            f = 1;
        } else if (dif[col[ne]][0].first != i && dif[col[ne]][0].second != i)
          f = 1;
      }
    }
    if (!f) break;
  }
  if (i != n)
    printf("YES\n%d", i + 1);
  else
    printf("NO");
  return 0;
}
