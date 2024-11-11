#include <bits/stdc++.h>
using namespace std;
int const N = 5e3 + 5;
int const NN = 26;
string S;
int n;
int dp[N][NN][NN], cnt[NN];
int main() {
  cin >> S;
  n = S.size();
  S = S + S;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < i + n; j++) {
      dp[S[i] - 'a'][j - i][S[j] - 'a']++;
    }
    cnt[S[i] - 'a']++;
  }
  double ans = 0;
  for (int p = 0; p < NN; p++) {
    double maxs = 0;
    for (int size = 0; size < n; size++) {
      int sum = 0;
      int cur = 0;
      for (int q = 0; q < NN; q++) sum += dp[p][size][q];
      for (int q = 0; q < NN; q++) {
        if (dp[p][size][q] == 1) {
          cur++;
        }
      }
      maxs = max(maxs, 1.0 * cur / sum);
    }
    ans += maxs / n * cnt[p];
  }
  printf("%0.13f\n", ans);
}
