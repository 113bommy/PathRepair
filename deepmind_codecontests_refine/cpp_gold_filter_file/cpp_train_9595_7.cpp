#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 5010;
int n, k, a[N], f[N][N], s[N][N], res[100010], ans;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  a[0] = -1e9;
  for (int i = 1; i * (k - 1) <= a[n]; i++) {
    f[0][0] = 1;
    int now = 0;
    s[0][0] = 1;
    for (int j = 1; j <= n; j++) {
      while (a[now] <= a[j] - i) now++;
      for (int m = 0; m <= k; m++) {
        if (m) f[j][m] = s[now - 1][m - 1];
        s[j][m] = (s[j - 1][m] + f[j][m]) % mod;
      }
      res[i] = (res[i] + f[j][k]) % mod;
    }
    ans = (ans + res[i]) % mod;
  }
  printf("%d", ans);
}
