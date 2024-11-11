#include <bits/stdc++.h>
using namespace std;
inline void ckmx(int &x, int y) { x = max(x, y); }
int n;
vector<int> G[500005];
int faz[500005], len[500005], gl[500005];
void DFS0(int u, int fz) {
  faz[u] = fz;
  for (auto v : G[u])
    if (v != fz) DFS0(v, u), len[u] = max(len[u], len[v] + 1);
}
void DFS1(int u, int fz) {
  static int pre[500005], suf[500005];
  int tp = 0;
  for (auto v : G[u])
    if (v != fz) pre[++tp] = len[v], suf[tp] = len[v];
  pre[0] = suf[tp + 1] = gl[u];
  for (int i = 1; i <= (tp); ++i) pre[i] = max(pre[i], pre[i - 1]);
  for (int i = tp; i >= (1); --i) suf[i] = max(suf[i], suf[i + 1]);
  tp = 0;
  for (auto v : G[u])
    if (v != fz) ++tp, gl[v] = max(pre[tp - 1], suf[tp + 1]) + 1;
  for (auto v : G[u])
    if (v != fz) DFS1(v, u);
}
vector<int> Vec[500005];
vector<pair<int, int> > V2[500005], tmp;
inline void PB(int xx, int yy, int aa, int bb) {
  if (xx == aa) --yy;
  if (xx == bb) --yy;
  if (yy) tmp.push_back({xx, yy});
}
int Ans[500005];
int main() {
  int x, y;
  scanf("%d", &n);
  for (int i = 2; i <= (n); ++i)
    scanf("%d%d", &x, &y), G[x].push_back(y), G[y].push_back(x);
  if (n == 2) return puts("1 2"), 0;
  if (n == 3) return puts("3 2 1"), 0;
  DFS0(1, 0);
  gl[1] = -1, DFS1(1, 0);
  for (int i = 1; i <= (n); ++i) {
    for (auto v : G[i])
      if (v != faz[i]) Vec[i].push_back(len[v] + 1);
    if (i > 1) Vec[i].push_back(gl[i] + 1);
    sort(Vec[i].begin(), Vec[i].end(), greater<int>());
    int lst = 0, cnt = 0;
    for (auto x : Vec[i])
      if (x != lst) {
        if (cnt) V2[i].push_back({lst, cnt});
        lst = x, cnt = 1;
      } else
        ++cnt;
    if (cnt) V2[i].push_back({lst, cnt});
  }
  for (int i = 1; i <= (n); ++i) {
    int sz = V2[i].size(), sum = 0;
    for (int j = 0; j <= (sz - 1); ++j) {
      sum += V2[i][j].second;
      ckmx(Ans[V2[i][j].first * 2], sum);
      ckmx(Ans[V2[i][j].first * 2 - 1], sum);
      if (j + 1 < sz) ckmx(Ans[V2[i][j + 1].first * 2 + 1], sum + 1);
    }
    ckmx(Ans[1], sum + 1);
  }
  for (int u = 2; u <= (n); ++u) {
    int p = faz[u];
    tmp.clear();
    int sz1 = V2[u].size(), sz2 = V2[p].size();
    int i = 0, j = 0;
    int AA = len[u] + 1, BB = gl[u] + 1;
    while (i < sz1 && j < sz2) {
      if (V2[u][i].first == V2[p][j].first) {
        PB(V2[u][i].first, V2[u][i].second + V2[p][j].second, AA, BB);
        ++i, ++j;
      } else if (V2[u][i].first > V2[p][j].first)
        PB(V2[u][i].first, V2[u][i].second, AA, BB), ++i;
      else
        PB(V2[p][j].first, V2[p][j].second, AA, BB), ++j;
    }
    while (i < sz1) PB(V2[u][i].first, V2[u][i].second, AA, BB), ++i;
    while (j < sz2) PB(V2[p][j].first, V2[p][j].second, AA, BB), ++j;
    int sz = tmp.size(), sum = 0;
    for (int j = 0; j <= (sz - 1); ++j) {
      sum += tmp[j].second;
      ckmx(Ans[tmp[j].first * 2], sum);
    }
  }
  ckmx(Ans[n], 1), ckmx(Ans[n - 1], 1);
  for (int i = n - 2; i >= (1); --i) ckmx(Ans[i], Ans[i + 2]);
  for (int i = 1; i <= (n); ++i) printf("%d ", Ans[i]);
  puts("");
  return 0;
}
