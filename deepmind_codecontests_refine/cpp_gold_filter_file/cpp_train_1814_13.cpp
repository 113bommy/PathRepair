#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
const int INF = (1 << 29);
const int MAX = 23;
int n, m;
int dis[MAX][MAX][(1 << 8) + 3];
int val[MAX], A[MAX];
char g[MAX][MAX];
int tot;
vector<pair<int, int> > V;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
bool good(int x, int y) {
  return (0 <= x && x < n && 0 <= y && y < m &&
          (g[x][y] == '.' || g[x][y] == 'S'));
}
int BFS(int xi, int xj) {
  memset(dis, -1, sizeof(dis));
  queue<int> Q;
  Q.push(xi);
  Q.push(xj);
  Q.push(0);
  dis[xi][xj][0] = 0;
  int ans = 0;
  while (!Q.empty()) {
    int px = Q.front();
    Q.pop();
    int py = Q.front();
    Q.pop();
    int pmask = Q.front();
    Q.pop();
    int d = dis[px][py][pmask];
    if (px == xi and py == xj) {
      int sum = -d;
      for (int i = 0; i < (int)V.size(); i++) {
        if (pmask & (1 << i)) sum += val[i];
      }
      ans = max(ans, sum);
    }
    for (int dir = 0; dir < 4; dir++) {
      int x = dx[dir] + px;
      int y = dy[dir] + py;
      if (!good(x, y)) continue;
      int tmask = pmask;
      for (int i = 0; i < (int)V.size(); i++) {
        if (px == V[i].first and y < V[i].second and dx[dir] == -1)
          tmask ^= (1 << i);
        if (px == V[i].first - 1 and y < V[i].second and dx[dir] == 1)
          tmask ^= (1 << i);
      }
      if (dis[x][y][tmask] == -1) {
        dis[x][y][tmask] = d + 1;
        Q.push(x);
        Q.push(y);
        Q.push(tmask);
      }
    }
  }
  return ans;
}
void MAIN(void) {
  cin >> n >> m;
  V.clear();
  int cnt = 0;
  int xi, xj;
  for (int i = 0; i < n; i++) {
    scanf("%s", g[i]);
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'S')
        xi = i, xj = j;
      else if (g[i][j] >= '1' and g[i][j] <= '9') {
        V.push_back(make_pair(i, j));
        g[i][j]--;
        cnt++;
      } else if (g[i][j] == 'B') {
        V.push_back(make_pair(i, j));
      }
    }
  }
  for (int i = 0; i < cnt; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < (int)V.size(); i++) {
    val[i] = (g[V[i].first][V[i].second] == 'B')
                 ? -200000
                 : A[g[V[i].first][V[i].second] - '0'];
  }
  int ans = BFS(xi, xj);
  cout << ans << endl;
  return;
}
int main() {
  int t;
  t = 1;
  while (t--) MAIN();
  return 0;
}
