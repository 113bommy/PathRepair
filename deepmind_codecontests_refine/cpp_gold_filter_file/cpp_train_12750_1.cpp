#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string d[10];
string ans;
void precalc() {
  d[0] = "";
  d[1] = "";
  d[2] = "2";
  d[3] = "3";
  d[4] = "322";
  d[5] = "5";
  d[6] = "53";
  d[7] = "7";
  d[8] = "7222";
  d[9] = "7332";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin >> s;
  precalc();
  for (int i = 0; i < n; i++) ans += (d[s[i] - '0']);
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
