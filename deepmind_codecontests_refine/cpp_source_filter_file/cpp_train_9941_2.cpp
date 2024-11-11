#include <bits/stdc++.h>
using namespace std;
long long int k, c[1100] = {0}, ans[1100] = {0}, C[1100][1100] = {0},
                 tot[1100] = {0};
long long int dp(long long int x) {
  if (x == 1) return 1;
  if (ans[x]) return ans[x];
  return ans[x] = ((dp(x - 1)) * (C[tot[x] - 1][c[x] - 1])) % 1000000007;
}
int main() {
  for (int i = 0; i < 1100; i++)
    for (int j = 0; j <= i; j++) {
      if (!i && !j)
        C[i][j] = 1;
      else {
        C[i][j] = C[i - 1][j] % 1000000007;
        if (j) C[i][j] += C[i - 1][j - 1] % 1000000007;
        C[i][j] = C[i][j] % 1000000007;
      }
    }
  scanf("%I64d", &k);
  for (int i = 1; i <= k; i++) scanf("%I64d", &c[i]);
  for (int i = 1; i <= k; i++) tot[i] = tot[i - 1] + c[i];
  dp(k);
  printf("%I64d\n", ans[k]);
}
