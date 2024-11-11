#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const long long mod = 1000000007;
const long long maxn = 100005;
int fix[maxn];
int ans[maxn];
long long dp[maxn];
long long pre[maxn];
void lps(string pat) {
  int len = pat.size();
  memset(fix, 0, sizeof(fix));
  fix[0] = 0;
  fix[1] = 0;
  int j = 0;
  for (int i = 2; i <= len; ++i) {
    if (pat[i - 1] == pat[j]) {
      j++;
      fix[i] = j;
    } else if (!j) {
      fix[i] = 0;
    } else {
      while (j) {
        j = fix[j];
        if (pat[j] == pat[i - 1]) {
          j++;
          fix[i] = j;
          break;
        }
      }
    }
  }
}
void kmp(string s, string pat) {
  lps(pat);
  int len = s.size();
  int m = pat.size();
  int j = 0;
  for (int i = 0; i < len; ++i) {
    if (pat[j] == s[i]) {
      j++;
      if (j == m) {
        ans[i] = 1;
        j = fix[j];
      }
    } else {
      if (j) {
        j = fix[j];
        i--;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, pat;
  while (cin >> s >> pat) {
    memset(ans, 0, sizeof(ans));
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    kmp(s, pat);
    long long len = s.size();
    long long m = pat.size();
    dp[0] = 0;
    pre[0] = 0;
    for (int i = 1; i <= len; ++i) {
      if (i > 1 && !ans[i - 1]) {
        dp[i] = (dp[i - 1] << 1) - dp[i - 2];
      }
      if (ans[i - 1]) {
        dp[i] += pre[i - m] + (i - m + 1) + dp[i - 1];
      }
      dp[i] %= mod;
      pre[i] = (pre[i - 1] + dp[i]) % mod;
    }
    cout << dp[len] << "\n";
  }
  return 0;
}
