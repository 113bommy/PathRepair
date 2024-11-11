#include <bits/stdc++.h>
using namespace std;
int n, ii, l, r, top, a[200100], b[32][200100][2], s[200100];
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i <= 31; i++) {
    b[i][1][0] = 0;
    b[i][n][1] = n + 1;
    for (int j = 1; j < n; j++)
      if (a[j] & (1 << i))
        b[i][j + 1][0] = j;
      else
        b[i][j + 1][0] = b[i][j][0];
    for (int j = n; j > 1; j--)
      if (a[j] & (1 << i))
        b[i][j - 1][1] = j;
      else
        b[i][j - 1][1] = b[i][j][1];
  }
  a[n + 1] = 1e9 + 1;
  for (int i = 1; i <= n + 1; i++) {
    while (top && a[s[top]] <= a[i]) {
      ii = s[top--];
      l = s[top] + 1;
      r = i - 1;
      for (int j = 0; j <= 31; j++) {
        if (a[ii] & (1 << j)) continue;
        l = max(l, min(b[j][ii][0] + 1, ii));
        r = min(r, max(b[j][ii][1] - 1, ii));
      }
      ans += (ii - l + 1) * (r - ii + 1) - 1;
    }
    s[++top] = i;
  }
  printf("%I64d", 1ll * n * (n - 1) / 2 - ans);
  return 0;
}
