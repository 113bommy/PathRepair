#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int A[n];
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  int dp[n], Ans[n];
  if (n == 1) {
    cout << "0\n" << A[0];
    return 0;
  }
  bool f;
  int till = INT_MAX, curr;
  for (int i = A[0]; i <= A[0]; ++i) {
    dp[0] = i;
    curr = i - A[0];
    for (int j = 1; j < n; ++j) {
      dp[j] = max(A[j], k - dp[j - 1]);
      curr += dp[j] - A[j];
    }
    if (curr < till) {
      for (int j = 0; j < n; ++j) {
        Ans[j] = dp[j];
      }
      till = curr;
    }
  }
  if (till != INT_MAX) {
    cout << till << "\n";
    for (int i = 0; i < n; ++i) {
      cout << Ans[i] << " ";
    }
  } else {
    cout << "0\n";
    for (int i = 0; i < n; ++i) {
      cout << A[i] << " ";
    }
  }
  return 0;
}
