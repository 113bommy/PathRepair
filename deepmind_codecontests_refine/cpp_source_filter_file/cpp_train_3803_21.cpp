#include <bits/stdc++.h>
using namespace std;
int n, m, q, s[10005][4];
int mtx[105][105];
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) mtx[i][j] = 1234567890;
  for (int i = (1); i <= (q); i++) {
    scanf("%d", &s[i][0]);
    if (s[i][0] == 3)
      scanf("%d %d %d", &s[i][1], &s[i][2], &s[i][3]);
    else
      scanf("%d", &s[i][1]);
  }
  for (int i = (q); i >= (1); i--) {
    if (s[i][0] == 3)
      mtx[s[i][1]][s[i][2]] = s[i][3];
    else if (s[i][0] == 1) {
      for (int j = (m); j >= (2); j--)
        swap(mtx[s[i][1]][j], mtx[s[i][1]][j - 1]);
    } else {
      for (int j = (n); j >= (2); j--)
        swap(mtx[j][s[i][1]], mtx[j - 1][s[i][1]]);
    }
  }
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++)
      if (s[i][j] == 1234567890) s[i][j] = 0;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++)
      printf("%d%c", mtx[i][j], j == m ? '\n' : ' ');
  return 0;
}
