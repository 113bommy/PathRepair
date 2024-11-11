#include <bits/stdc++.h>
using namespace std;
int dp[256];
int str[256];
int last[256];
const int mod = 1e9 + 7;
bool cmp(int a, int b) { return last[a] < last[b]; }
int main(void) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0;
  int cnt = 0;
  for (auto it : s) {
    ans = (ans + mod - dp[it - 'a' + 1]) % mod;
    dp[it - 'a' + 1] = (dp[it - 'a' + 1] + ans + 1) % mod;
    ans = (ans + dp[it - 'a' + 1]) % mod;
    last[it - 'a' + 1] = ++cnt;
  }
  for (int i = 1; i <= k; ++i) str[i] = i;
  sort(str + 1, str + 1 + k, cmp);
  for (int i = 1; i <= n; ++i) {
    char it = i == k ? str[n] : str[i % k];
    ans = (ans + mod - dp[it]) % mod;
    dp[it] = (dp[it] + ans + 1) % mod;
    ans = (ans + dp[it]) % mod;
  }
  return cout << (ans + 1) % mod << '\n', 0;
}
