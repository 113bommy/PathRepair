#include <bits/stdc++.h>
using namespace std;
const int maxn = 600;
int mmp[maxn][maxn], n, m;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> mmp[i][j];
  int posx = n - 1, posy = m - 1;
  while (posx && posy) {
    if (mmp[posx][posy] == 0)
      mmp[posx][posy] = min(mmp[posx + 1][posy], mmp[posx][posy + 1]) - 1;
    for (int i = posx - 1; i; --i)
      if (mmp[i][posy] == 0)
        mmp[i][posy] = min(mmp[i][posy + 1], mmp[i + 1][posy]) - 1;
    for (int j = posy - 1; j; --j)
      if (mmp[posx][j] == 0)
        mmp[posx][j] = min(mmp[posx + 1][j], mmp[posx][j + 1]) - 1;
    --posx, --posy;
  }
  if (posx) {
    for (int i = posx; i; --i)
      if (mmp[i][1] == 0) mmp[i][1] = min(mmp[i + 1][1], mmp[i][2]) - 1;
  }
  if (posy)
    for (int i = posy; i; --i)
      if (mmp[1][i] == 0) mmp[1][i] = min(mmp[2][i], mmp[1][i + 1]) - 1;
  bool f = true;
  int sum = 0;
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < m; ++j) {
      if (mmp[i][j] <= 0 || mmp[i][j] >= mmp[i + 1][j] ||
          mmp[i][j] >= mmp[i][j + 1])
        f = false;
    }
  for (int i = 1; i < n; ++i)
    if (mmp[i][m] >= mmp[i + 1][m]) f = false;
  for (int i = 1; i < m; ++i)
    if (mmp[n][i] >= mmp[n][i + 1]) f = false;
  if (f) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) sum += mmp[i][j];
  } else
    sum = -1;
  printf("%d", sum);
}
