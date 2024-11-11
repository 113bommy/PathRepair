#include <bits/stdc++.h>
using namespace std;
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t n, q, i, ans;
  cin >> n >> q;
  string str;
  cin >> str;
  str = "#" + str + "#";
  ans = 0;
  for (int64_t i = 1; i < n + 1; i++)
    ans += (str[i] == '.' and str[i + 1] == '.');
  while (q--) {
    int64_t pos;
    char ch;
    cin >> pos >> ch;
    if (ch == '.' and str[pos] != '.') {
      ans += str[pos - 1] == '.';
      ans += str[pos + 1] == '.';
    } else if (ch != '.' and str[pos] == '.') {
      ans -= str[pos - 1] == '.';
      ans -= str[pos + 1] == '.';
    }
    str[pos] = ch;
    cout << ans << endl;
  }
  return 0;
}
