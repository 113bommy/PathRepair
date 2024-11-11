#include <bits/stdc++.h>
using namespace std;
string s[101];
map<char, int> mp;
int used[11];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  mp['R'] = 6;
  mp['G'] = 7;
  mp['B'] = 8;
  mp['Y'] = 9;
  mp['W'] = 10;
  int ans = 1111111;
  for (int m = 0; m < (1 << 10); m++) {
    int c = 0;
    for (int i = 0; i < 10; i++)
      if ((m >> i) & 1)
        used[i + 1] = 1, c++;
      else
        used[i + 1] = 0;
    if (c >= ans) continue;
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j]) continue;
        if (s[i][0] == s[j][0]) {
          if (!used[s[i][1] - 48] && !used[s[j][1] - 48]) ok = false;
        } else if (s[i][1] == s[j][1]) {
          if (!used[mp[s[i][0]]] && !used[mp[s[j][0]]]) ok = false;
        } else if (!used[s[i][1] - 48] && !used[s[j][1] - 48] &&
                   !used[mp[s[i][0]]] && !used[mp[s[j][0]]])
          ok = false;
      }
    }
    if (ok) ans = c;
  }
  cout << ans;
}
