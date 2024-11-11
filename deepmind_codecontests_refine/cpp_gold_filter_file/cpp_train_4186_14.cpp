#include <bits/stdc++.h>
using namespace std;
long long t, n;
string s;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  for (int q = 0; q < t; q++) {
    cin >> n >> s;
    s = "#" + s;
    long long l = 1000000000, r = -1000000000;
    for (long long i = 1; i <= n; i++) {
      if (s[i] == '1') {
        l = min(l, i);
        r = max(r, i);
      }
    }
    if (l >= 1000000000) {
      cout << n << "\n";
      continue;
    }
    long long ans = max(2 * r, 2 * (n - l + 1));
    cout << ans << "\n";
  }
  flush(cout);
  return 0;
}
