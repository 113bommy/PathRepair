#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[101][101];
bool check(int x, int y, char ch) {
  for (int i = 0; i < m; ++i) {
    if (c[x][i] == ch && i != y) return false;
  }
  for (int i = 0; i < n; ++i) {
    if (c[i][y] == ch && i != x) return false;
  }
  return true;
}
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> c[i][j];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (check(i, j, c[i][j])) cout << c[i][j];
    }
  }
  return 0;
}
