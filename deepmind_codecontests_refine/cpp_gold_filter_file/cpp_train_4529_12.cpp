#include <bits/stdc++.h>
using namespace std;
int n, k, a[400000], n1, n2, spt;
int f[6000][6000];
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  n1 = n % k;
  spt = n / k + 1;
  n2 = k - n1;
  for (int i = 0; i <= n1; ++i)
    for (int j = 0; j <= n2; ++j)
      if ((i + j) != 0) {
        f[i][j] = 2e9;
        if (i) {
          int v = (i - 1) * spt + j * (spt - 1) + 1;
          int up = a[v + spt - 1] - a[v];
          f[i][j] = min(f[i][j], f[i - 1][j] + up);
        }
        if (j) {
          int v = i * spt + (j - 1) * (spt - 1) + 1;
          int up = a[v + spt - 2] - a[v];
          f[i][j] = min(f[i][j], f[i][j - 1] + up);
        }
      }
  cout << f[n1][n2];
  return 0;
}
