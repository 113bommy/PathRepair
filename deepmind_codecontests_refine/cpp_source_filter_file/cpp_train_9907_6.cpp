#include <bits/stdc++.h>
using namespace std;
int n, m, tmp, a[1000];
int co[1000000], col[1000000];
long long int dp[1000][1000];
void read(void) {
  scanf("%d%d", &tmp, &m);
  for (int i = 0; i < m; i++) scanf("%d", &co[i]);
  n = 1;
  col[0] = co[0];
  for (int i = 1; i < m; i++)
    if (co[i] != co[i - 1]) col[n++] = co[i];
  return;
}
bool judge(void) {
  int l, r;
  for (int i = tmp; i >= 2; i--) {
    l = r = 0;
    for (int j = 0; j < n; j++)
      if (col[j] == i) r = j;
    for (int j = n - 1; j >= 0; j--)
      if (col[j] == i) l = j;
    for (int j = l; j < r; j++)
      if (col[j] < col[l]) return 1;
    for (int j = l; j < r; j++) a[j] = i;
  }
  return 0;
}
int main(void) {
  read();
  if (n >= 2 * tmp || judge()) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < n; i++) dp[i][i] = 1;
  for (int k = 1; k < n; k++)
    for (int l = 0; l + k < n; l++) {
      long long int t1, t2;
      int r = l + k, posl = l, posr = l;
      for (int i = l + 1; i <= r; i++) {
        if (col[posl] > col[i]) posl = i;
        if (col[posr] >= col[i]) posr = i;
      }
      if (posl == l)
        t1 = 1;
      else {
        t1 = dp[l][posl - 1] * 2;
        for (int i = l + 1; i < posl; i++)
          if (a[i - 1] <= col[posl])
            t1 = (t1 + dp[l][i - 1] * dp[i][posl - 1]) % 998244353;
      }
      if (posr == r)
        t2 = 1;
      else {
        t2 = dp[posr + 1][r] * 2;
        for (int i = posr + 1; i < r; i++)
          if (a[i] <= col[posl])
            t2 = (t2 + dp[posr + 1][i] * dp[i + 1][r]) % 998244353;
      }
      dp[l][r] = t1 * t2 % 998244353;
      int lst = posl;
      for (int i = lst + 1; i <= r; i++)
        if (col[i] == col[lst]) {
          dp[l][r] = dp[l][r] * dp[lst + 1][i - 1] % 998244353;
          lst = i;
        }
    }
  printf("%lld\n", dp[0][n - 1]);
  return 0;
}
