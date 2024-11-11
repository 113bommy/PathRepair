#include <bits/stdc++.h>
using namespace std;
const int maxn = 8001;
const int inf = 1e9;
int pf[maxn + 1][maxn + 1];
int dp[maxn + 1];
string s;
int log10(int n) {
  int ans = 0;
  while (n) {
    n /= 10;
    ans++;
  }
  return ans;
}
void pi(int i) {
  pf[i][0] = 0;
  int sz = s.size();
  for (int k = 1 + i; k < s.size(); k++) {
    int j = pf[i][k - 1 - i];
    while (s[k] != s[j + i] and j > 0) {
      j = pf[i][j - 1];
    }
    if (s[k] == s[j + i]) j++;
    pf[i][k - i] = j;
  }
}
void pref() {
  for (int i = 0; i < s.size(); i++) {
    pi(i);
  }
}
int main() {
  cin >> s;
  pref();
  for (int i = 0; i <= maxn; i++) {
    dp[i] = inf;
  }
  dp[0] = 0;
  int n = s.size();
  for (int i = 1; i <= n; i++) {
    dp[i] = i + 1;
    for (int j = i - 1; j > 0; j--) {
      int period = i - j + 1;
      if (pf[j - 1][i - j] != 0 and period % (period - pf[j - 1][i - j]) == 0) {
        period -= pf[j - 1][i - j];
      }
      dp[i] = min(dp[i], period + log10((i - j + 1) / period) + dp[j - 1]);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
