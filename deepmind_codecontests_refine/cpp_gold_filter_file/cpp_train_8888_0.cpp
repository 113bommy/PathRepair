#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[n][2];
  map<long long, long long> m;
  for (long long i = 0; i < (n); ++i) {
    cin >> a[i][0] >> a[i][1];
    m[a[i][0]] = a[i][1];
  }
  long long cnt = 0;
  for (long long j = 0; j < n; j++) {
    for (long long k = 0; k < n; k++) {
      if ((k != j) && (a[j][0] == a[k][1])) {
        cnt++;
        break;
      }
    }
  }
  cout << n - cnt;
}
