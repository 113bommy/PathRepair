#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int MAXK = 1000;
const int MAXA = 1000;
int N, K;
int A[MAXN];
int dp[MAXN * MAXA + 1];
signed main() {
  ios::sync_with_stdio(0);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A + N);
  for (int i = 1; i < N; ++i) {
    A[i] -= A[0];
  }
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j + A[i] <= MAXN * MAXA; ++j) {
      dp[j + A[i]] = min(dp[j + A[i]], dp[j] + 1);
    }
  }
  for (int i = 0; i <= MAXN * MAXA; ++i) {
    if (dp[i] <= K) {
      cout << i + A[0] * K << " ";
    }
  }
  return 0;
}
