#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:67108864")
using namespace std;
const int inf = 1000 * 1000 * 1000 + 7;
int n, m;
char buf[1 << 12];
vector<vector<int> > M;
long long DP1[1 << 8];
long long DP2[1 << 8][1 << 8][2];
const string H[7] = {".........", "....O....", "O.......O", "O...O...O",
                     "O.O...O.O", "O.O.O.O.O", "OOO...OOO"};
const string V[7] = {".........", "....O....", "..O...O..", "..O.O.O..",
                     "O.O...O.O", "O.O.O.O.O", "O.OO.OO.O"};
bool check(int x) {
  if (n & 1) return 0;
  bool res = 1;
  for (int i = 0; i < n; i++) res &= (M[i][x] == 3);
  return res;
}
int ch(int x, int y) { return M[x][y] & M[x][y + 1] & 1; }
int cv(int x, int y) { return (M[x][y] & M[x + 1][y] & 2) >> 1; }
long long dp2(int x, int y, int t) {
  if (x == n) return t;
  if (x == n - 1) return ch(x, y);
  if (DP2[x][y][t] == -1) {
    long long& res = DP2[x][y][t];
    res = ch(x, y) * dp2(x + 1, y, 1) +
          cv(x, y) * cv(x, y + 1) * dp2(x + 2, y, t);
    res %= inf;
  }
  return DP2[x][y][t];
}
long long dp1(int x) {
  if (x == m) return 1;
  if (x == m - 1) return check(x);
  if (DP1[x] == -1) {
    long long& res = DP1[x];
    res = check(x) * dp1(x + 1) + dp2(0, x, 0) * dp1(x + 2);
    res %= inf;
  }
  return DP1[x];
}
int main() {
  memset(DP1, -1, sizeof(DP1));
  memset(DP2, -1, sizeof(DP2));
  scanf("%d%d\n", &n, &m);
  M.resize(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    gets(buf);
    vector<string> S(m);
    for (int j = 0; j < 3; ++j) {
      gets(buf);
      int t = strlen(buf);
      int cur = -1;
      for (int k = 0; k < t; ++k)
        if (buf[k] == '#')
          ++cur;
        else
          S[cur] += buf[k];
    }
    for (int j = 0; j < m; ++j)
      for (int k = 0; k < 7; ++k)
        if (H[k] == S[j]) M[i][j] |= 1;
    for (int j = 0; j < m; ++j)
      for (int k = 0; k < 7; ++k)
        if (V[k] == S[j]) M[i][j] |= 2;
  }
  gets(buf);
  if ((m * n) & 1) {
    printf("0\n");
    return 0;
  }
  printf("%d\n", dp1(0));
  return 0;
}
