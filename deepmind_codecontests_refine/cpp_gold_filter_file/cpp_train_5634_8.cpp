#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int fx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int fy[] = {1, 0, -1, 1, -1, 1, 0, -1};
char ma[maxn][maxn];
int n, m;
bool check(int xx, int yy) {
  for (int i = 0; i < 8; i++) {
    int x = xx + fx[i];
    int y = yy + fy[i];
    bool fla = 1;
    if (x >= 1 && x <= n && y >= 1 && y <= m)
      ;
    else
      continue;
    for (int j = 0; j < 8; j++) {
      int xxx = x + fx[j];
      int yyy = y + fy[j];
      if (xxx >= 1 && xxx <= n && yyy >= 1 && yyy <= m && ma[xxx][yyy] == '#')
        ;
      else
        fla = 0;
    }
    if (fla) return 1;
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> ma[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (ma[i][j] == '#' && check(i, j) == 0) {
        cout << "NO" << endl;
        return 0;
      }
    }
  cout << "YES" << endl;
  return 0;
}
