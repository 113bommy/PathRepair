#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long int INFF = 1e17;
const double EPS = 1e-9;
const long long int MOD = 1e9 + 7;
int main() {
  long long int n, ways = 0;
  string s;
  scanf("%lld", &n);
  ;
  cin >> s;
  long long int lim[26];
  long long int dp[1010];
  long long int ans = 0, no = 0, len = 0;
  for (int i = 0; i < 26; i++) scanf("%d", &lim[i]);
  ;
  for (int i = 0; i < n; i++) {
    dp[i] = 0;
  }
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    int arr[26];
    for (int j = 0; j < 26; j++) arr[j] = 0;
    len = 1;
    arr[s[i] - 'a'] = 1;
    int flag = 0;
    ans = max((long long int)len, ans);
    for (int j = i - 1; j >= 0; j--) {
      dp[i] += dp[j];
      len++;
      arr[s[j] - 'a'] = 1;
      flag = 0;
      for (int k = 0; k < 26; k++) {
        if (len > lim[k] && arr[k] == 1) flag = 1;
      }
      if (flag) break;
      ans = max((long long int)len, ans);
    }
    for (int k = 0; k < 26; k++) {
      if (len > lim[k] && arr[k] == 1) flag = 1;
    }
    if (!flag) dp[i]++;
    dp[i] = dp[i] % MOD;
  }
  len = 0;
  printf("%lld\n", dp[n - 1]);
  ;
  printf("%lld\n", ans);
  ;
  int arr[26];
  for (int j = 0; j < 26; j++) arr[j] = 0;
  for (int i = 0; i < n; i++) {
    len++;
    arr[s[i] - 'a'] = 1;
    int flag = 0;
    for (int k = 0; k < 26; k++) {
      if (len > lim[k] && arr[k] == 1) flag = 1;
    }
    if (flag) {
      for (int j = 0; j < 26; j++) arr[j] = 0;
      len = 1;
      arr[s[i] - 'a'] = 1;
      no++;
    }
  }
  no++;
  printf("%lld\n", no);
  ;
  return 0;
}
