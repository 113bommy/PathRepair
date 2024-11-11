#include <bits/stdc++.h>
using namespace std;
long long count(const string& s) {
  int n = s.size();
  vector<long long> dp(n + 1);
  dp[0] = 1;
  array<int, 26> now_ends;
  for (int i = 0; i < 26; i++) now_ends[i] = 0;
  for (int i = 0; i < n; i++) {
    dp[i + 1] = ((((2 * dp[i] - now_ends[s[i] - 'a']) % (1000000007ll)) +
                  (1000000007ll)) %
                 (1000000007ll));
    now_ends[s[i] - 'a'] =
        ((((now_ends[s[i] - 'a'] + dp[i + 1] - dp[i]) % (1000000007ll)) +
          (1000000007ll)) %
         (1000000007ll));
  }
  return dp[n];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int m = s.size();
  array<int, 26> last;
  for (int i = 0; i < 26; i++) last[i] = 0;
  for (int i = 0; i < m; i++) last[s[i] - 'a'] = i + 1;
  for (int i = 0; i < n; i++) {
    int mn = 0;
    for (int j = 1; j < k; j++) {
      if (last[j] < last[mn]) mn = j;
    }
    s.push_back('a' + mn);
    last[s[m + i] - 'a'] = m + i + 1;
  }
  cout << count(s) << endl;
  return 0;
}
