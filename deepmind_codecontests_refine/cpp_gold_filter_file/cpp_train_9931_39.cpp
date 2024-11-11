#include <bits/stdc++.h>
using namespace std;
template <typename X>
inline X abs(const X& a) {
  return a < 0 ? -a : a;
}
template <typename X>
inline X sqr(const X& a) {
  return a * a;
}
const int INF = int(1e9);
const long long INF64 = long long(1e18);
const long double EPS = 1e-9, PI = 3.1415926535897932384626433832795;
const int N = 1600 + 3;
int n, m;
int a[N][N];
inline bool read() {
  if (scanf("%d%d", &n, &m) != 2) return false;
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(m); j++) assert(scanf("%d", &a[i][j]) == 1);
  return true;
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int t[N][N], b[N][N];
int color, c[N][N];
int used[N][N];
void dfs(int first, int second) {
  used[first][second] = true;
  c[first][second] = color;
  for (int i = 0; i < int(4); i++) {
    int xx = first + dx[i], yy = second + dy[i];
    if (!(0 <= (xx) && (xx) < (n) && 0 <= (yy) && (yy) < (m)) ||
        a[xx][yy] == 0 || used[xx][yy])
      continue;
    dfs(xx, yy);
  }
}
int cur;
void dfs2(int first, int second) {
  used[first][second] = true;
  cur++;
  for (int i = 0; i < int(4); i++) {
    int xx = first + dx[i], yy = second + dy[i];
    if (!(0 <= (xx) && (xx) < (n) && 0 <= (yy) && (yy) < (m)) ||
        a[xx][yy] == 0 || used[xx][yy] || b[xx][yy] == 1)
      continue;
    dfs2(xx, yy);
  }
}
const int M = 5;
const int ITER1 = 4;
const int ITER2 = 9;
inline void solve() {
  color = 0;
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(m); j++) {
      if (used[i][j] || a[i][j] == 0) continue;
      dfs(i, j);
      color++;
    }
  {
    for (int i = 0; i < int(n); i++)
      for (int j = 0; j < int(m); j++) b[i][j] = a[i][j];
    for (int iter = 0; iter < int(ITER1); iter++) {
      for (int i = 0; i < int(n); i++)
        for (int j = 0; j < int(m); j++) t[i][j] = b[i][j];
      for (int i = 0; i < int(n); i++)
        for (int j = 0; j < int(m); j++) {
          if (t[i][j] == 0) continue;
          bool rem = false;
          for (int k = 0; k < int(4); k++) {
            int first = i + dx[k], second = j + dy[k];
            if (!(0 <= (first) && (first) < (n) && 0 <= (second) &&
                  (second) < (m)))
              continue;
            if (b[first][second] == 0) rem = true;
          }
          if (rem) t[i][j] = 0;
        }
      for (int i = 0; i < int(n); i++)
        for (int j = 0; j < int(m); j++) b[i][j] = t[i][j];
    }
  }
  {
    for (int iter = 0; iter < int(ITER2); iter++) {
      for (int i = 0; i < int(n); i++)
        for (int j = 0; j < int(m); j++) t[i][j] = b[i][j];
      for (int i = 0; i < int(n); i++)
        for (int j = 0; j < int(m); j++) {
          if (t[i][j] == 1) continue;
          bool paint = false;
          for (int k = 0; k < int(4); k++) {
            int first = i + dx[k], second = j + dy[k];
            if (!(0 <= (first) && (first) < (n) && 0 <= (second) &&
                  (second) < (m)))
              continue;
            if (b[first][second] == 1) paint = true;
          }
          if (paint) t[i][j] = 1;
        }
      for (int i = 0; i < int(n); i++)
        for (int j = 0; j < int(m); j++) b[i][j] = t[i][j];
    }
  }
  vector<int> cnt(color, 0);
  memset(used, false, sizeof used);
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(m); j++) {
      if (used[i][j] || a[i][j] == 0) continue;
      if (b[i][j] == 1) continue;
      cur = 0;
      dfs2(i, j);
      int num = c[i][j];
      if (cur > M) cnt[num]++;
    }
  }
  sort((cnt).begin(), (cnt).end());
  cout << color << endl;
  for (int i = 0; i < int(int((cnt).size())); i++) printf("%d ", cnt[i]);
  puts("");
}
int main() {
  cout << setprecision(10) << fixed;
  cerr << setprecision(5) << fixed;
  assert(read());
  solve();
  return 0;
}
