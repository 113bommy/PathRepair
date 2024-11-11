#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 5;
const long long p = 1000000009;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[n][m];
  for (long long i = (0); i < (n); i++)
    for (long long j = (0); j < (m); j++) cin >> a[i][j];
  long long x, y;
  cin >> x >> y;
  long long mini = INT_MAX;
  for (long long i = 0; i <= (n - x); i++) {
    for (long long j = 0; j <= (m - y); j++) {
      long long cnt = 0, cn = 0;
      for (long long m = i; m < i + x; m++) {
        for (long long l = j; l < j + y; l++) {
          if (a[m][l] == 1) cnt++;
          cn++;
        }
      }
      mini = min(cnt, mini);
    }
  }
  for (long long i = 0; i <= (n - y); i++) {
    for (long long j = 0; j <= (m - x); j++) {
      long long cnt = 0, cn = 0;
      for (long long m = i; m < i + y; m++) {
        for (long long l = j; l < j + x; l++) {
          if (a[m][l] == 1) cnt++;
          cn++;
        }
      }
      mini = min(cnt, mini);
    }
  }
  cout << mini;
}
int32_t main() { solve(); }
