#include <bits/stdc++.h>
using namespace std;
int solve() {
  string s;
  cin >> s;
  int team[2][3] = {0};
  int i;
  for (i = 0; i < 10; i++) {
    if (s[i] == '0')
      team[i % 2][0]++;
    else if (s[i] == '1')
      team[i % 2][1]++;
    else
      team[i % 2][2]++;
    if (team[0][1] + team[0][2] > team[1][1] + (10 - i) / 2)
      return i + 1;
    else if (team[1][1] + team[1][2] > team[0][1] + (9 - i) / 2)
      return i + 1;
  }
  return i + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    int ans = solve();
    cout << ans << endl;
  }
  return 0;
}
