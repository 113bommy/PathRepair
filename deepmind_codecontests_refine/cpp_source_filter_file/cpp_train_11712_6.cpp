#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char st[maxn];
int row[maxn], col[maxn];
int n, m, sum;
long long ans;
int comb(int x) { return x * (x + 1) / 2; }
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) {
    scanf("%s", st + 1);
    for (j = 1; j <= m; ++j)
      if (st[j] == '.') {
        ++sum;
        ans += m * (comb(i - 1) + comb(n - i));
        ans += n * (comb(j - 1) + comb(m - j));
      } else
        row[i] = j, col[j] = i;
  }
  for (i = 1; i <= n; ++i)
    if (row[i])
      for (j = 1; j <= m; ++j) {
        ans -= m * abs(i - j) + comb(row[i] - 1) + comb(m - row[i]);
        if (row[j]) ans += abs(i - j) + abs(row[i] - row[j]);
      }
  for (i = 1; i <= n; ++i)
    if (row[i]) {
      ans += (row[i] - 1) * (m - row[i]) * 4;
      for (j = i - 1; j >= 1; --j)
        if (row[j] && row[j] < row[j + 1])
          ans += (m - row[i]) * (row[j] - 1) * 4;
        else
          break;
      for (j = i + 1; j <= n; ++j)
        if (row[j] && row[j] < row[j - 1])
          ans += (m - row[i]) * (row[j] - 1) * 4;
        else
          break;
    }
  for (i = 1; i <= m; ++i)
    if (col[i]) {
      ans += (col[i] - 1) * (n - col[i]) * 4;
      for (j = i - 1; j >= 1; --j)
        if (col[j] && col[j] < col[j + 1])
          ans += (n - col[i]) * (col[j] - 1) * 4;
        else
          break;
      for (j = i + 1; j <= m; ++j)
        if (col[j] && col[j] < col[j - 1])
          ans += (n - col[i]) * (col[j] - 1) * 4;
        else
          break;
    }
  printf("%.10lf\n", (double)ans / sum / sum);
  return 0;
}
