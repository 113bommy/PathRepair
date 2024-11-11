#include <bits/stdc++.h>
using namespace std;
vector<long> v, vv;
set<long> s;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long n;
  cin >> n;
  long a[n];
  long maxi = -19;
  for (long i = 0; i < n; i++) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
  }
  long cnt = 1;
  long ans = -19;
  for (long i = 1; i < n; i++) {
    if (a[i] == a[i - 1] && a[i] == maxi) {
      cnt++;
      ans = max(cnt, ans);
    } else {
      cnt = 1;
    }
  }
  cout << ans;
  return 0;
}
