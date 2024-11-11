#include <bits/stdc++.h>
using namespace std;
int sgn(int x) {
  if (!x) return 0;
  return x < 0 ? -1 : 1;
}
int n, d[124], l[124];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int asd[256];
bool o[2048][2048], v[2048][2048];
set<int> xs, ys;
map<int, int> idx, idy;
int nx, ny;
int wx[2048], wy[2048];
void dfs(int x, int y) {
  if (x < 0 || x >= nx || y < 0 || y >= ny || v[x][y] || o[x][y]) return;
  v[x][y] = true;
  for (int _ = 0, ThxDem = 4; _ < ThxDem; ++_) dfs(x + dx[_], y + dy[_]);
}
void doit(set<int>& s, map<int, int>& id, int* w, int& n) {
  vector<int> v(s.begin(), s.end());
  n = 0;
  for (int i = 0, ThxDem = ((int)v.size()); i < ThxDem; ++i) {
    w[n] = 1;
    id[v[i]] = n++;
    if (i < ((int)v.size()) - 1 && v[i + 1] > v[i] + 1)
      w[n++] = v[i + 1] - v[i] - 1;
  }
}
int main() {
  asd['L'] = 0;
  asd['R'] = 1;
  asd['U'] = 2;
  asd['D'] = 3;
  scanf("%d", &n);
  int x = 0, y = 0;
  xs.insert(x);
  ys.insert(y);
  for (int i = 0, ThxDem = n; i < ThxDem; ++i) {
    char s[4];
    scanf("%s%d", s, l + i);
    d[i] = asd[s[0]];
    x += dx[d[i]] * l[i];
    xs.insert(x);
    y += dy[d[i]] * l[i];
    ys.insert(y);
  }
  doit(xs, idx, wx, nx);
  doit(ys, idy, wy, ny);
  x = 0;
  y = 0;
  o[idx[x]][idy[y]] = 1;
  for (int i = 0, ThxDem = n; i < ThxDem; ++i) {
    int xx = x + dx[d[i]] * l[i], yy = y + dy[d[i]] * l[i];
    int x0 = idx[x], y0 = idy[y], x1 = idx[xx], y1 = idy[yy];
    while (x0 != x1 || y0 != y1) {
      x0 += sgn(x1 - x0);
      y0 += sgn(y1 - y0);
      o[x0][y0] = 1;
    }
    x = xx;
    y = yy;
  }
  for (int i = 0, ThxDem = nx; i < ThxDem; ++i) dfs(i, 0), dfs(i, ny - 1);
  for (int i = 0, ThxDem = ny; i < ThxDem; ++i) dfs(0, i), dfs(nx - 1, i);
  long long r = 0;
  for (int i = 0, ThxDem = nx; i < ThxDem; ++i)
    for (int j = 0, ThxDem = ny; j < ThxDem; ++j)
      if (!v[i][j]) r += 1LL * wx[i] * wy[j];
  printf("%lld\n", r);
  return 0;
}
