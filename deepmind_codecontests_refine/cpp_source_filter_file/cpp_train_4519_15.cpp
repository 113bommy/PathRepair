#include <bits/stdc++.h>
using namespace std;
int n, k, a[2100][2100], q[2100];
long double c[2100][2100], ans;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      a[j][i] = a[i][j];
    }
  for (int i = 1; i <= n; i++) a[i][i] = -1;
  for (int i = 1; i <= n; i++) {
    q[0] = 0;
    for (int j = 1; j <= n; j++)
      if (a[i][j] != -1) q[++q[0]] = a[i][j];
    if (q[0] < k) continue;
    for (int j = 1; j <= q[0]; j++)
      ans = ans + q[j] * c[q[0] - 1][k - 1] / c[n][k];
  }
  cout << (long long)ans + (1e-4) << endl;
  return 0;
}
