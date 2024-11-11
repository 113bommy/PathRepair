#include <bits/stdc++.h>
using namespace std;
int n, m, b;
string sky[510];
int stars[510][510];
int movi[] = {1, 0, -1, 0};
int movj[] = {0, 1, 0, -1};
int main() {
  cin >> n >> m >> b;
  for (int i = 0; i < n; i++) cin >> sky[i];
  memset(stars, 0, sizeof(stars));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (sky[i][j] == '1') {
        int valid = 0;
        for (int k = 0; k < 4; k++) {
          int ni = i + movi[k], nj = j + movj[k];
          if (0 <= ni && ni < n && 0 <= nj && nj < m && sky[ni][nj] == '1')
            valid++;
        }
        stars[i][j] = (valid == 4);
      }
  for (int i = 1; i < m; i++) stars[0][i] += stars[0][i - 1];
  for (int i = 1; i < n; i++) stars[i][0] += stars[i - 1][0];
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      stars[i][j] += stars[i][j - 1] + stars[i - 1][j] - stars[i - 1][j - 1];
  long long ret = 0;
  for (int i = 1; i < n; i++)
    for (int j = i; j < n - 1; j++) {
      for (int k = 0; k < m - 1; k++) {
        int l = k, r = m - 1;
        while (l < r - 1) {
          int mid = (l + r) / 2;
          int cnt =
              stars[j][mid] - stars[i - 1][mid] - stars[j][k] + stars[i - 1][k];
          if (cnt < b)
            l = mid;
          else
            r = mid;
        }
        ret += m - r - 1;
      }
    }
  cout << ret << endl;
  return 0;
}
