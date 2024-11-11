#include <bits/stdc++.h>
using namespace std;
int a[1010101];
int b[1010101];
int c[1010101], d[1010101];
long long dp[1010101][2];
long long l;
long long n, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i < l % n) c[i] = a[i];
  }
  sort(a, a + n);
  long long len = l % n;
  sort(c, c + len);
  int cntr = len - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1 || a[i] != a[i + 1])
      b[i] = i;
    else
      b[i] = b[i + 1];
    if (cntr >= 0 && c[cntr] == a[i]) {
      d[cntr] = b[i];
      cntr--;
    }
  }
  for (int i = 0; i < n; i++) dp[i][0] = i + 1;
  long long res = l % 1000000007;
  for (long long i = 1; i < k; i++) {
    if ((i + 1) * n <= l) {
      for (int j = 0; j < n; j++) {
        dp[j][i % 2] = dp[b[j]][(i + 1) % 2];
        if (j > 0) dp[j][i % 2] += dp[j - 1][i % 2];
        dp[j][i % 2] %= 1000000007;
      }
      res += (((l / n - i) % 1000000007) * dp[n - 1][i % 2]) % 1000000007;
      res %= 1000000007;
    }
    if (len && i * n < l) {
      long long sum = 0;
      for (int j = 0; j < len; j++) {
        sum += dp[d[j]][(i + 1) % 2];
        sum %= 1000000007;
      }
      res += sum;
      res %= 1000000007;
    }
  }
  cout << res << "\n";
}
