#include <bits/stdc++.h>
using namespace std;
long long dp[27], num[27], n, kq = 26;
string s;
long long tpm(int x) {
  memset(num, 0, sizeof(num));
  long long ans = 0, sum = 0;
  for (int l = 1, r = 1; r <= n; r++) {
    int c = s[r] - 'a';
    if (num[c] == 0) sum++;
    num[c]++;
    while (sum > x) {
      int t = s[l] - 'a';
      num[t]--;
      if (num[t] == 0) sum--;
      l++;
    }
    ans += 1ll * (r - l + 1);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  n = s.size();
  s = ' ' + s;
  for (int i = 1; i <= 26; i++) dp[i] = tpm(i);
  for (int i = 2; i <= 26; i++)
    if (dp[i] == dp[i - 1]) {
      kq = i - 1;
      break;
    }
  cout << kq << '\n';
  for (int i = 1; i <= kq; i++) cout << dp[i] - dp[i - 1] << '\n';
  return 0;
}
