#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-9;
struct Data {
  int x, y, z;
  Data(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};
const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};
int K, N, M;
char tbl[15][15][15];
bool vis[15][15][15] = {};
queue<Data> que;
inline bool Valid(int x, int y, int z) {
  return x >= 1 && x <= K && y >= 1 && y <= N && z >= 1 && z <= M;
}
int main() {
  int i, j, k, x, y, z;
  scanf("%d%d%d", &K, &N, &M);
  for (i = 1; i <= K; i++) {
    for (j = 1; j <= N; j++) {
      scanf("%s", tbl[i][j] + 1);
    }
  }
  scanf("%d%d", &y, &z);
  int ans = 0;
  if (tbl[1][y][z] != '#') {
    vis[1][y][z] = true;
    que.push(Data(1, y, z));
    ans++;
  }
  while (!que.empty()) {
    x = (que.front().x);
    y = (que.front().y);
    z = (que.front().z);
    que.pop();
    for (k = 0; k < 6; k++) {
      if (!Valid((x + dx[k]), (y + dy[k]), (z + dz[k]))) continue;
      if (tbl[(x + dx[k])][(y + dy[k])][(z + dz[k])] == '#') continue;
      if (vis[(x + dx[k])][(y + dy[k])][(z + dz[k])]) continue;
      vis[(x + dx[k])][(y + dy[k])][(z + dz[k])] = true;
      que.push(Data((x + dx[k]), (y + dy[k]), (z + dz[k])));
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
