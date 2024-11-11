#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m, k;
string g[maxn];
int dis[maxn][maxn];
int stx, sty, edx, edy;
int X[] = {0, 0, 1, -1};
int Y[] = {-1, 1, 0, 0};
bool valid(long long x, long long y) {
  if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#') return 1;
  return 0;
}
int bfs() {
  queue<pair<int, int>> q;
  q.push({stx, sty});
  memset(dis, -1, sizeof dis);
  dis[stx][sty] = 0;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= k; j++) {
        int kx = x + X[i] * j;
        int ky = y + Y[i] * j;
        if (!valid(kx, ky)) break;
        if (dis[kx][ky] != -1) continue;
        dis[kx][ky] = dis[x][y] + 1;
        q.push({kx, ky});
        if (kx == edx && ky == edy) return dis[kx][ky];
      }
    }
  }
  return -1;
}
void solve() {
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) {
    cin >> g[i];
  }
  cin >> stx >> sty >> edx >> edy;
  stx--, sty--, edx--, edy--;
  if (stx == edx && sty == edy)
    cout << 0 << '\n';
  else
    cout << bfs() << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
