#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int MAXM = 100100;
char s[MAXN][MAXM];
int a[MAXM];
int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = (0); i < (n); ++i) scanf("%s", s[i]);
  for (int j = (0); j < (m); ++j) {
    for (int i = (0); i < (n); ++i)
      if (s[i][j] == '1') a[j] |= 1 << i;
  }
  static int f[MAXN + 1][1 << MAXN];
  for (int i = (0); i < (m); ++i) f[0][a[i]]++;
  for (int i = (0); i < (n); ++i)
    for (int j = n - 1; j >= 0; --j)
      for (int s = (0); s < (1 << n); ++s) f[j + 1][s ^ (1 << i)] += f[j][s];
  static int ans[1 << MAXN];
  for (int s = (0); s < (1 << n); ++s)
    for (int j = (0); j < (n + 1); ++j) ans[s] += min(j, n - j) * f[j][s];
  printf("%d\n", *min_element(ans, ans + (1 << n)));
  return 0;
}
