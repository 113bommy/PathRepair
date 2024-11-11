#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> G[200001];
int T[20][200002];
int lvl[200002];
int lca(int x, int y) {
  if (lvl[x] < lvl[y]) swap(x, y);
  int logx, logy;
  for (logx = 1; (1 << logx) < lvl[x]; logx++)
    ;
  for (logy = 1; (1 << logy) < lvl[y]; logy++)
    ;
  for (int k = logx; k >= 0; k--)
    if (lvl[x] - (1 << k) >= lvl[y]) x = T[k][x];
  if (x == y) return x;
  for (int k = logy; k >= 0; k--)
    if (T[k][x] != T[k][y] && T[k][x] > 0) {
      x = T[k][x];
      y = T[k][y];
    }
  return T[0][x];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  lvl[1] = 1;
  for (int i = 2; i <= n; i++) {
    cin >> T[0][i];
    lvl[i] = lvl[T[0][i]] + 1;
  }
  for (int i = 1; (1 << i) <= n; i++)
    for (int j = 1; j <= n; j++) T[i][j] = T[i - 1][T[i - 1][j]];
  cout << 1 << " ";
  int f1 = 1, f2 = 2, dist = 1;
  for (int i = 3; i <= n; i++) {
    int p = T[0][i];
    if (p == f1) {
      f1 = i;
      dist++;
    } else if (p == f2) {
      f2 = i;
      dist++;
    } else {
      int l1 = lca(i, f1);
      int l2 = lca(i, f2);
      int dist1 = lvl[i] - lvl[l1] + lvl[f1] - lvl[l1];
      int dist2 = lvl[i] - lvl[l2] + lvl[f2] - lvl[l2];
      if (dist1 < dist2 && dist2 > dist) {
        dist = dist2;
        f1 = i;
      } else if (dist1 > dist2 && dist1 > dist) {
        dist = dist1;
        f2 = i;
      }
    }
    cout << dist << " ";
  }
}
