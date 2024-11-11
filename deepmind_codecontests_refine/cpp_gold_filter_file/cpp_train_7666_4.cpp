#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 1;
const long long inf = 1e18;
int main() {
  ios_base::sync_with_stdio(0);
  string s, need = "abcdefghijklmnopqrstuvwxyz", ans = "";
  char now = 'a';
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (now > 'z') {
      ans += s[i];
      continue;
    }
    if (now >= s[i]) {
      ans += now;
      now++;
    } else {
      ans += s[i];
    }
  }
  if (now <= 'z') {
    cout << -1;
  } else {
    cout << ans;
  }
  return 0;
}
