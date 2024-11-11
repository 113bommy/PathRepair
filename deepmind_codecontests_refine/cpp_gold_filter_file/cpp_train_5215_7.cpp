#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  ;
  string s;
  cin >> s;
  long long ans = 0, one = 0, two = 0;
  for (long long i = 0; i < s.size(); i++) {
    long long t = s[i] - '0';
    if (t % 3 == 0) {
      ans++;
      one = 0;
      two = 0;
    } else if (t % 3 == 1)
      one++;
    else
      two++;
    if (one == 3 || two == 3 || (one >= 1 && two >= 1)) {
      ans++;
      one = 0;
      two = 0;
    }
  }
  cout << ans;
}
