#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)(1e9 + 7);
const long long INF = (long long)(1e9 + 10);
const int MAXN = (int)(2e5 + 5);
const int MAX_VAL = (int)(1e6 + 10);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> dp(8000005, -1);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = (0); i < (int)(n); i++)
    cin >> v[i], dp[v[i] ^ ((1 << 22) - 1)] = v[i];
  for (int i = 8000004; i >= 1; i--) {
    if (dp[i] == -1) continue;
    for (int j = 1; j < i; j *= 2) {
      if ((i & j)) dp[i ^ j] = dp[i];
    }
  }
  for (int i = (0); i < (int)(n); i++) cout << dp[v[i]] << " ";
  cout << "\n";
  return 0;
}
