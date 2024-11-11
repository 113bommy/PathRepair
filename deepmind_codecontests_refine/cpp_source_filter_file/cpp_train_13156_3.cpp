#include <bits/stdc++.h>
using namespace std;
long long dp[200005][2];
bool vst[200005][2];
long long A[200005], n;
long long go(long long v, bool b) {
  if (vst[v][b]) return dp[v][b];
  vst[v][b] = true;
  long long val = 0;
  if (!b) {
    if ((v - A[v]) > 1)
      val = go(v - A[v], b ^ 1);
    else if ((v - A[v]) == 1)
      val = -1;
  } else {
    if ((v + A[v]) < n) val = go(v + A[v], b ^ 1);
  }
  if (val != -1)
    dp[v][b] = A[v] + val;
  else
    dp[v][b] = -1;
  return dp[v][b];
}
int main() {
  long long i;
  cin >> n;
  for (i = (2); i <= (n); i++) {
    cin >> A[i];
  }
  memset((vst), (0), sizeof(vst));
  long long j;
  memset((dp), (-1), sizeof(dp));
  for (i = (2); i <= (n); i++) {
    go(i, 0);
    if (dp[i][0] != -1)
      cout << dp[i][0] + i - 1 << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
