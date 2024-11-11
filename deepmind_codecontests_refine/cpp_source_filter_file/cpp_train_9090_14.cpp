#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
string s[105];
int n, last_hh, last_mm, last_tme, cur_tme, cur_mm, cur_hh, ans = 1, cnt = 0;
int calch(int i) { return (s[i][1] - '0') * 10 + s[i][2] - '0'; }
int calcm(int i) { return (s[i][4] - '0') * 10 + s[i][5] - '0'; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n + 1; i++) getline(cin, s[i]);
  for (int i = 2; i <= n + 1; i++) {
    last_hh = calch(i - 1);
    if (last_hh == 12) last_hh = 0;
    last_mm = calcm(i - 1);
    cur_hh = calch(i);
    if (cur_hh == 12) cur_hh = 0;
    cur_mm = calcm(i);
    last_tme = last_hh * 60 + last_mm;
    cur_tme = cur_hh * 60 + cur_mm;
    if (s[i - 1][7] == 'p') last_tme += 12 * 60;
    if (s[i][7] == 'p') cur_tme += 12 * 60;
    if (last_tme > cur_tme)
      ans++, cnt = 1;
    else if (last_tme == cur_tme) {
      cnt++;
      if (cnt == 0) ans++, cnt = 0;
    } else
      cnt = 0;
  }
  cout << ans << '\n';
  return 0;
}
