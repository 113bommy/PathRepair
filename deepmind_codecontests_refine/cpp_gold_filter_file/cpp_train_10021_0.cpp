#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1e6, MOD = 1e9 + 7;
int n, dp[N_MAX], sum;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  n = s.length();
  int i = 0;
  while (i < n && s[i] == '0') i++;
  if (i == n) {
    cout << n << "\n";
    return 0;
  }
  int j = n - 1;
  while (s[j] == '0') j--;
  long long mult = i + 1;
  mult *= n - j;
  mult %= MOD;
  s = s.substr(i, j - i + 1);
  n = s.length();
  sum = 1;
  i = 0;
  while (i < n - 1) {
    int j = 0;
    while (i + j + 1 < n && s[i + j + 1] == '0') j++;
    int diff = 0;
    for (int k = 0; k <= j; k++) {
      diff += sum;
      if (diff >= MOD) diff -= MOD;
      diff += MOD - dp[k];
      if (diff >= MOD) diff -= MOD;
      dp[k] = sum;
    }
    sum += diff;
    if (sum >= MOD) sum -= MOD;
    i += j + 1;
  }
  cout << mult * sum % MOD << "\n";
  return 0;
}
