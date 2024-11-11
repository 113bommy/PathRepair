#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
long long n, s, l, arr[100005], dp[100005], maxt[100005][25], mint[100005][25];
long long query(long long l, long long r) {
  long long p = log2(r - l + 1);
  return max(maxt[l][p], maxt[r - (1 << p) + 1][p]) -
         min(mint[l][p], mint[r - (1 << p) + 1][p]);
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> s >> l;
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
    maxt[i][0] = mint[i][0] = arr[i];
  }
  for (long long j = 1; j <= 20; j++)
    for (long long i = 1; i <= n; i++) {
      maxt[i][j] = max(maxt[i][j - 1], maxt[min(n, i + (1 << (j - 1)))][j - 1]);
      mint[i][j] = min(mint[i][j - 1], mint[min(n, i + (1 << (j - 1)))][j - 1]);
    }
  deque<long long> dq;
  dq.push_front(0);
  for (long long i = 1; i < l; i++) dp[i] = -1;
  for (long long i = l; i <= n; i++) {
    while (!dq.empty() && query(dq.back() + 1, i) > s) dq.pop_back();
    if (dq.empty() || i - dq.back() < l)
      dp[i] = -1;
    else {
      dp[i] = dp[dq.back()] + 1;
      dq.push_front(i);
    }
  }
  cout << dp[n] << '\n';
}
