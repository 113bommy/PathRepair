#include <bits/stdc++.h>
using namespace std;
int w[1003][1003];
pair<int, int> iahub[1003][1003], iahubina[1003][1003];
int main() {
  int n, m, i, j, gain = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &w[i][j]);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      iahub[i][j].first =
          max(iahub[i][j - 1].first, iahub[i - 1][j].first) + w[i][j];
  for (i = n; i >= 1; i--)
    for (j = m; j >= 1; j--)
      iahub[i][j].second =
          max(iahub[i][j + 1].second, iahub[i + 1][j].second) + w[i][j];
  for (i = n; i >= 1; i--)
    for (j = 1; j <= m; j++)
      iahubina[i][j].first =
          max(iahubina[i][j - 1].first, iahubina[i + 1][j].first) + w[i][j];
  for (i = 1; i <= n; i++)
    for (j = m; j >= 1; j--)
      iahubina[i][j].second =
          max(iahubina[i][j + 1].second, iahubina[i - 1][j].second) + w[i][j];
  for (i = 2; i < n; i++)
    for (j = 2; j < m; j++) {
      gain =
          max(gain, iahub[i][j - 1].first + iahub[i][j + 1].second +
                        iahubina[i + 1][j].first + iahubina[i - 1][j].second);
      gain =
          max(gain, iahub[i - 1][j].first + iahub[i + 1][j].second +
                        iahubina[i][j - 1].first + iahubina[i][j + 1].second);
    }
  printf("%d\n", gain);
  return 0;
}
