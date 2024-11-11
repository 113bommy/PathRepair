#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int val;
  string news;
  for (long long i = 0; i < s.length(); i++) {
    for (long long j = i + 1; j < s.length(); j++) {
      for (long long k = j + 1; k < s.length(); k++) {
        val = 100 * (s[i] - '0') + 10 * (s[j] - '0') + 1 * (s[k] - '0');
        if (val % 8 == 0) {
          cout << "YES" << '\n';
          cout << val << '\n';
          return;
        }
      }
      val = 10 * (s[i] - '0') + 1 * (s[j] - '0');
      if (val % 8 == 0) {
        cout << "YES" << '\n';
        cout << val << '\n';
        return;
      }
    }
    if ((s[i] - '0') % 8 == 0) {
      cout << "YES" << '\n';
      cout << s[i] - '0' << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
