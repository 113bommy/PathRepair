#include <bits/stdc++.h>
using namespace std;
string char_to_str(char c) {
  string tem(1, c);
  return tem;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long n, k;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;
  long long v[n];
  long long pr = 1;
  for (long long i = 0; i < n; ++i) {
    if (s[i] == 'a' && t[i] == 'b') {
      v[i] = min(k, pr * 2);
    }
    if (s[i] == 'b' && t[i] == 'b') {
      v[i] = min(k, 1 + (pr - 1) * 2);
    }
    if (s[i] == 'a' && t[i] == 'a') {
      v[i] = min(k, 1 + (pr - 1) * 2);
    }
    if (s[i] == 'b' && t[i] == 'a') {
      v[i] = min(k, max(pr, 2 + (pr - 2) * 2));
    }
    pr = v[i];
  }
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    ans += v[i];
  }
  cout << ans;
}
