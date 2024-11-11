#include <bits/stdc++.h>
using namespace std;
const long long N = 105;
long long n, m, k, tot = 0;
char a[N][N];
long long ans[N][N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    tot = 0;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        if (a[i][j] == 'R') tot++;
      }
    }
    long long reqd = tot / k;
    long long extra = tot % k;
    long long cur = 0;
    long long keep = 0;
    for (long long i = 1; i <= n; i++) {
      if (i % 2 == 0) {
        long long j = 1;
        while (j <= m) {
          cur += (a[i][j] == 'R');
          ans[i][j] = keep;
          if (cur == reqd + (extra > 0)) {
            keep++;
            extra--;
            cur = 0;
            keep = min(keep, k);
          }
          j++;
        }
      } else {
        long long j = m;
        while (j >= 1) {
          cur += (a[i][j] == 'R');
          ans[i][j] = keep;
          if (cur == reqd + (extra > 0)) {
            keep++;
            extra--;
            cur = 0;
            keep = min(keep, k);
          }
          j--;
        }
      }
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        if (ans[i][j] <= 25)
          cout << (char)('a' + ans[i][j]);
        else if (ans[i][j] <= 51)
          cout << (char)('A' + ans[i][j] - 26);
        else
          cout << (char)('0' + ans[i][j] - 52);
      }
      cout << "\n";
    }
  }
  return 0;
}
