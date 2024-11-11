#include <bits/stdc++.h>
using namespace std;
long long arr[5111], f[5111], l[5111];
bool hass[5111];
long long arrans[5111];
long long dp[5111];
long long lst[5111];
int main() {
  std::ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
    if (f[arr[i]] == 0) f[arr[i]] = i;
    l[arr[i]] = i;
  }
  long long finans = 0;
  for (long long i = 1; i <= n; i++) {
    long long st = arr[i];
    long long firstocc = f[st];
    long long lastocc = l[st];
    lst[i] = lastocc;
    if (firstocc < i) continue;
    long long s = i;
    memset(hass, 0, sizeof(hass));
    long long curxor = 0;
    bool flag = 1;
    for (long long j = s; j <= lastocc; j++) {
      if (f[arr[j]] < i) {
        flag = 0;
        break;
      }
      lastocc = max(lastocc, l[arr[j]]);
      if (hass[arr[j]] == 0) curxor = curxor ^ arr[j];
      hass[arr[j]] = 1;
    }
    if (flag) arrans[i] = curxor;
    lst[i] = lastocc;
  }
  for (long long i = n; i >= 1; i--) {
    dp[i] = dp[i + 1];
    if (f[arr[i]] == i) dp[i] = max(dp[i], dp[lst[i] + 1] + arrans[i]);
  }
  cout << dp[1] << endl;
  return 0;
}
