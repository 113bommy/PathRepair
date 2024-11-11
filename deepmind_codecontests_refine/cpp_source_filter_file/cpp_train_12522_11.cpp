#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int INF = int(1e9) + 5;
const int MOD = int(1e9) + 7;
const int64_t INF64 = int64_t(1e15) + 5;
void run_case() {
  int N, M;
  string A, B;
  cin >> N >> M >> A >> B;
  vector<vector<int>> dp(N + 1, vector<int>(M + 1));
  int ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      if (A[i] == B[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 2;
      } else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]) - 1;
      }
      ans = max(ans, dp[i + 1][j + 1]);
    }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests = 1;
  while (tests-- > 0) {
    run_case();
  }
  return 0;
}
