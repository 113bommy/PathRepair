#include <bits/stdc++.h>
using namespace std;
inline int read(int num = 0, char c = getchar()) {
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') num = num * 10 + c - 48, c = getchar();
  return num;
}
const int N = 2e7;
int f[N + 5], V[3010][6010];
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int r, c, n, ans = 0;
int id(int i, int j) { return 2 * c * (i - 1) + j; }
bool Q(int &x, int &y) {
  if (y == 0) y = 2 * c;
  if (y == 2 * c + 1) y = 1;
  return (x <= 0 || x > r || !V[x][y]);
}
int find(int x) { return f[x] == x ? f[x] : f[x] = find(f[x]); }
bool check(int x, int y) {
  for (register int i = 0; i <= 7; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (Q(nx, ny)) continue;
    for (register int j = 0; j <= 7; ++j) {
      int nx_ = x + dx[j], ny_ = y + c + dx[j];
      if (Q(nx_, ny_)) continue;
      if (find(id(nx, ny)) == find(id(nx_, ny_))) return 0;
    }
  }
  return 1;
}
int main() {
  r = read(), c = read(), n = read();
  if (c == 1) return !printf("0\n");
  for (register int i = 1; i <= r; ++i)
    for (register int j = 1; j <= 2 * c; ++j) f[id(i, j)] = id(i, j);
  for (register int n_ = 1; n_ <= n; ++n_) {
    int x = read(), y = read();
    if (check(x, y)) {
      for (register int i = 0; i <= 7; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!Q(nx, ny)) f[find(id(x, y))] = find(id(nx, ny));
        int nx_ = x + dx[i], ny_ = y + c + dy[i];
        if (!Q(nx_, ny_)) f[find(id(x, y + c))] = find(id(nx_, ny_));
      }
      V[x][y] = V[x][y + c] = 1;
      ++ans;
    }
  }
  return !printf("%d\n", ans);
}
