#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int maxlen = 1e5;
vector<int> A;
int dp[maxlen + 10];
int main() {
  int i, j, n;
  scanf("%d", &n);
  int l, r;
  l = r = 0;
  A.resize(n);
  for (i = 0; i < n; ++i) scanf("%d", &A[i]);
  memset(dp, -1, sizeof(dp));
  for (i = 0; i < A.size(); ++i)
    if (dp[A[i] - 1] != -1)
      dp[A[i]] = dp[A[i] - 1] + 1;
    else
      dp[A[i]] = 1;
  int mx = 0;
  for (i = 1; i <= n; ++i) mx = max(mx, dp[i]);
  printf("%d", n - mx);
  return 0;
}
