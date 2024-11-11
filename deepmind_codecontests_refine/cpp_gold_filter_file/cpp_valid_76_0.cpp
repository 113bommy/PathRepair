#include <bits/stdc++.h>
using namespace std;
long long n, m;
inline void add_self(long long &a, long long b) {
  a += b;
  if (a > m) a -= m;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<long long> dp(n + 1);
  dp[n] = 1;
  long long curr = 0;
  for (long long i = n; i > 1; i--) {
    add_self(dp[i], curr);
    add_self(curr, dp[i]);
    long long sq = sqrt(i);
    long long sqm = sq;
    if (i / sq == sq) sqm--;
    for (long long j = 2; j <= sq; j++) {
      add_self(dp[i / j], dp[i]);
    }
    for (long long j = sqm; j >= 1; j--) {
      add_self(dp[j], (((i / j) - (i / (j + 1))) * dp[i]) % m);
    }
  }
  cout << (dp[1] + curr) % m << '\n';
}
