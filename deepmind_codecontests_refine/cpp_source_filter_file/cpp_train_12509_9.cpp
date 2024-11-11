#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t launch = clock();
  long long t = 1;
  while (t--) {
    long long n, v, dp[6] = {0};
    cin >> n;
    map<long long, long long> m;
    m[4] = 1;
    m[8] = 2;
    m[15] = 3;
    m[16] = 4;
    m[23] = 5;
    m[42] = 6;
    for (long long i = 0; i < n; i++) {
      cin >> v;
      v = m[v];
      if (v == 1)
        dp[v]++;
      else
        dp[v] = min(dp[v - 1], dp[v] + 1);
    }
    cout << n - (6 * dp[6]) << endl;
  }
  clog << ((long double)(clock() - launch) / CLOCKS_PER_SEC) << "\n";
  return 0;
}
