#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  bool T[n][n];
  for (int i = (0); i <= (n - 1); ++i) {
    char s[n];
    scanf("%s", &s);
    for (int j = (0); j <= (n - 1); ++j) {
      char c = s[j];
      T[i][j] = (c == '1');
    }
  }
  bool R[n][2], C[n][2];
  for (int i = (0); i <= (n - 1); ++i)
    for (int j = (0); j <= (1); ++j) C[i][j] = R[i][j] = 0;
  vector<vector<pair<int, int> > > Q(n + 1);
  for (int i = (0); i <= (n - 1); ++i)
    for (int j = (0); j <= (n - 1); ++j)
      Q[max(i, j) - min(i, j)].push_back(make_pair(i, j));
  int ans = 0;
  for (int dist = (n); dist >= (0); --dist)
    for (int it = (0); it <= ((int)(Q[dist]).size() - 1); ++it) {
      int x = Q[dist][it].first, y = Q[dist][it].second;
      bool me = T[x][y];
      if (x >= y) {
        me ^= R[x][0];
        me ^= C[y][0];
      }
      if (x <= y) {
        me ^= R[x][1];
        me ^= C[y][1];
      }
      if (me) {
        ans++;
        R[x][x < y] ^= me;
        C[y][x < y] ^= me;
      }
    }
  printf("%d", ans);
  return 0;
}
