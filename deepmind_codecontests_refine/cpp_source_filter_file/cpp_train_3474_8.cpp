#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, k, its;
long long s[N * 2][N * 2];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i)
    for (int j = 1, x; j <= m; ++j)
      scanf("%d", &x), s[i + j - 1][i - j + m] = x;
  for (int i = 1; i <= n + m - 1; ++i)
    for (int j = 1; j <= n + m - 1; ++j)
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
  long long mx = -1;
  int ansx = 0, ansy = 0;
  for (int i = k; i <= n - k + 1; ++i)
    for (int j = k; j <= m - k + 1; ++j) {
      long long sm = 0;
      int x = i + j - 1, y = i - j + m;
      for (int l = 0; l < k; ++l)
        sm += s[x + l][y + l] - s[x - l - 1][y + l] - s[x + l][y - l - 1] +
              s[x - l - 1][y - l - 1];
      if ((++its) * k > 10000000) {
        printf("%d %d\n", ansx, ansy);
        return 0;
      }
      if (sm > mx) {
        mx = sm;
        ansx = i;
        ansy = j;
      }
    }
  printf("%d %d\n", ansx, ansy);
}
