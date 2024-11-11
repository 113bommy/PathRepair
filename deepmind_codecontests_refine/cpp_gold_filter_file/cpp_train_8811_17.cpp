#include <bits/stdc++.h>
using namespace std;
int n, k;
int l[105], r[105];
int f[2][200005];
int cur = 1, pre = 0;
int q[200005];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i <= 1; i++)
    for (int j = 0; j <= n; j++) f[i][j] = 1000000007;
  f[0][0] = 0;
  for (int i = 1; i <= k; i++) {
    int h = 1, t = 0;
    scanf("%d %d", &l[i], &r[i]);
    for (int j = 0; j <= r[i]; j++) {
      if (j <= n) {
        while (t >= h && f[pre][j] <= f[pre][q[t]]) t--;
        t++;
        q[t] = j;
      }
      while (h <= t && q[h] < j - (r[i] - l[i])) h++;
      f[cur][j] = min(f[pre][j], f[pre][q[h]] + 2);
    }
    h = 1, t = 0;
    for (int j = r[i]; j >= 0; j--) {
      if (r[i] - j <= n) {
        while (t >= h && f[pre][r[i] - j] <= f[pre][q[t]]) t--;
        t++;
        q[t] = r[i] - j;
      }
      while (h <= t && q[h] < l[i] - j) h++;
      f[cur][j] = min(f[cur][j], f[pre][q[h]] + 1);
    }
    swap(f[cur], f[pre]);
  }
  if (f[pre][n] == 1000000007)
    printf("Hungry\n");
  else {
    printf("Full\n");
    printf("%d\n", f[pre][n]);
  }
  return 0;
}
