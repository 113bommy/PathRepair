#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int h, w;
int buf[2000][2000];
int core[2000][2000];
int sum[2000][2000];
struct uf {
  int par[4000000];
  void init() { memset(par, -1, sizeof(par)); }
  int root(int a) {
    if (par[a] == -1) return a;
    return par[a] = root(par[a]);
  }
  void unite(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    par[a] = b;
  }
};
uf u, uc;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int id[4000005];
int main() {
  cin >> h >> w;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) {
      scanf("%d", &buf[i + 5][j + 5]);
    }
  h += 10;
  w += 10;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) {
      sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + buf[i][j];
    }
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (buf[i][j]) {
        int tot = sum[i + 3][j + 3] - sum[i + 3][j - 3] - sum[i - 3][j + 3] +
                  sum[i - 3][j - 3];
        core[i][j] = (tot == 36);
      }
  u.init();
  uc.init();
  vector<int> res;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (buf[i][j]) {
        for (int d = 0; d < 4; ++d) {
          int px = j + dx[d], py = i + dy[d];
          if (px < 0 || py < 0 || px >= w || py >= h) continue;
          if (buf[py][px]) u.unite(i * w + j, py * w + px);
        }
      }
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (core[i][j] & 1) {
        int sz = 8;
        for (int dx = -sz; dx < sz; ++dx)
          for (int dy = -sz; dy < sz; ++dy) {
            if (i + dy < h && i + dy >= 0 && j + dx >= 0 && j + dx <= w)
              core[i + dy][j + dx] |= 2;
          }
      }
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (!core[i][j] && buf[i][j]) {
        for (int d = 0; d < 4; ++d) {
          int px = j + dx[d], py = i + dy[d];
          if (px < 0 || py < 0 || px >= w || py >= h) continue;
          if (!core[py][px] && buf[py][px]) uc.unite(i * w + j, py * w + px);
        }
      }
  int cnt = 0;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (buf[i][j] && u.root(i * w + j) == i * w + j) {
        id[i * w + j] = cnt++;
      }
  res.resize(cnt);
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (!core[i][j] && buf[i][j] && uc.root(i * w + j) == i * w + j) {
        int belong = id[u.root(i * w + j)];
        res[belong]++;
      }
  sort((res).begin(), (res).end());
  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); ++i) printf("%d\n", res[i]);
  return 0;
}
