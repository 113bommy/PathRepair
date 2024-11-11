#include <bits/stdc++.h>
const int N = 1e5 + 5;
char str[N];
int n, s[N];
long long f[N][11], ans;
inline int nex(int i, int j) { return (9 + i * (i - 1) / 2 + j + 1) % 11; }
int main() {
  scanf("%s", str + 1);
  n = strlen(str + 1);
  for (int i = 1; i <= n; ++i) s[i] = str[i] - '0';
  for (int i = 1; i <= n; ++i)
    if (s[i]) ++f[i][s[i]];
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= 10; ++j) {
      if (s[i] < j) f[i][nex(j, s[i])] += f[i - 1][j];
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= 10; ++j) ans += f[i][j];
  printf("%d\n", ans);
  return 0;
}
