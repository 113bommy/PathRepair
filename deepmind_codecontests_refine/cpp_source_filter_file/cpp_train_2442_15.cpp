#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[6][2000];
bool bo[2000][2000];
int order[6][2000];
int f[2000];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      order[i][a[i][j]] = j;
    }
  memset(bo, true, sizeof(bo));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int s = 0; s < k; s++) bo[i][j] &= (order[s][i] <= order[s][j]);
  int ans = 0;
  for (int i = 1; i <= n; i++) f[i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) {
      if (bo[a[0][j]][a[0][i]]) f[i] = max(f[i], f[j] + 1);
      ans = max(ans, f[i]);
    }
  printf("%d\n", ans);
}
