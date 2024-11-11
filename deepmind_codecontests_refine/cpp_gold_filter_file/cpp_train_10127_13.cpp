#include <bits/stdc++.h>
using namespace std;
const long long LINF = (long long)1e18 + 47;
const int INF = (int)1e9 + 47;
const int MOD = (int)1e9 + 7;
const int modulo = 998244353;
const int nax = 3 * (int)1e5 + 10;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAX = 300 + 7;
void upRating() {}
long long dp[nax][2];
int a[nax];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  upRating();
  int tt;
  cin >> tt;
  for (int test = (0); test < (tt); test++) {
    int n, q;
    cin >> n >> q;
    for (int i = (0); i < (n); i++) cin >> a[i];
    dp[0][0] = a[0];
    dp[0][1] = 0;
    for (int i = (1); i < (n); i++) {
      dp[i][0] = max({dp[i - 1][1] + a[i], dp[i - 1][0]});
      dp[i][1] = max({dp[i - 1][0] - a[i], dp[i - 1][1]});
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
  }
}
