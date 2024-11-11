#include <bits/stdc++.h>
using namespace std;
string s[2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s[0] >> s[1];
  int ans = 0;
  for (int i = 0; i < s[0].size() - 1; i++) {
    if (s[0][i] == '0' && s[0][i + 1] == '0' && s[1][i] == '0' &&
        s[1][i + 1] == '0') {
      ans++;
      s[0][i + 1] = s[0][i] = s[1][i] = 'X';
    }
    int p = 0;
    if (s[0][i] == '0') p++;
    if (s[1][i] == '0') p++;
    if (s[0][i + 1] == '0') p++;
    if (s[1][i + 1] == '0') p++;
    if (p == 3) {
      ans++;
      s[0][i] = s[0][i + 1] = s[1][i] = s[1][i + 1] = 'X';
    }
  }
  cout << ans;
  return 0;
}
