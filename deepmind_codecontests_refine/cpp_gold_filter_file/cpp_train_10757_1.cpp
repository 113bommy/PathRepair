#include <bits/stdc++.h>
using namespace std;
int N, K;
long long int good, bad, dp[2][2];
char A[2005], B[2005];
bool cur = 0, pre = 1, starting;
int main() {
  scanf(" %s %s %d", A, B, &K);
  N = strlen(A);
  for (int i = 0; i < N; ++i) {
    bool flag = 1;
    for (int j = 0; j < N; ++j)
      if (A[j] != B[(i + j) % N]) {
        flag = 0;
        break;
      }
    if (flag) ++good;
    if (flag && i == 0) starting = 1;
  }
  bad = (long long int)(N)-good;
  dp[cur][starting] = 1;
  for (int i = 0; i < K; ++i) {
    pre = !pre;
    cur = !cur;
    dp[cur][1] = (dp[pre][1] * (good - 1ll) + dp[pre][0] * good) % 1000000007;
    dp[cur][0] = (dp[pre][0] * (bad - 1ll) + dp[pre][1] * bad) % 1000000007;
  }
  cout << dp[cur][1] << endl;
}
