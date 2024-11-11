#include <bits/stdc++.h>
using namespace std;
long long dp[3001][3010];
int main() {
  long long n, l, k = 0;
  cin >> n >> l;
  long long a[3000], b[3000], c[3000];
  for (int i = int(1); i <= int(n); i++) {
    cin >> a[i] >> b[i];
    c[i] = i;
    if (a[i] != b[i]) {
      k++;
      c[n + k] = i;
      a[n + k] = b[i];
      b[n + k] = a[i];
    }
  }
  n += k;
  long long ans = 0;
  for (int i = int(1); i <= int(l); i++) {
    for (int j = int(1); j <= int(n); j++) {
      if (a[j] == i) dp[i][j] = 1;
      for (int last = int(1); last <= int(n); last++) {
        if (b[last] == a[j] && i >= a[j] && c[j] != c[last])
          dp[i][j] = (dp[i][j] + dp[i - a[j]][last]) % 1000000007;
      }
      if (i == l) ans = (ans + dp[l][j]) % 1000000007;
    }
  }
  cout << ans;
}
