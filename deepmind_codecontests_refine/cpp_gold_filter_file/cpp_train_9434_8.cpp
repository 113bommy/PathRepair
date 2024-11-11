#include <bits/stdc++.h>
using namespace std;
int n;
int m, k;
struct edge {
  int x, y;
} ed[300000];
bool flag;
vector<int> head[300000];
int high[300000], low[300000], du[300000], q[300000], ans[300000], top;
vector<pair<int, int>> jx[300000];
set<pair<int, int>> S;
void topsort(int now[], int delta) {
  int l = 0, r = -1, v, to;
  for (int i = 1; i <= n; ++i)
    if (du[i] == 0) q[++r] = i;
  while (l <= r) {
    v = q[l++];
    for (int i = 0; i < head[v].size(); ++i) {
      to = head[v][i];
      if (delta < 0)
        now[to] = min(now[to], now[v] + delta);
      else
        now[to] = max(now[to], now[v] + delta);
      if (--du[to] == 0) q[++r] = to;
    }
  }
  if (r != n - 1) {
    flag = false;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    high[i] = k;
    low[i] = 1;
  }
  int x;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    if (x != 0) high[i] = low[i] = x;
  }
  flag = true;
  for (int i = 1; i <= m; ++i) scanf("%d%d", &ed[i].x, &ed[i].y);
  for (int i = 1; i <= n; ++i) head[i].clear(), du[i] = 0;
  for (int i = 1; i <= m; ++i) head[ed[i].x].push_back(ed[i].y), ++du[ed[i].y];
  topsort(high, -1);
  for (int i = 1; i <= n; ++i) head[i].clear(), du[i] = 0;
  for (int i = 1; i <= m; ++i) head[ed[i].y].push_back(ed[i].x), ++du[ed[i].x];
  topsort(low, 1);
  if (!flag) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    if (low[i] > high[i]) {
      printf("-1\n");
      return 0;
    }
  top = k;
  for (int i = 1; i <= k; ++i) jx[i].clear();
  S.clear();
  for (int i = 1; i <= n; ++i) jx[high[i]].push_back(make_pair(-low[i], i));
  pair<int, int> temp;
  set<pair<int, int>>::iterator it;
  for (int i = 0; i < jx[k].size(); ++i) S.insert(jx[k][i]);
  while (top) {
    if (S.empty()) {
      printf("-1\n");
      return 0;
    }
    it = S.begin();
    temp = *it;
    ans[temp.second] = top;
    S.erase(it);
    while (1) {
      it = S.begin();
      temp = *it;
      if (-temp.first < top) break;
      ans[temp.second] = top;
      S.erase(it);
    }
    --top;
    for (int i = 0; i < jx[top].size(); ++i) S.insert(jx[top][i]);
  }
  while (!S.empty()) {
    it = S.begin();
    temp = *it;
    ans[temp.second] = 1;
    S.erase(it);
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
