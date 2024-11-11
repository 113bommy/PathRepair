#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long ans = 0, cnt = 0, tmp;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1')
        break;
      else
        ++tmp;
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1')
        ans += cnt, cnt = 0;
      else
        ++cnt;
    }
    if (ans > 0)
      cout << ans - tmp << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
