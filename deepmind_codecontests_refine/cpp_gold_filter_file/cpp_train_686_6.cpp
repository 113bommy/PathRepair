#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6, N2 = 5e3 + 10, mod = 1e9 + 7, inf = 1e10;
const long double PI = 3.1415926535897932;
long long int a[N], dp[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < m; i++) cin >> dp[i];
  sort(a, a + n);
  sort(dp, dp + m);
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (a[i] == dp[j]) return cout << (a[i]), 0;
    }
  }
  cout << min(a[0], dp[0]) << max(a[0], dp[0]);
}
