#include <bits/stdc++.h>
using namespace std;
int Dp[200][200][30], len[200], n, m;
vector<pair<int, int> > G[200];
int Go(int x, int y, int color) {
  if (Dp[x][y][color] != -1) return Dp[x][y][color];
  for (int i = 0; i < G[x].size(); i++) {
    int cc = G[x][i].second, to = G[x][i].first;
    if (cc >= color && !Go(y, to, cc)) return Dp[x][y][color] = 1;
  }
  return Dp[x][y][color] = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    x--;
    y--;
    int z = (int)(c - 'a');
    G[x].push_back(make_pair(y, c));
  }
  memset(Dp, -1, sizeof(Dp));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Go(i, j, 0) == 1)
        cout << 'A';
      else
        cout << 'B';
    }
    cout << endl;
  }
  return 0;
}
