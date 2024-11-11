#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char a[2001][2001];
int ans[2001];
void init() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%s", &a[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++) {
      if (j - i + 1 >= 0 && a[i][j - i + 1] == 'R') ans[j]++;
      if (j + i - 1 < m && a[i][j + i - 1] == 'L') ans[j]++;
      if (i + i - 1 <= n && a[i + i - 1][j] == 'U') ans[j]++;
    }
  for (int i = 0; i < m; i++) cout << ans[i] << " ";
}
int main() {
  init();
  return 0;
}
