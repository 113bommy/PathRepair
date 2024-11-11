#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, k;
string s;
int last[27];
long long dp[2000005];
const long long mod = 1000000007;
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  cin >> n >> k >> s;
  memset(last, -1, sizeof(last));
  for (int i = 0; i < s.size(); i++) {
    last[s[i] - 'a'] = i;
  }
  for (int i = 0; i < n; i++) {
    int ch = 0;
    for (int j = 0; j < k; j++) {
      if (last[j] < last[ch]) {
        ch = j;
      }
    }
    last[ch] = i + s.size();
    s += ch + 'a';
  }
  dp[0] = 2;
  memset(last, -1, sizeof(last));
  last[s[0] - 'a'] = 0;
  for (int i = 1; i < s.size(); i++) {
    int call = last[s[i] - 'a'] - 1, v = 0;
    if (call == -1) {
      v = 1;
    } else {
      if (call < -1) {
        v = 0;
      } else {
        v = dp[call];
      }
    }
    dp[i] = (2 * dp[i - 1] - v) % mod;
    last[s[i] - 'a'] = i;
  }
  cout << dp[s.size() - 1] << endl;
  return 0;
}
