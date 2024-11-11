#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n, last = 0;
    cin >> n;
    string second;
    cin >> second;
    long long cnt = 0, ans = 0;
    for (long long i = 0; i < second.size(); i++) {
      if (second[i] == 'A')
        last = i;
      else
        ans = max(ans, i - last);
    }
    cout << ans << '\n';
  }
  return 0;
}
