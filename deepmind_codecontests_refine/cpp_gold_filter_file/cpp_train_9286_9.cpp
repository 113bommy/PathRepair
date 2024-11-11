#include <bits/stdc++.h>
using namespace std;
inline void smax(int &a, int b) {
  if (b > a) a = b;
}
int n, p1, p2, xx, yy, hei[510000], up[510000], ans[510000], dm, sum;
vector<int> e[510000], cnt;
vector<pair<int, int> > v[510000];
void dfs1(int x, int fa) {
  for (int y : e[x])
    if (y != fa) {
      dfs1(y, x);
      smax(hei[x], hei[y] + 1);
    }
}
void dfs2(int x, int uph) {
  pair<int, int> tmp[2], tm;
  up[x] = uph + 1;
  tmp[0] = make_pair(up[x], -1);
  tmp[1] = make_pair(-1, -1);
  for (int y : e[x])
    if (hei[y] < hei[x]) {
      tm = make_pair(hei[y] + 1, y);
      for (int k = 0; k <= 1; k++)
        if (tm > tmp[k]) swap(tm, tmp[k]);
    }
  for (int y : e[x])
    if (hei[y] < hei[x])
      if (tmp[0].second == y)
        dfs2(y, tmp[1].first);
      else
        dfs2(y, tmp[0].first);
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d%d", &xx, &yy);
    e[xx].push_back(yy);
    e[yy].push_back(xx);
  }
  dfs1(1, -1);
  dfs2(1, -1);
  for (int x = 1; x <= n; x++) {
    cnt.clear();
    if (up[x]) cnt.push_back(up[x]);
    for (int y : e[x])
      if (hei[y] < hei[x]) cnt.push_back(hei[y] + 1);
    sort(cnt.begin(), cnt.end());
    for (int now : cnt)
      if (!v[x].empty() && v[x].back().first == now)
        v[x].back().second++;
      else
        v[x].push_back(make_pair(now, 1));
  }
  for (int i = 1; i <= n; i++) ans[i] = 1;
  for (int i = 1; i <= n; i++) smax(dm, v[i].back().first);
  for (int i = 1; i <= dm; i++) ans[i] = 2;
  for (int x = 1; x <= n; x++) smax(ans[1], e[x].size() + 1);
  for (int x = 1; x <= n; x++) {
    sum = e[x].size();
    for (int i = 0; i < v[x].size(); i++) {
      smax(ans[(v[x][i].first << 1) - 1], sum);
      smax(ans[v[x][i].first << 1], sum);
      if (i) smax(ans[(v[x][i - 1].first << 1) + 1], sum + 1);
      sum -= v[x][i].second;
    }
  }
  for (int x = 1; x <= n; x++)
    for (int y : e[x])
      if (hei[y] < hei[x]) {
        sum = e[x].size() + e[y].size() - 2;
        p1 = p2 = 0;
        for (auto tt : v[x])
          if (tt.first == hei[y] + 1) {
            tt.second--;
            break;
          }
        for (auto tt : v[y])
          if (tt.first == up[y]) {
            tt.second--;
            break;
          }
        while (p1 < v[x].size() && p2 < v[y].size()) {
          int te = min(v[x][p1].first, v[y][p2].first);
          smax(ans[te << 1], sum);
          if (te == v[x][p1].first) sum -= v[x][p1++].second;
          if (te == v[y][p2].first) sum -= v[y][p2++].second;
        }
        for (auto tt : v[x])
          if (tt.first == hei[y] + 1) {
            tt.second++;
            break;
          }
        for (auto tt : v[y])
          if (tt.first == up[y]) {
            tt.second++;
            break;
          }
      }
  for (int i = n - 2; i >= 1; i--) smax(ans[i], ans[i + 2]);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
