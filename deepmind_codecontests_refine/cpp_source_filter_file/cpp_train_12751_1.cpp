#include <bits/stdc++.h>
using namespace std;
long long mem[2][502][502];
int main() {
  int n, m, K, i, j, k, a;
  long long mod;
  bool flag = 1;
  scanf("%d%d%d%I64d", &n, &m, &K, &mod);
  mem[0][0][0] = 1;
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    for (j = 0; j <= m; j++) {
      for (k = 0; k <= K; k++) {
        mem[flag][j][k] = mem[!flag][j][k];
        if (k - a >= 0) {
          mem[flag][j][k] =
              ((long long)mem[flag][j][k] + mem[flag][j - 1][k - a]) % mod;
        }
      }
    }
    flag = !flag;
  }
  long long ans = 0;
  flag = !flag;
  for (i = 0; i <= K; i++) {
    ans = ((long long)ans + mem[flag][m][i]) % mod;
  }
  printf("%I64d", ans);
}
