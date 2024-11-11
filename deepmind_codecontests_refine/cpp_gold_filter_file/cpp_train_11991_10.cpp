#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1 << 29;
const long long int maxn = 1e7;
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T... args) {
  ((cout << args << " "), ...);
}
signed main() {
  string s, t;
  cin >> s >> t;
  long long int ans = 0;
  for (long long int i = 0; i < s.length(); i++) {
    for (long long int j = i; j < s.length(); j++) {
      long long int pos = 0;
      for (long long int p = 0; p < s.length(); p++) {
        if (i <= p && p <= j) continue;
        if (pos < t.length() && t[pos] == s[p]) pos++;
      }
      if (pos == t.length()) ans = max(ans, j - i + 1);
    }
  }
  cout << ans << endl;
  return 0;
}
