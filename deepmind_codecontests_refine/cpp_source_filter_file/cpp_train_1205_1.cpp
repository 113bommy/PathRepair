#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char p[N][N];
vector<pair<int, int> > fans, bans;
int n, m;
void rolate(int x, int y) {
  if (p[x + 1][y] == 'U') {
    if (p[x + 1][y + 1] == 'L') rolate(x + 1, y + 1);
    bans.push_back(pair<int, int>(x + 1, y));
    p[x + 2][y] = 'L';
    p[x + 2][y + 1] = 'R';
  }
  bans.push_back(pair<int, int>(x, y));
  p[x][y] = p[x][y + 1] = 'U';
  p[x + 1][y] = p[x + 1][y + 1] = 'D';
}
void solve() {
  for (int i = 1; i <= n; i++) scanf("%s", p[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (p[i][j] == 'L') rolate(i, j);
}
int main() {
  scanf("%d%d", &n, &m);
  solve();
  fans = bans;
  bans.clear();
  solve();
  printf("%d\n", fans.size() + bans.size());
  for (int i = 0; i < fans.size(); i++)
    printf("%d %d\n", fans[i].first, fans[i].second);
  for (int i = bans.size() - 1; i >= 0; i--)
    printf("%d %d\n", bans[i].first, bans[i].second);
}
