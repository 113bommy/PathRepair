#include <bits/stdc++.h>
using namespace std;
long long int h[1000050], us[1300005];
long long int h2[1000050], us2[1030005];
long long int n, m, i, arr[1000005];
long long int dp[2000005];
long long int ok[2000005], a = 1;
string str;
int main() {
  cin >> n >> m;
  cin >> str;
  long long int x = 0, y = 0;
  for (i = 0; i < str.size(); i++) {
    x = (26 * x + str[i] - 'a' + 1) % 333345987652299LL;
    y = ((a * (str[str.size() - i - 1] - 'a' + 1)) + y) % 333345987652299LL;
    a = a * 27 % 333345987652299LL;
    assert(x > 0 and y > 0);
    if (x == y) ok[i] = 1;
  }
  for (i = 1; i <= m; i++) {
    cin >> arr[i];
    if (i != 1) {
      if (!(arr[i - 1] + str.size() - 1 < arr[i]) and
          !ok[arr[i - 1] + str.size() - arr[i] - 1]) {
        cout << 0 << '\n';
        return 0;
      }
    }
    dp[arr[i]]++;
    dp[arr[i] + str.size()]--;
  }
  long long int s = 0;
  for (i = 1; i <= n; i++) {
    dp[i] += dp[i - 1];
    if (!dp[i]) s++;
  }
  long long int ans = 1;
  for (i = 1; i <= s; i++) ans = (ans * 26) % 1000000007;
  cout << ans << '\n';
}
