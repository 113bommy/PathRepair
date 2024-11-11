#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
long long a[MAXN][MAXN], b[MAXN][MAXN], s[MAXN][MAXN];
int n, m, k;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int first;
      scanf("%d", &first);
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + first;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= m; ++j) {
      if (j) a[i][j] = a[i - 1][j - 1] + s[i][j];
      if (i >= k && j >= k) a[i][j] -= s[i - k][j - k];
      b[i][j] = b[i - 1][j + 1] + s[i][j];
      if (i >= k && j + k <= m) b[i][j] -= s[i - k][j + k];
    }
  long long Tohka = 0, first, second;
  for (int i = k; i + k - 1 <= n; ++i)
    for (int j = k; j + k - 1 <= m; ++j) {
      long long t = b[i + k - 1][j] + b[i - 1][j - k] - a[i + k - 1][j - 1] -
                    a[i - 1][j + k - 1];
      if (Tohka < t) Tohka = t, first = i, second = j;
    }
  cout << first << " " << second << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
