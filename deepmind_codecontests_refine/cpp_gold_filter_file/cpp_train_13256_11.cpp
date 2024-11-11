#include <bits/stdc++.h>
using namespace std;
constexpr int S = 101;
constexpr int L = 3005;
constexpr long long MOD = 1000000007;
long long DP[L][S][S] = {0};
int A[S] = {0};
int B[S] = {0};
int n, l;
long long solve(const int l, const int w, const int t) {
  if (l == 0) return 1;
  if (l < 0) return 0;
  if (DP[l][w][t] != -1) return DP[l][w][t];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (i != t) {
      if (A[i] == w) {
        ans += solve(l - B[i], B[i], i) % MOD;
        ans %= MOD;
      }
      if (A[i] != B[i] && B[i] == w) {
        ans += solve(l - A[i], A[i], i) % MOD;
        ans %= MOD;
      }
    }
  }
  DP[l][w][t] = ans;
  return ans;
}
int main() {
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> B[i];
  }
  for (int i = 0; i < L; i++)
    for (int j = 0; j < S; j++)
      for (int k = 0; k < S; k++) DP[i][j][k] = -1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += solve(l - A[i], A[i], i);
    ans %= MOD;
    if (A[i] != B[i]) {
      ans += solve(l - B[i], B[i], i) % MOD;
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
