#include <bits/stdc++.h>
using namespace std;
ifstream fi("908B.INP");
char c[55][55];
int n, m, a[5] = {0, 1, 2, 3}, x, y, res;
struct data {
  int x, y;
} S, E;
string s;
int main() {
  fi >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      fi >> c[i][j];
      if (c[i][j] == 'E') {
        E.x = i;
        E.y = j;
      }
      if (c[i][j] == 'S') {
        S.x = i;
        S.y = j;
      }
    }
  fi >> s;
  for (int i = 1; i <= 24; ++i) {
    x = S.x;
    y = S.y;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] - '0' == a[0]) {
        --x;
        if (!x) break;
      }
      if (s[j] - '0' == a[1]) {
        ++y;
        if (y > m) break;
      }
      if (s[j] - '0' == a[2]) {
        ++x;
        if (x > n) break;
      }
      if (s[j] - '0' == a[3]) {
        --y;
        if (!y) break;
      }
      if (c[x][y] == '#') break;
      if (x == E.x && y == E.y) break;
    }
    if (x == E.x && y == E.y) ++res;
    next_permutation(a, a + 4);
  }
  cout << res;
  return 0;
}
