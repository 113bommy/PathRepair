#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
int a[MAXN][MAXN];
int n, k;
int d[MAXN];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) scanf("%d", &a[i][j]);
  }
  if (k == 1) {
    long long ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        if (a[i][j] != -1) ans += a[i][j];
    cout << ans * 2 / n << endl;
  } else if (k == 2) {
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) a[j][i] = a[i][j];
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        if (a[i][j] != -1) d[i]++, d[j]++;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        if (j != i && a[i][j] != -1) ans += a[i][j] * (long long)(d[i] - 1);
    }
    ans /= n * (n - 1) / 2;
    cout << ans << endl;
  } else {
    long long ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        if (a[i][j] != -1) ans += a[i][j];
    ans = ans * (n - 1) / n;
    cout << ans << endl;
  }
  return 0;
}
