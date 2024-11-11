#include <bits/stdc++.h>
#pragma comment(linker, "/stack:256000000")
using namespace std;
const int N = 1010, INF = 1000 * 1000 * 1000 + 7;
const long double eps = 1e-9;
template <typename X>
X gcd(X a, X b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
template <typename V>
V dist(V x1, V y1, V x2, V y2) {
  return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int n, m;
bool read() {
  if (!(cin >> n >> m)) {
    return 0;
  }
  return 1;
}
int a[N][N];
bool check(int x, int y) {
  for (int i = max(x - 3, 0); i < x; i++) {
    for (int j = max(y - 3, 0); j < y; j++) {
      int black = 0;
      for (int ii = 0; ii < 3; ++ii) {
        for (int jj = 0; jj < 3; ++jj) {
          int nx = i + ii;
          int ny = j + jj;
          if (nx >= n || ny >= n) break;
          black += a[nx][ny];
        }
      }
      if (black == 9) {
        return 1;
      }
    }
  }
  return 0;
}
bool solve() {
  if (!read()) return 0;
  int mi = INF;
  memset(a, 0, sizeof a);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    a[x][y] = 1;
    if (check(x, y)) {
      mi = min(i + 1, mi);
    }
  }
  if (mi >= INF / 2) {
    cout << -1 << endl;
  } else {
    cout << mi << endl;
  }
  return 1;
}
int main() {
  while (solve())
    ;
  return 0;
}
