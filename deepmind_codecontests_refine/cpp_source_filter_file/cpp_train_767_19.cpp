#include <bits/stdc++.h>
const int N = 3009;
const int TOTAL = 2 * N * N;
const int d[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                    {0, 1},   {1, -1}, {1, 0},  {1, 1}};
int r, c, n;
bool g[N][2 * N];
int fa[TOTAL];
int rk[TOTAL];
inline int get(int x, int y) { return (x - 1) * 2 * c + y; }
inline int find(int x) {
  int anc = x, y;
  while (anc != fa[anc]) anc = fa[anc];
  while (x != anc) y = fa[x], fa[x] = anc, x = y;
  return anc;
}
inline bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return false;
  else {
    if (rk[x] > rk[y]) std::swap(x, y);
    fa[x] = y, rk[y] = std::max(rk[y], rk[x] + 1);
    return true;
  }
}
bool valid(int &x, int &y) {
  if (x < 0 || x > r)
    return false;
  else {
    if (y < 0)
      y += 2 * c;
    else if (y > 2 * c)
      y -= 2 * c;
    return g[x][y];
  }
}
inline void init() {
  std::cin >> r >> c >> n;
  for (int i = 1; i <= 2 * r * c; ++i) fa[i] = i, rk[i] = 1;
}
inline void solve() {
  int ans = 0;
  if (c == 1) {
    puts("0");
    return;
  }
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    bool flag = true;
    for (int j = 0; j < 8 && flag; ++j) {
      int ax = x + d[j][0], ay = y + d[j][1];
      if (valid(ax, ay)) {
        int a = get(ax, ay);
        for (int k = 0; k < 8 && flag; ++k) {
          int bx = x + d[k][0], by = y + c + d[k][1];
          if (valid(bx, by)) {
            int b = get(bx, by);
            if (find(a) == find(b)) flag = false;
          }
        }
      }
    }
    if (flag) {
      g[x][y] = g[x][y + c] = true;
      int a = get(x, y), b = get(x, y + c);
      for (int j = 0; j < 8; ++j) {
        int nx = x + d[j][0], ny = y + d[j][1];
        if (valid(nx, ny)) merge(a, get(nx, ny));
        ny += c;
        if (valid(nx, ny)) merge(b, get(nx, ny));
      }
      ans++;
    }
  }
  std::cout << ans << std::endl;
}
int main() {
  init();
  solve();
  return 0;
}
