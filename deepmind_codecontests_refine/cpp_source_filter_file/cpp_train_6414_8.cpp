#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, w, h;
const int maxt = 100005, maxn = 200005, maxw = 200005;
int g[maxn], p[maxn], t[maxn], x[maxn];
pair<int, int> ans[maxn];
vector<int> vx[maxn], vy[maxn];
bool cmp(int x, int y) { return p[x] < p[y]; }
int main() {
  n = read(), w = read(), h = read();
  for (int i = 1; i <= n; i++) {
    g[i] = read(), p[i] = read(), t[i] = read();
    x[i] = p[i] - t[i] + maxt;
    if (g[i] == 1)
      vx[x[i]].push_back(i);
    else
      vy[x[i]].push_back(i);
  }
  for (int i = 1; i <= 2e5; i++) {
    int lx = vx[i].size();
    int ly = vy[i].size();
    sort(vx[i].begin(), vx[i].end(), cmp);
    sort(vy[i].begin(), vy[i].end(), cmp);
    for (int j = 0; j < lx; j++) {
      int id = vx[i][j];
      int right = lx - j;
      if (right > ly)
        ans[id] = make_pair(p[vx[i][j + ly]], h);
      else
        ans[id] = make_pair(w, p[vy[i][right - 1]]);
    }
    for (int j = 0; j < ly; j++) {
      int id = vy[i][j];
      int up = ly - j;
      if (up > lx)
        ans[id] = make_pair(w, p[vy[i][j + lx]]);
      else
        ans[id] = make_pair(p[vx[i][up - 1]], h);
    }
  }
  for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
