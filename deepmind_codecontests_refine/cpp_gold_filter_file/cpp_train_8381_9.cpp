#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < s.length(); ++i) {
    int last = (s[i - 1] - '0') * 10 + s[i] - '0';
    if (i > 0 && last % 4 == 0) {
      ans += i;
    }
    if ((s[i] - '0') % 4 == 0) ++ans;
  }
  cout << ans << "\n";
  return 0;
}
