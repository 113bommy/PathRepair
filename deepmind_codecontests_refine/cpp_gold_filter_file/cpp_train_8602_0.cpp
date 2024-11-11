#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = (int)s.length();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = 0, q = 0;
    for (int j = i; j < n; ++j) {
      if (s[j] == ')')
        cnt--;
      else if (s[j] == '(')
        cnt++;
      else
        q++;
      if (q > cnt && q > 0) cnt++, q--;
      if (cnt < 0) break;
      if ((j - i) % 2 && q >= cnt) ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
