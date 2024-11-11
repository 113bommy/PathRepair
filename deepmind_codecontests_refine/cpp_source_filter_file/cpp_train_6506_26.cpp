#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, m;
  string s;
  cin >> n >> m >> s;
  ll ans = n * m - n;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      ans += n * m - n;
    }
  }
  for (char c = 'a'; c < 'a' + m; ++c) {
    for (char d = c + 1; d < 'a' + m; ++d) {
      int x = 0;
      while (x < n) {
        if (s[x] == c || s[x] == d) {
          int len = 1;
          ++x;
          while (x < n && (s[x] == c || s[x] == d) && s[x] != s[x - 1]) {
            ++x, ++len;
          }
          ans -= len * (len - 1) / 2;
        } else {
          ++x;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
