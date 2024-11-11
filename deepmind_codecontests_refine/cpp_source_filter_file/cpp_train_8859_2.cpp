#include <bits/stdc++.h>
using namespace std;
const int maxn = 2001;
int n, m, r, c, x, y;
char arr[maxn][maxn];
priority_queue<pair<pair<int, int>, pair<int, int> >,
               vector<pair<pair<int, int>, pair<int, int> > >,
               greater<pair<pair<int, int>, pair<int, int> > > >
    cola;
const int mf[] = {0, 0, 1, -1};
const int mc[] = {1, -1, 0, 0};
bool vis[maxn][maxn];
void bfs() {
  cola.push({{0, 0}, {r, c}});
  int f, c, nf, nc, wx, wy;
  vis[r][c] = 1;
  while (!cola.empty()) {
    f = cola.top().second.first;
    c = cola.top().second.second;
    wx = cola.top().first.first;
    wy = cola.top().first.second;
    cola.pop();
    for (int i = 0; i < 4; i++) {
      nf = f + mf[i];
      nc = c + mc[i];
      if (nf < 1 or nf > n or nc < 1 or nc > m or vis[nf][nc] or
          arr[nf][nc] == '*')
        continue;
      if (i == 0) wy++;
      if (i == 1) wx++;
      if (wx <= x and wy <= y) {
        vis[nf][nc] = 1;
        cola.push({{wx, wy}, {nf, nc}});
      }
      if (i == 0) wy--;
      if (i == 1) wx--;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> r >> c >> x >> y;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> arr[i][j];
  bfs();
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) ans += vis[i][j];
  cout << ans;
  return 0;
}
