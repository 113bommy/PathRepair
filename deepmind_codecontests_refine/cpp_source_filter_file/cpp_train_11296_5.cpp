#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795l;
template <typename T>
inline auto sqr(T x) -> decltype(x * x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 1010;
int n, m;
int k;
char c[N][N];
int color[N][N];
int cnt;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int res[N * N];
void dfs(int x, int y) {
  color[x][y] = cnt;
  for (int i = int(0); i < int(4); ++i) {
    int nx = dx[i] + x, ny = y + dy[i];
    if (c[nx][ny] != '.' || color[nx][ny] >= 0) continue;
    dfs(nx, ny);
  }
}
int main() {
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision(20);
  cin >> n >> m >> k;
  string q;
  getline(cin, q);
  for (int i = int(0); i < int(n); ++i) gets(c[i]);
  memset(color, -1, sizeof(color));
  cnt = 0;
  for (int i = int(0); i < int(n); ++i) {
    for (int j = int(0); j < int(m); ++j) {
      if (color[i][j] < 0 && c[i][j] == '.') {
        dfs(i, j);
        cnt++;
      }
    }
  }
  memset(res, 0, sizeof(res));
  for (int i = int(0); i < int(n); ++i)
    for (int j = int(0); j < int(n); ++j) {
      if (color[i][j] < 0) continue;
      for (int k = int(0); k < int(4); ++k) {
        int nx = i + dx[k], ny = j + dy[k];
        if (c[nx][ny] == '*') res[color[i][j]]++;
      }
    }
  for (int i = int(0); i < int(k); ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    cout << res[color[x][y]] << endl;
  }
  return 0;
}
