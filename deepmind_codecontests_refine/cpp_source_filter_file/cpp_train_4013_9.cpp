#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
int main() {
  int n;
  int m;
  while (~scanf("%d%d", &n, &m)) {
    vector<string> maze(n);
    for (int(i) = 0; (i) < (int)(n); ++(i)) cin >> maze[i];
    int sy;
    int sx;
    scanf("%d%d", &sy, &sx), --sy, --sx;
    int gy;
    int gx;
    scanf("%d%d", &gy, &gx), --gy, --gx;
    vector<vector<int> > door(n, vector<int>(m));
    const char *str = "+-|^><vLRUD*";
    const int masks[12] = {15, 1 + 4,  2 + 8,  8,      1,      4,
                           2,  15 - 4, 15 - 1, 15 - 8, 15 - 2, 0};
    for (int(i) = 0; (i) < (int)(n); ++(i))
      for (int(j) = 0; (j) < (int)(m); ++(j))
        door[i][j] = masks[strchr(str, maze[i][j]) - str];
    vector<bool> vis(n * m * 4);
    vector<int> q, nq;
    nq.push_back((sy * m + sx) * 4 + 0);
    int dist = 0, ans = 0x3f3f3f3f;
    while (!nq.empty()) {
      q.swap(nq);
      while (!q.empty()) {
        int s = q.back();
        q.pop_back();
        if (vis[s]) continue;
        vis[s] = true;
        int i = s / 4 / m, j = s / 4 % m, t = s % 4;
        if (i == gy && j == gx) {
          nq.clear();
          ans = dist;
          break;
        }
        static const int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
        nq.push_back((i * m + j) * 4 + (t + 1) % 4);
        for (int d = 0; d < 4; ++d) {
          int yy = i + dy[d], xx = j + dx[d];
          if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
          if (~door[i][j] >> ((d + 4 - t) % 4) & 1) continue;
          if (~door[yy][xx] >> ((d + t) % 4) & 1) continue;
          nq.push_back((yy * m + xx) * 4 + t);
        }
      }
      ++dist;
    }
    if (ans == 0x3f3f3f3f)
      puts("-1");
    else
      printf("%d\n", ans);
  }
  return 0;
}
