#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long dp[1 << 18][100];
int num[10];
int d[19];
int len;
int main() {
  cin >> n >> m;
  int len = 0;
  while (n) {
    num[n % 10]++;
    d[len++] = n % 10;
    n /= 10;
  }
  long long res = 1;
  for (int i = 0; i < 10; i++) {
    while (num[i]) {
      res *= num[i];
      num[i]--;
    }
  }
  dp[0][0] = 1;
  for (int s = 0; s < (1 << len); s++)
    for (int i = 0; i < len; i++)
      if (s || d[i]) {
        if (s & (1 << i)) continue;
        for (int k = 0; k < m; k++) {
          dp[s | (1 << i)][(10 * k + d[i]) % m] += dp[s][k];
        }
      }
  cout << dp[(1 << len) - 1][0] / res << endl;
  return 0;
}
