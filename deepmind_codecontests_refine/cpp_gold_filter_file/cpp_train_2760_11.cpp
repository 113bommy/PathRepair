#include <bits/stdc++.h>
const int N = 1007;
int G[N][N];
int C[N * N];
int xs, ys;
int cc = 0;
int sz = 0;
void dfs(short x, short y) {
  if (y < 0 || y > ys || x < 0 || x > xs || G[y][x] != -1) return;
  G[y][x] = cc;
  sz++;
  dfs(x, y + 1);
  dfs(x, y - 1);
  dfs(x + 1, y);
  dfs(x - 1, y);
}
int singleRes(int x, int y) {
  if (x < 0 || x > xs || y < 0 || y > ys) return 0;
  return G[y][x];
}
int res(int x, int y) {
  int abc[] = {singleRes(x, y + 1), singleRes(x, y - 1), singleRes(x + 1, y),
               singleRes(x - 1, y)};
  int r = C[abc[0]] + 1;
  if (abc[0] != abc[1]) r += C[abc[1]];
  if (abc[0] != abc[2] && abc[1] != abc[2]) r += C[abc[2]];
  if (abc[0] != abc[3] && abc[1] != abc[3] && abc[2] != abc[3]) r += C[abc[3]];
  return r % 10;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> ys >> xs;
  for (int y = 0; y < ys; y++) {
    for (int x = 0; x < xs; x++) {
      char c;
      std::cin >> c;
      if (c == '.') G[y][x] = -1;
    }
  }
  for (int y = 0; y < ys; y++) {
    for (int x = 0; x < xs; x++) {
      if (G[y][x] == -1) {
        sz = 0;
        cc++;
        dfs(x, y);
        C[cc] = sz;
      }
    }
  }
  for (int y = 0; y < ys; y++) {
    for (int x = 0; x < xs; x++) {
      if (G[y][x] == 0)
        std::cout << res(x, y);
      else
        std::cout << '.';
    }
    std::cout << '\n';
  }
  return 0;
}
