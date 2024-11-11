#include <bits/stdc++.h>
using namespace std;
const int MAXN = 333;
int n, k, m;
char star[MAXN][MAXN];
inline bool isstar(int x, int y, int r) {
  if (star[x][y] != '*' || star[x + r][y] != '*' || star[x][y + r] != '*')
    return false;
  if (star[x - r][y] != '*' || star[x][y - r] != '*') return false;
  return true;
}
int main() {
  cin.sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> star[i][j];
  for (int radii = 1; radii <= 160; radii++)
    for (int i = radii; i < n - radii; i++)
      for (int j = radii; j < m - radii; j++) {
        if (isstar(i, j, radii)) k--;
        if (k == 0) {
          i++;
          j++;
          cout << i << " " << j << endl;
          cout << i - radii << " " << j << endl;
          cout << i + radii << " " << j << endl;
          cout << i << " " << j - radii << endl;
          cout << i << " " << j + radii << endl;
          return 0;
        }
      }
  cout << -1 << endl;
  return 0;
}
