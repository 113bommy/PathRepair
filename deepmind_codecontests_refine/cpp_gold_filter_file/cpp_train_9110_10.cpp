#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s, d, i;
  cin >> n >> m >> s >> d;
  int A[n + 1], last;
  A[0] = -1;
  for (i = 1; i <= n; i++) cin >> A[i];
  sort(A, A + n + 1);
  int dp[n + 1];
  dp[n] = n;
  last = n;
  for (i = n - 1; i >= 0; i--) {
    dp[i] = -1;
    if (A[i + 1] - A[i] >= s + 2 && A[last] + 2 - A[i + 1] <= d)
      dp[i] = last, last = i;
  }
  if (dp[0] == -1) return !printf("IMPOSSIBLE\n");
  last = 0;
  while (last != n) {
    cout << "RUN " << A[last + 1] - A[last] - 2 << endl;
    cout << "JUMP " << A[dp[last]] + 2 - A[last + 1] << endl;
    last = dp[last];
  }
  if (m - A[last] - 1) cout << "RUN " << m - A[last] - 1 << endl;
  return 0;
}
