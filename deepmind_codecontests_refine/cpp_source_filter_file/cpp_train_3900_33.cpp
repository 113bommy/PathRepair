#include <bits/stdc++.h>
using namespace std;
const long long N = 2005;
long long d1[2 * N];
long long d2[2 * N];
long long n;
long long a[N][N];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      cin >> a[i][j];
      d1[i + j] += a[i][j];
      d2[i - j + n] += a[i][j];
    }
  }
  long long sum1 = 0, sum2 = 0;
  pair<long long, long long> p1, p2;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if ((i + j) % 2) {
        long long y = d1[i + j] + d2[i - j + n] - a[i][j];
        if (y > sum1) {
          p1.first = i;
          p1.second = j;
          sum1 = y;
        }
      } else {
        long long y = d1[i + j] + d2[i - j + n] - a[i][j];
        if (y > sum2) {
          p2.first = i;
          p2.second = j;
          sum2 = y;
        }
      }
    }
  }
  cout << (sum1 + sum2) << "\n";
  cout << p1.first << " " << p1.second << "\n";
  cout << p2.first << " " << p2.second << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  t = 1;
  while (t--) solve();
  return 0;
}
