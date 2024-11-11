#include <bits/stdc++.h>
using namespace std;
long long rr[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long cc[] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long mod = 1e9 + 7;
const long long N = 5005;
long long temp[N][N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long test = 1;
  while (test--) {
    long long n, m;
    cin >> n >> m;
    long long a[n + 1][m + 1];
    string s[n];
    for (long long i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        a[i + 1][j + 1] = s[i][j] - '0';
      }
    }
    long long ans = 0;
    vector<long long> x(n + 1);
    for (long long j = 1; j <= m; j++) {
      for (long long i = 0; i <= n; i++) {
        x[i] = 0;
      }
      for (long long i = 1; i <= n; i++) {
        temp[i][j] = (a[i][j] ? temp[i][j - 1] + 1 : 0);
        x[temp[i][j]]++;
      }
      for (long long i = n - 1; i >= 0; i--) {
        x[i] += x[i + 1];
      }
      for (long long i = 0; i <= n; i++) {
        ans = max(ans, x[i] * i);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
