#include <bits/stdc++.h>
using namespace std;
const int maxn = 200200;
const int inf = 0x3f3f3f3f;
int a[maxn], p[maxn], tot;
int s[maxn][111], mn[maxn * 4];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= 100; j++) s[i][j] = s[i - 1][j];
    s[i][a[i]]++;
  }
  int mx = 0, id = 0, id2 = 0;
  for (int i = 1; i <= 100; i++) {
    if (s[n][i] > mx)
      mx = s[n][i], id = i, id2 = 0;
    else if (s[n][i] == mx)
      id2 = i;
  }
  if (id2) {
    printf("%d\n", n);
    return 0;
  }
  p[++tot] = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] == id) p[++tot] = i;
  p[++tot] = n + 1;
  int ans = 0, B = 400004;
  for (int j = 1; j <= 100; j++)
    if (j != id) {
      for (int i = 0; i <= 2 * B; i++) mn[i] = inf;
      for (int i = 1; i <= tot; i++) {
        ans = max(ans, p[i] - mn[s[p[i] - 1][j] - i + B]);
        mn[s[p[i]][j] - i - 1 + B] = min(mn[s[p[i]][j] - i - 1 + B], p[i] + 1);
      }
    }
  printf("%d\n", ans);
  return 0;
}
