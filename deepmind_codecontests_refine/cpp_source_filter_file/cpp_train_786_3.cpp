#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
const int INF = 2147483647;
int N, V;
vector<pair<int, int> > A, B;
int longest_increasing_subsequence(vector<pair<int, int> > &A,
                                   bool second_case = false) {
  int dp[MAXN];
  for (int i = 1; i <= N; i++) dp[i] = INF;
  dp[0] = -INF;
  for (int i = 0; i < A.size(); i++) {
    int j = int(upper_bound(dp, dp + N + 1, A[i].second) - dp);
    if (second_case && (A[i].first < 0 || A[i].second < 0)) continue;
    if (dp[j - 1] <= A[i].second && A[i].second <= dp[j]) dp[j] = A[i].second;
  }
  int q = 0;
  for (int i = 0; i <= N; i++)
    if (dp[i] != INF) q = i;
  return q;
}
int main() {
  cin >> N;
  A.resize(N);
  B.resize(N);
  for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
  cin >> V;
  for (int i = 0; i < N; i++)
    B[i].first = -A[i].first + A[i].second * V,
    B[i].second = A[i].first + A[i].second * V;
  sort(B.begin(), B.end());
  int ans1 = longest_increasing_subsequence(B);
  int ans2 = longest_increasing_subsequence(B, 1);
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
