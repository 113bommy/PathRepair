#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6;
long long dp[11][MAXN];
long long dp2[11][MAXN];
long long ans;
int main() {
  for (long long i = 0; i < 10; i++) {
    for (long long j = 1; j < MAXN; j++) {
      long long a = j;
      long long largestdigit = max(i, a % 10);
      while ((a /= 10) > 0) {
        largestdigit = max(largestdigit, a % 10);
      }
      if (j - largestdigit >= 0) {
        dp[i][j] = dp[i][j - largestdigit] + 1;
        dp2[i][j] = dp[i][j - largestdigit];
      } else {
        dp[i][j] = 1;
        dp2[i][j] = j - largestdigit;
      }
    }
  }
  long long n;
  cin >> n;
  long long b1 = n / MAXN;
  long long b2 = n % MAXN;
  while (b1 >= 0) {
    long long a = b1;
    long long largestdigit = a % 10;
    while ((a /= 10) > 0) {
      largestdigit = max(largestdigit, a % 10);
    }
    ans += dp[largestdigit][b2];
    if (dp2[largestdigit][b2] == 0 && b1 > 0) {
      b2 = MAXN - largestdigit;
      ans++;
    } else {
      b2 = MAXN + dp2[largestdigit][b2];
    }
    b1--;
  }
  cout << ans << endl;
}
