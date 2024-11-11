#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    pair<long long, long long> *val = new pair<long long, long long>[n + 1];
    for (long long i = 1; i <= n; i++) {
      long long req;
      cin >> req;
      val[i].first = req;
      val[i].second = i;
    }
    sort(val + 1, val + n + 1);
    long long ans = 1;
    long long cnt = 0;
    for (long long i = 1; i <= n; i++) {
      if ((ans + cnt) >= val[i].first) {
        if (cnt == 0) {
          ans += 1;
        } else {
          ans += cnt;
          ans += 1;
        }
        cnt = 0;
      } else {
        cnt++;
      }
    }
    cout << ans << endl;
  }
}
