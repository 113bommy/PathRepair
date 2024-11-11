#include <bits/stdc++.h>
using namespace std;
template <class _>
void chkmin(_ &a, _ b) {
  if (a > b) a = b;
}
template <class _>
void Add(_ &a, _ b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
int n;
long long ans;
long long A[1000005];
long long B[1000005];
long long H[1000005];
long long dp[1000005][2];
int main() {
  scanf("%d", &n);
  for (int i = (1), i_end_ = (n); i <= i_end_; i++) scanf("%lld", &H[i]);
  H[0] = H[n + 1] = 2e9;
  ;
  for (int i = (1), i_end_ = (n); i <= i_end_; i++) {
    B[i] = A[i] = H[i];
    chkmin(A[i], H[i - 1]);
    chkmin(A[i], H[i + 1]);
    chkmin(B[i], H[i + 1]);
  }
  for (int i = (1), i_end_ = (n); i <= i_end_; i++) {
    Add(dp[i][0], dp[i - 1][0] * (A[i] - 1) % 1000000007);
    Add(dp[i][0], dp[i - 1][1] * (A[i] - 1) % 1000000007);
    dp[i][1] = B[i] - 1;
    Add(ans, H[i] - 1);
    Add(ans, dp[i - 1][0] * (B[i - 1] - 1) % 1000000007);
    Add(ans, dp[i - 1][1] * (B[i - 1] - 1) % 1000000007);
  }
  printf("%lld\n", ans);
  return 0;
}
