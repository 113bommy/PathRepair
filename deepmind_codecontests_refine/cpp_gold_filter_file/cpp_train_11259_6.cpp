#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, t, mx = 200001, ans = 0;
  cin >> n >> t;
  long long s[n], d[n];
  for (long long i = 0; i < n; i++) cin >> s[i] >> d[i];
  for (long long i = 0; i < n; i++) {
    long long cur = s[i];
    while (cur < t) {
      cur += d[i];
    }
    if (mx > cur) {
      mx = cur;
      ans = i + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
