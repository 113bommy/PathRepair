#include <bits/stdc++.h>
using namespace std;
namespace Matching {
const int MX = 40040, MY = 40040;
vector<int> E[MX], RE[MY];
int xy[MX], yx[MY];
int n, m;
void addE(int x, int y) {
  E[x].push_back(y);
  RE[y].push_back(x);
}
void setnm(int sn, int sm) {
  n = sn;
  m = sm;
}
int tdis[MX], que[MX], *dis = tdis + 1;
int bfs() {
  int *fr = que, *re = que;
  for (int i = 1; i <= n; i++) {
    if (xy[i] == -1)
      *fr++ = i, dis[i] = 0;
    else
      dis[i] = -1;
  }
  dis[-1] = -1;
  while (fr != re) {
    int t = *re++;
    if (t == -1) return 1;
    for (int e : E[t]) {
      if (dis[yx[e]] == -1) dis[yx[e]] = dis[t] + 1, *fr++ = yx[e];
    }
  }
  return 0;
}
int dfs(int x) {
  for (int e : E[x]) {
    if (yx[e] == -1 || (dis[yx[e]] == dis[x] + 1 && dfs(yx[e]))) {
      xy[x] = e;
      yx[e] = x;
      return 1;
    }
  }
  dis[x] = -1;
  return 0;
}
void Do(vector<int>& aa, vector<int>& bb) {
  memset(xy, -1, sizeof xy);
  memset(yx, -1, sizeof yx);
  int ans = 0;
  while (bfs()) {
    for (int i = 1; i <= n; i++)
      if (xy[i] == -1 && dfs(i)) ++ans;
  }
  int chka[1010] = {}, chkb[1010] = {};
  vector<int> v;
  for (int i = 1; i <= n; i++)
    if (xy[i] == -1) v.push_back(i), chka[i] = 1;
  for (int i = 0; i < ((int)(v).size()); i++) {
    int t = v[i];
    for (int e : E[t])
      if (yx[e] != -1 && chka[yx[e]] == 0) {
        chka[yx[e]] = 1;
        v.push_back(yx[e]);
      }
  }
  aa = v;
  v.clear();
  for (int i = 1; i <= m; i++)
    if (yx[i] == -1) v.push_back(i), chkb[i] = 1;
  for (int i = 0; i < ((int)(v).size()); i++) {
    int t = v[i];
    for (int e : RE[t])
      if (xy[e] != -1 && chkb[xy[e]] == 0) {
        chkb[xy[e]] = 1;
        v.push_back(xy[e]);
      }
  }
  bb = v;
  v.clear();
  for (int i = 1; i <= n; i++)
    if (xy[i] != -1 && chka[i] == 0 && chkb[xy[i]] == 0) {
      aa.push_back(i);
    }
}
}  // namespace Matching
int n;
pair<int, int> p[1010];
int mark[1010][1010];
int num_x[1010][1010];
int num_y[1010][1010];
int cnt_x, cnt_y;
int chx[100010], chy[100010];
vector<pair<pair<int, int>, pair<int, int> > > ans[2];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].first, &p[i].second);
  vector<int> vx, vy;
  for (int i = 1; i <= n; i++)
    vx.push_back(p[i].first), vy.push_back(p[i].second);
  sort((vx).begin(), (vx).end());
  vx.resize(unique((vx).begin(), (vx).end()) - vx.begin());
  sort((vy).begin(), (vy).end());
  vy.resize(unique((vy).begin(), (vy).end()) - vy.begin());
  for (int i = 1; i <= n; i++)
    p[i].first =
        (int)(lower_bound((vx).begin(), (vx).end(), p[i].first) - vx.begin());
  for (int i = 1; i <= n; i++)
    p[i].second =
        (int)(lower_bound((vy).begin(), (vy).end(), p[i].second) - vy.begin());
  for (int i = 1; i <= n; i++) {
    mark[p[i].first][p[i].second] = 1;
  }
  for (int i = 0; i < ((int)(vx).size()); i++) {
    int p = -1;
    for (int j = 0; j < ((int)(vy).size()); j++) {
      if (mark[i][j]) {
        if (p != -1) {
          ++cnt_x;
          for (int a = p + 1; a < j; a++) num_x[i][a] = cnt_x;
        }
        p = j;
      }
    }
  }
  for (int j = 0; j < ((int)(vy).size()); j++) {
    int p = -1;
    for (int i = 0; i < ((int)(vx).size()); i++) {
      if (mark[i][j]) {
        if (p != -1) {
          ++cnt_y;
          for (int a = p + 1; a < i; a++) num_y[a][j] = cnt_y;
        }
        p = i;
      }
    }
  }
  Matching::setnm(cnt_x, cnt_y);
  for (int i = 0; i < ((int)(vx).size()); i++)
    for (int j = 0; j < ((int)(vy).size()); j++) {
      if (num_x[i][j] && num_y[i][j]) {
        int a = num_x[i][j];
        int b = num_y[i][j];
        Matching::addE(a, b);
      }
    }
  vector<int> ax, ay;
  Matching::Do(ax, ay);
  for (int e : ax) chx[e] = 1;
  for (int e : ay) chy[e] = 1;
  for (int i = 0; i < ((int)(vx).size()); i++) {
    int p = -1;
    vector<int> temp(((int)(vy).size()));
    for (int j = 0; j < ((int)(vy).size()); j++) {
      int ok = mark[i][j];
      if (mark[i][j] == 0 && chx[num_x[i][j]]) ok = 1;
      temp[j] = ok;
    }
    for (int j = 0; j < ((int)(vy).size()); j++) {
      if (p == -1 && temp[j]) p = j;
      if (temp[j] && (j == ((int)(vy).size()) - 1 || temp[j + 1] == 0)) {
        ans[0].push_back(make_pair(pair<int, int>(i, p), pair<int, int>(i, j)));
        p = -1;
      }
    }
  }
  for (int i = 0; i < ((int)(vy).size()); i++) {
    int p = -1;
    vector<int> temp(((int)(vx).size()));
    for (int j = 0; j < ((int)(vx).size()); j++) {
      int ok = mark[j][i];
      if (mark[j][i] == 0 && chy[num_y[j][i]]) ok = 1;
      temp[j] = ok;
    }
    for (int j = 0; j < ((int)(vx).size()); j++) {
      if (p == -1 && temp[j]) p = j;
      if (temp[j] && (j == ((int)(vx).size()) - 1 || temp[j + 1] == 0)) {
        ans[1].push_back(make_pair(pair<int, int>(p, i), pair<int, int>(j, i)));
        p = -1;
      }
    }
  }
  for (int u = 0; u < 2; u++) {
    printf("%d\n", ((int)(ans[u ^ 1]).size()));
    for (auto e : ans[u ^ 1]) {
      pair<int, int> t = e.first;
      printf("%d %d ", vx[t.first], vy[t.second]);
      t = e.second;
      printf("%d %d\n", vx[t.first], vy[t.second]);
    }
  }
  return 0;
}
