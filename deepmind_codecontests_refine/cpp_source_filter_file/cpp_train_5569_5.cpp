#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 52;
int n;
long long k;
long long dp[maxn];
int ans[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  for (int i = 1; i <= n;) {
    if (dp[n - i] >= k) {
      ans[i] = i;
      i++;
    } else {
      ans[i] = i + 1;
      ans[i + 1] = i;
      k -= dp[i];
      i += 2;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
