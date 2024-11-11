#include <bits/stdc++.h>
using namespace std;
int n, m, nrq, r[1005], cnt[1005], p[1005][12], lvl[1005], cc[1005];
pair<int, int> cp[1005], O[1005];
queue<int> q;
vector<int> G[1005], GG[1005];
bool isIncluded(pair<int, int> O1, int r1, pair<int, int> O2, int r2) {
  if (r1 > r2) return 0;
  long long d = 1LL * (O1.first - O2.first) * (O1.first - O2.first) +
                1LL * (O1.second - O2.second) * (O1.second - O2.second);
  return d <= 1LL * r2 * r2 - 1LL * r1 * r1;
}
void DFS(int u, int pp) {
  lvl[u] = lvl[pp] + 1;
  int yy = pp;
  for (int i = 0; i < 12; i++) {
    p[u][i] = yy;
    yy = p[yy][i];
  }
  for (auto xx : G[u])
    if (xx != pp) DFS(xx, u);
}
int lca(int xx, int yy) {
  if (lvl[xx] < lvl[yy]) swap(xx, yy);
  for (int i = 12 - 1; i >= 0; i--)
    if (lvl[xx] - (1 << i) >= lvl[yy]) xx = p[xx][i];
  if (xx == yy) return xx;
  for (int i = 12 - 1; i >= 0; i--)
    if (p[xx][i] != p[yy][i]) {
      xx = p[xx][i];
      yy = p[yy][i];
    }
  return p[xx][0];
}
bool inCircle(pair<int, int> A, pair<int, int> O, int r) {
  return 1LL * (A.first - O.first) * (A.first - O.first) +
             1LL * (A.second - O.second) * (A.second - O.second) <=
         r * r;
}
int main() {
  scanf("%d %d %d", &n, &m, &nrq);
  for (int i = 1; i <= n; i++) scanf("%d %d\n", &cp[i].first, &cp[i].second);
  for (int i = 1; i <= m; i++)
    scanf("%d %d %d", &r[i], &O[i].first, &O[i].second);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++)
      if (i != j && isIncluded(O[i], r[i], O[j], r[j])) {
        cnt[i]++;
        GG[j].push_back(i);
      }
  for (int i = 1; i <= m; i++)
    if (!cnt[i]) {
      q.push(i);
      G[1004].push_back(i);
    }
  while (!q.empty()) {
    int xx = q.front();
    q.pop();
    for (auto yy : GG[xx]) {
      cnt[yy]--;
      if (!cnt[yy]) {
        q.push(yy);
        G[xx].push_back(yy);
      }
    }
  }
  DFS(1004, 0);
  for (int i = 1; i <= n; i++) {
    cc[i] = 1004;
    for (int j = 1; j <= m; j++)
      if (inCircle(cp[i], O[j], r[j]) && lvl[j] > lvl[cc[i]]) cc[i] = j;
  }
  while (nrq--) {
    int xx, yy;
    scanf("%d %d", &xx, &yy);
    xx = cc[xx], yy = cc[yy];
    printf("%d\n", lvl[xx] + lvl[yy] - 2 * lvl[lca(xx, yy)]);
  }
  return 0;
}
