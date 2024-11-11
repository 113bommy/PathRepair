#include <bits/stdc++.h>
using namespace std;
int a[105][105], s[105], S[105], ans[105];
int n, i, j, k, cnt;
char tmp[105];
int check() {
  for (int i = 1; i <= n; i++) {
    int now = 0;
    for (int j = 1; j <= n; j++)
      if (a[i][j]) now += ans[j];
    if (now == S[i]) return 0;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (scanf("%s", tmp + 1), j = 1; j <= n; j++) a[j][i] = tmp[j] - '0';
  for (i = 1; i <= n; i++) scanf("%d", &s[i]), S[i] = s[i];
  for (j = 1; j <= n; j++) {
    k = 0;
    for (i = 1; i <= n; i++)
      if (!ans[i] && s[i] == 0) k = i;
    if (!k) break;
    ans[k] = 1;
    for (i = 1; i <= n; i++)
      if (a[i][k]) s[i]--;
  }
  if (!check()) return puts("-1"), 0;
  for (i = 1; i <= n; i++) cnt += ans[i];
  printf("%d\n", cnt);
  for (i = 1; i <= n; i++)
    if (ans[i]) printf("%d ", i);
}
