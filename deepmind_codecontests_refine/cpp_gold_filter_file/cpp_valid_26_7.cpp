#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int ans = 10;
  {
    int me = 0, his = 0, mybaki = 5, hisbaki = 5;
    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        mybaki--;
        if (s[i] != '0') me++;
      } else {
        hisbaki--;
        if (s[i] == '1') his++;
      }
      if (me + mybaki < his || his + hisbaki < me) ans = min(ans, i + 1);
    }
  }
  {
    int me = 0, his = 0, mybaki = 5, hisbaki = 5;
    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        mybaki--;
        if (s[i] == '1') me++;
      } else {
        hisbaki--;
        if (s[i] != '0') his++;
      }
      if (me + mybaki < his || his + hisbaki < me) ans = min(ans, i + 1);
    }
  }
  cout << ans << ("\n");
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
