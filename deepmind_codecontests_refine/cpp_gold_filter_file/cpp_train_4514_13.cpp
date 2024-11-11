#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char s[maxn];
int n, len;
long long f[maxn][5];
int main() {
  long long ans = 0;
  scanf("%s", s);
  int len = strlen(s);
  s[len] = s[0];
  for (int j = 0; j < 2; j++) {
    memset(f, 0, sizeof f);
    f[0][j] = 1;
    for (int i = 0; i < len; i++) {
      if (s[i] == 'A') {
        f[i + 1][0] += f[i][0] + f[i][1];
        if (s[i + 1] == 'B') f[i + 1][1] += f[i][1];
      } else {
        f[i + 1][0] += f[i][1];
        f[i + 1][1] += f[i][s[i + 1] - 'A'];
      }
      ans += f[len][j];
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
