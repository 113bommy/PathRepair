#include <bits/stdc++.h>
using namespace std;
const int sz = 1e6 + 1;
int dp[sz];
void solve() {
  for (long long i = 2; i < sz; i++) {
    if (dp[i]) {
      for (long long j = i + i; j < sz; j += i) {
        if (dp[j]) {
          dp[j] = max(dp[j], dp[i] + 1);
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    dp[x] = 1;
  }
  solve();
  int maxi = 0;
  for (int i = 0; i < sz; i++) {
    maxi = max(maxi, dp[i]);
  }
  cout << maxi << "\n";
  return 0;
}
