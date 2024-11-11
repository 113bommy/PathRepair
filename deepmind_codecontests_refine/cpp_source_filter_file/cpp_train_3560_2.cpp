#include <bits/stdc++.h>
using namespace std;
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j;
  long long n, c;
  cin >> n >> c;
  long long a[n];
  long long b[n];
  for (i = 1; i < n; i++) cin >> a[i];
  for (i = 1; i < n; i++) cin >> b[i];
  long long dp1[n];
  long long dp2[n];
  dp1[0] = 0;
  dp1[0] = c;
  for (i = 1; i < n; i++) {
    dp1[i] = min(dp1[i - 1], dp2[i - 1] + c) + b[i];
    dp2[i] = min(dp2[i - 1], dp1[i - 1]) + a[i];
  }
  for (i = 0; i < n; i++) cout << min(dp1[i], dp2[i]) << " ";
  cout << "\n";
  return 0;
}
