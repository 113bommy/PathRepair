#include <bits/stdc++.h>
using namespace std;
const long long P = 1000000007;
bool ban[1010][1010];
int bel[1010];
int n, m;
long long ans;
long long tag[1010], f[1010][1010], s[1010];
char str[1010];
int main() {
  scanf("%d%d", &m, &n);
  int i, j, siz;
  for (i = 1; i <= n; i++) {
    scanf("%s", str + 1);
    for (j = 1; j <= m; j++)
      if (str[j] == '1') tag[j] |= 1ll << (i - 1);
  }
  ans = f[0][0] = 1;
  for (i = 1; i <= m; i++)
    for (j = 1; j <= i; j++)
      f[i][j] = (f[i - 1][j] * j + f[i - 1][j - 1]) % P,
      s[i] = (s[i] + f[i][j]) % P;
  for (i = 1; i <= m; i++)
    if (!bel[i]) {
      siz = 0;
      for (j = i; j <= m; j++)
        if (tag[j] == tag[i]) bel[j] = i, siz++;
      ans = ans * s[siz] % P;
    }
  printf("%lld", ans);
  return 0;
}
