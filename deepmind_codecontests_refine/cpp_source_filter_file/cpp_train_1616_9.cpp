#include <bits/stdc++.h>
using namespace std;
void yo() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  cout << fixed;
}
int main() {
  yo();
  long long n;
  cin >> n;
  string ans = "";
  long long cnt = 0;
  while (n--) {
    string s;
    cin >> s;
    long long sn = s.size();
    if (s == "0") {
      cout << 0;
      return 0;
    }
    bool flag = s[0] == '1' && count(s.begin(), s.end(), '0') == sn - 1;
    if (flag)
      cnt += (sn - 1);
    else
      ans = s;
  }
  cout << ans;
  while (cnt--) cout << 0;
  return 0;
}
