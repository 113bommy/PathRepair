#include <bits/stdc++.h>
using namespace std;
long long inf = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  {
    long long n, d, fm = 0;
    cin >> n >> d;
    pair<long long, long long> a[n];
    long long f[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    f[0] = a[0].second;
    for (long long i = 1; i < n; i++) {
      f[i] = f[i - 1] + a[i].second;
    }
    long long i = 0, j = 0;
    while (j < n) {
      while (a[j].first - a[i].first > d) {
        i++;
      }
      if (a[j].first - a[i].first <= d) {
        if (i != 0) {
          fm = max(fm, f[j] - f[i - 1]);
        } else {
          fm = max(fm, f[j]);
        }
        j++;
      }
    }
    cout << fm << endl;
  }
  return 0;
}
