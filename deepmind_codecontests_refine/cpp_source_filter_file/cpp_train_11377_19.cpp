#include <bits/stdc++.h>
using namespace std;
long long int dp[500005];
long long int arr[500005];
long long int en[500005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  string w;
  cin >> w;
  vector<char> s;
  s.push_back('0');
  for (long long int i = 0; i < w.size(); i++) {
    s.push_back(w[i]);
  }
  s.push_back('0');
  for (long long int i = 1; i <= n; i++) {
    arr[i] = n + 1;
  }
  long long int ans = 0;
  for (long long int i = n; i >= 1; i--) {
    if (s[i] == '1') {
      en[i] = max(i, en[i + 1]);
    }
  }
  for (long long int i = n; i >= 1; i--) {
    if (s[i] == '1') {
      long long int l = en[i] - i + 1;
      ans += (l * (l + 1)) / 2;
      long long int w = arr[l + 1];
      ans += (w - en[i] - 1) * l;
      ans += dp[w];
    } else {
      if (s[i + 1] == '1') {
        for (long long int j = en[i + 1]; j >= i + 1; j--) {
          dp[j] = (j - i) * (arr[j - i + 1] - j) + dp[arr[j - i + 1]];
          arr[j - i] = j;
        }
      }
      ans += dp[arr[1]];
    }
  }
  cout << ans << "\n";
}
