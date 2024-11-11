#include <bits/stdc++.h>
using namespace std;
long long f[555][555], Ans[555];
int n, tmp[555][555], id[555];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &tmp[i][j]);
  for (int i = 1; i <= n; i++) scanf("%d", &id[n - i + 1]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) f[i][j] = tmp[id[i]][id[j]];
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= k; i++)
      for (int j = 1; j <= k; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (int i = 1; i <= k; i++)
      for (int j = 1; j <= k; j++) Ans[n - k + 1] += f[i][j];
  }
  for (int k = 1; k <= n; k++) printf("%I64d ", Ans[k]);
}
