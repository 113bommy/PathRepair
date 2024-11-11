#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1);
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int a[MAX];
int dp[MAX][2];
int main() {
  int n;
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    int x;
    cin >> x;
    if (x < 0)
      a[i] = -1;
    else
      a[i] = 1;
  }
  dp[1][0] = (a[1] == 1);
  dp[1][1] = 1 - dp[1][0];
  int sum1 = 0, sum2 = 0;
  for (int i = (2); i <= (n); ++i) {
    if (a[i] == 1) {
      dp[i][0] = 1 + dp[i - 1][0];
      dp[i][1] = dp[i - 1][1];
    } else {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = 1 + dp[i - 1][0];
    }
    sum1 += dp[i][0];
    sum2 += dp[i][1];
  }
  cout << sum2 + dp[1][1] << ' ' << sum1 + dp[1][0] << '\n';
}
