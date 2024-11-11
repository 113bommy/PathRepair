#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int rev = 0;
  cin >> n;
  vector<int> V(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> V[i];
    for (size_t j = 0; j < i; ++j) {
      if (V[i] < V[j]) {
        rev++;
      }
    }
  }
  int dp[max(rev + 1, 3)];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 4;
  for (size_t i = 3; i < rev + 1; ++i) {
    dp[i] = (4 + dp[i - 2]);
  }
  cout << dp[rev] << endl;
  return 0;
}
