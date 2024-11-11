#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> L(n + 1, 1e9), R(n + 1, -1e9);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    L[A[i]] = min(L[A[i]], i);
    R[A[i]] = max(R[A[i]], i);
  }
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  n = A.size();
  vector<int> dp(n + 1, 1);
  dp[0] = 1;
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    if (L[A[i]] > R[A[i - 1]]) {
      dp[i] = max(dp[i], dp[i - 1] + 1);
    }
    ans = max(ans, dp[i]);
  }
  cout << n - ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
