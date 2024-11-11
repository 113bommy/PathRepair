#include <bits/stdc++.h>
using namespace std;
long long f[1001][1001], s[1001][1001];
long long a[10001], ans[10001];
int main() {
  int n, m, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + n + 1);
  a[0] = -10080124100;
  long long sum = 0;
  for (int t = 1; t * (k - 1) <= a[n]; t++) {
    s[0][0] = f[0][0] = 1;
    int l = 0;
    for (int i = 1; i <= n; i++) {
      if (a[l] <= a[i] - t) l++;
      for (int j = 0; j <= k; j++) {
        if (j != 0) f[i][j] = s[l - 1][j - 1] % 998244353;
        s[i][j] = (s[i - 1][j] + f[i][j]) % 998244353;
      }
      sum = (sum + f[i][k]) % 998244353;
    }
  }
  cout << sum << endl;
  return 0;
}
