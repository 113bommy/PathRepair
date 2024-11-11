#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
const double pi = acos(-1.0);
const int size = 300 * 1000 + 100;
const int rms = (1 << 18) - 1;
const int hrms = rms / 2;
const int inf = 1000 * 1000 * 1000;
int rmq[rms + 1];
bool res[size];
vector<int> qs[size];
vector<int> toadd[size];
int xr[size], yr[size];
int xc1[size], yc1[size], xc2[size], yc2[size];
int n, m, k, q;
void change(int ps, int val) {
  ps += hrms;
  rmq[ps] = val;
  while (ps > 1) {
    ps /= 2;
    rmq[ps] = min(rmq[ps * 2], rmq[ps * 2 + 1]);
  }
}
int rss(int v, int lb, int rb, int i, int j) {
  if (lb > j || rb < i) return inf;
  if (lb >= i && rb <= j) return rmq[v];
  return min(rss(v * 2, lb, (lb + rb) / 2, i, j),
             rss(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j));
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &xr[i], &yr[i]);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d%d", &xc1[i], &yc1[i], &xc2[i], &yc2[i]);
  }
  for (int i = 0; i < k; i++) toadd[yr[i]].push_back(i);
  for (int i = 0; i < q; i++) qs[yc2[i]].push_back(i);
  for (int i = 0; i <= rms; i++) rmq[i] = -inf;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < (int)toadd[i].size(); j++) change(xr[toadd[i][j]], i);
    for (int j = 0; j < (int)qs[i].size(); j++) {
      if (rss(1, 1, hrms + 1, xc1[qs[i][j]], xc2[qs[i][j]]) >= yc1[qs[i][j]])
        res[qs[i][j]] = true;
    }
  }
  for (int i = 1; i <= m; i++) {
    toadd[i].clear();
    qs[i].clear();
  }
  for (int i = 0; i <= rms; i++) rmq[i] = -inf;
  for (int i = 0; i < k; i++) toadd[xr[i]].push_back(i);
  for (int i = 0; i < q; i++) qs[xc2[i]].push_back(i);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)toadd[i].size(); j++) change(yr[toadd[i][j]], i);
    for (int j = 0; j < (int)qs[i].size(); j++) {
      if (rss(1, 1, hrms + 1, yc1[qs[i][j]], yc2[qs[i][j]]) >= xc1[qs[i][j]])
        res[qs[i][j]] = true;
    }
  }
  for (int i = 0; i < q; i++)
    if (res[i])
      printf("YES\n");
    else
      printf("NO\n");
  return 0;
}
