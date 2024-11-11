#include <bits/stdc++.h>
using namespace std;
bool _(int a, int b) { return a > b; }
int n, k, p[111][111], i, j, a, b, c, d, e, x = 1, y = 1;
int main() {
  cin >> n >> k;
  string s;
  for (i = 1; i <= n; i++) {
    cin >> s;
    for (j = 1; j <= n; j++) p[i][j] = (s[j - 1] == '.') ? 0 : -1;
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (!p[i][j]) {
        a = j;
        while (!p[i][j] && j <= n) j++;
        b = j - 1;
        if (b - a + 1 >= k) {
          c = b - a + 1 - k;
          for (d = a; d <= a + c; d++) p[i][d] = d - a + 1;
          for (d = a + c + 1; d <= b - c - 1; d++) p[i][d] = c + 1;
          for (d = b - c; d <= b; d++) p[i][d] = b - d + 1;
        }
      }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (p[j][i] >= 0) {
        a = j;
        while (p[j][i] >= 0 && j <= n) j++;
        b = j - 1;
        if (j - a >= k) {
          c = j - a - k;
          for (d = a; d <= a + c; d++) p[d][i] += d - a + 1;
          for (d = a + c + 1; d <= b - c - 1; d++) p[d][i] += c + 1;
          for (d = b - c; d <= b; d++) p[d][i] += b - d + 1;
        }
      }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (_(p[i][j], e)) e = p[i][j], x = i, y = j;
  printf("%d %d", x, y);
  return 0;
}
