#include <bits/stdc++.h>
using namespace std;
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
inline int myrand() { return abs((rand() << 15) ^ rand()); }
inline int rnd(int x) { return myrand() % x; }
const int maxn = (int)1600 + 10;
int a[maxn][maxn];
int used[maxn][maxn];
int maxu;
const int maxg = 4;
const int go[maxg][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int cnt;
int st[maxn * maxn][2];
int h, w;
inline bool ok(int y, int x) { return 0 <= y && 0 <= x && y < h && x < w; }
void dfs(int y, int x) {
  used[y][x] = maxu;
  st[cnt][0] = y, st[cnt][1] = x, ++cnt;
  for (int g = 0; g < maxg; ++g) {
    int ny = y + go[g][0], nx = x + go[g][1];
    if (!ok(ny, nx) || used[ny][nx] || !a[ny][nx]) continue;
    dfs(ny, nx);
  }
}
int dfs2(int y, int x) {
  used[y][x] = -1;
  int res = 1;
  for (int g = 0; g < maxg; ++g) {
    int ny = y + go[g][0], nx = x + go[g][1];
    if (!ok(ny, nx) || used[ny][nx] == -1 || !a[ny][nx]) continue;
    res += dfs2(ny, nx);
  }
  return res;
}
const int K = 5;
bool check(int y, int x) {
  int col = used[y][x];
  for (int i1 = -K; i1 <= K; ++i1) {
    for (int i2 = -K; i2 <= K; ++i2) {
      if ((i1 * i1) + (i2 * i2) > K * K) continue;
      int ry = y, rx = x;
      ry += i1 * go[0][0], rx += i1 * go[0][1];
      ry += i2 * go[2][0], rx += i2 * go[2][1];
      if (!ok(ry, rx)) return 0;
      if (used[ry][rx] != col) return 0;
    }
  }
  return 1;
}
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) : x(_x), y(_y) {}
  inline Point operator-(const Point &p) const {
    return Point(x - p.x, y - p.y);
  }
  inline Point operator*(const double k) const { return Point(x * k, y * k); }
  inline double operator^(const Point &p) const { return x * p.y - y * p.x; }
  inline double operator*(const Point &p) const { return x * p.x + y * p.y; }
  inline double abs() const { return sqrt(x * x + y * y); }
};
double value[maxn][maxn];
const int K2 = 1;
bool solve() {
  if (scanf("%d%d", &h, &w) < 2) return 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      used[i][j] = 0;
    }
  }
  maxu = 0;
  vector<int> ans;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (used[i][j] || !a[i][j]) continue;
      ++maxu;
      cnt = 0;
      dfs(i, j);
      assert(cnt >= 500);
      int cool = 0;
      long long sumy = 0, sumx = 0;
      for (int i = 0; i < cnt; ++i) {
        if (!check(st[i][0], st[i][1])) continue;
        ++cool;
        sumy += st[i][0], sumx += st[i][1];
      }
      Point c(sumx, sumy);
      c = c * (1.0 / cool);
      int y = -1, x = -1;
      double maxval = -1;
      for (int i = 0; i < cnt; ++i) {
        if (!check(st[i][0], st[i][1])) continue;
        Point cur(st[i][1], st[i][0]);
        cur = cur - c;
        if (maxval < cur.abs()) {
          maxval = cur.abs(), y = st[i][0], x = st[i][1];
        }
      }
      double a = maxval;
      Point dir(x, y);
      dir = dir - c;
      dir = dir * (1.0 / a);
      maxval = -1;
      for (int i = 0; i < cnt; ++i) {
        if (!check(st[i][0], st[i][1])) continue;
        Point cur(st[i][1], st[i][0]);
        cur = cur - c;
        maxval = max(maxval, abs(dir ^ cur));
      }
      double b = maxval;
      a += K + 2, b += K + 2;
      fprintf(stderr, "a = %.3f, b = %.3f\n", a, b);
      fprintf(stderr, "center : (%.3f %.3f)\n", c.y, c.x);
      fprintf(stderr, "dir : (%.3f %.3f)\n", dir.y, dir.x);
      for (int i = 0; i < cnt; ++i) {
        Point cur(st[i][1], st[i][0]);
        cur = cur - c;
        Point real(cur * dir, cur ^ dir);
        double coef =
            ((real.x / a) * (real.x / a)) + ((real.y / b) * (real.y / b));
        if (coef <= 1.0 + (1e-9))
          used[st[i][0]][st[i][1]] = -1;
        else
          assert(!check(st[i][0], st[i][1]));
      }
      int res = 0;
      for (int i = 0; i < cnt; ++i) {
        int y = st[i][0], x = st[i][1];
        if (used[y][x] == -1) continue;
        int tmp = dfs2(y, x);
        if (tmp >= 10) ++res;
      }
      ans.push_back(res);
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ((int)(ans).size()));
  for (int i = 0; i < ((int)(ans).size()); ++i)
    printf("%d%c", ans[i], " \n"[i == ((int)(ans).size()) - 1]);
  return 1;
}
int main() {
  srand(rdtsc());
  while (1) {
    if (!solve()) break;
  }
  return 0;
}
