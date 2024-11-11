#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const long long MOD = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> dp(n);
  dp[n - 1] = 1;
  set<int> s;
  s.insert(v[n - 1]);
  for (int i = n - 2; i >= 0; i--) {
    if (!s.count(v[i]))
      dp[i] = dp[i + 1] + 1;
    else
      dp[i] = dp[i + 1];
    s.insert(v[i]);
  }
  set<int> s1;
  long long res = 0;
  for (int i = 0; i < n - 1; i++) {
    if (!s1.count(v[i])) {
      res += dp[i + 1];
    }
    s1.insert(v[i]);
  }
  cout << res << endl;
}
