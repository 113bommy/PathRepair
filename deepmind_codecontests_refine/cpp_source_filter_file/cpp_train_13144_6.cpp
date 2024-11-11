#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0, b = getchar(), c = 1;
  while (!isdigit(b)) c = b == '-' ? -1 : 1, b = getchar();
  while (isdigit(b)) a = a * 10 + b - '0', b = getchar();
  return a * c;
}
int T, n, sum, ans, a[100005], dp[1100005];
string s;
int main() {
  T = read();
  while (T--) {
    n = read();
    ans = sum = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) a[i] = s[i] - '0';
    for (int i = 0; i < n; i++) sum += a[i];
    for (int i = 0; i <= sum + n + 1; i++) dp[i] = 0;
    sum = n + 1, dp[n + 1] = 1;
    for (int i = 0; i < n; i++) {
      sum += a[i] - 1;
      ans += dp[sum];
      dp[sum]++;
    }
    cout << ans << endl;
  }
  return 0;
}
