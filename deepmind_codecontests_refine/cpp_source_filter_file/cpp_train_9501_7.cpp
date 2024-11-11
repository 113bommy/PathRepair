#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void fun() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  char tmp;
  long long count = 0;
  while (s.size() && s[0] == s[s.size() - 1]) {
    tmp = s[0];
    count++;
    s.pop_back();
  }
  while (s.size()) {
    if (s[0] == tmp) {
      count++;
      s.erase(s.begin());
    } else
      break;
  }
  if (s.size() == 0) {
    if (count <= 2)
      cout << 0 << "\n";
    else
      cout << (count + 2) / 3;
    return;
  }
  long long ans = count / 3;
  count = 0;
  if (s.size() >= 3) {
    for (long long i = 0; i <= s.size() - 3; ++i) {
      if ((s[i] == 'L' || s[i] == 'R') && s[i] == s[i + 1] &&
          s[i + 1] == s[i + 2]) {
        ans += 1;
        if (s[i] == 'L')
          s[i + 1] = 'R';
        else
          s[i + 1] = 'L';
        i += 2;
      }
    }
  }
  cout << ans << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    fun();
  }
  return 0;
}
