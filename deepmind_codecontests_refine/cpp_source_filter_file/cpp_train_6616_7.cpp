#include <bits/stdc++.h>
using namespace std;
const int MXN = 3e3 + 9;
int N;
int A[MXN];
vector<int> B;
int dp[MXN][MXN];
int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
    A[i] = A[i] - i;
    B.push_back(A[i]);
  }
  sort(B.begin(), B.end());
  B.resize(unique(B.begin(), B.end()) - B.begin());
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < (int)B.size(); ++j) {
      dp[i][j] = dp[i - 1][j] + abs(A[i] - B[j]);
      if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
    }
  }
  cout << dp[N][(int)B.size() - 1] << "\n";
  return 0;
}
