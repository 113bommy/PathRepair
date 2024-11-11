#include <bits/stdc++.h>
const int MAXN = 2e5 + 1;
int dat[2][MAXN], ans[MAXN], n;
char str[MAXN];
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < 2; ++i) {
    scanf("%s", str + 1);
    for (int j = 1; j <= n; ++j) dat[i][j] = str[j] - 'a';
  }
  for (int i = 1; i <= n; ++i) {
    ans[i] += (dat[0][i] + dat[1][i]) >> 1;
    if ((dat[0][i] + dat[1][i]) & 1) ans[i + 1] += 13;
  }
  for (int i = n; i; --i)
    if (ans[i] >= 26) ans[i + 1] += ans[i] / 26, ans[i] %= 26;
  for (int i = 1; i <= n; ++i) putchar(ans[i] + 'a');
  return 0;
}
