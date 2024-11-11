#include <bits/stdc++.h>
using namespace std;
const int maxn = 305, N = 4e5;
int mv[N][2][2], am[maxn][maxn], cnt = 0;
string s;
void add(int x1, int y1, int x2, int y2) {
  mv[++cnt][0][0] = x1;
  mv[cnt][0][1] = y1;
  mv[cnt][1][0] = x2;
  mv[cnt][1][1] = y2;
  ++am[x2][y2];
}
void Move(int x, int y, bool t) {
  if (t) {
    if (x != 2)
      add(x, y, 2, y);
    else
      add(x, y, 2, y == 1 ? 2 : 1);
  } else {
    if (x != 1)
      add(x, y, 1, y);
    else
      add(x, y, 1, y == 1 ? 2 : 1);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> s;
      for (int k = s.size() - 1; k >= 0; k--) Move(i, j, s[k] == '1');
    }
  for (int i = 1; i <= 2; i++)
    for (int j = 2; j <= m; j++) {
      for (int k = 1; k <= am[i][j]; k++) add(i, j, i, 1);
      am[i][j] = 0;
    }
  int tot = cnt;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> s;
      for (int k = 0; k < s.size(); k++) Move(i, j, s[k] == '1');
    }
  for (int i = 1; i <= 2; i++)
    for (int j = 2; j <= m; j++)
      for (int k = 1; k <= am[i][j]; k++) add(i, j, i, 1);
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++)
    printf("%d %d %d %d\n", mv[i][0][0], mv[i][0][1], mv[i][1][0], mv[i][1][1]);
  for (int i = cnt; i > tot; i--)
    printf("%d %d %d %d\n", mv[i][1][0], mv[i][1][1], mv[i][0][0], mv[i][0][1]);
}
