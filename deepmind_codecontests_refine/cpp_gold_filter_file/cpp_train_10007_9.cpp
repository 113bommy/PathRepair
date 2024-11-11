#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string ans;
  int now = atoi(s.c_str()) * 60;
  s = s.substr(3, 2);
  now += atoi(s.c_str());
  now++;
  for (;; now++) {
    ans = "";
    if (now == 1440) now = 0;
    int h = now / 60, m = now - h * 60;
    if (h < 10) {
      ans += '0';
      ans += (h + '0');
      ans += ':';
      ans += (m / 10 + '0');
      ans += (m % 10 + '0');
    } else {
      ans += (h / 10 + '0');
      ans += (h % 10 + '0');
      ans += ':';
      ans += (m / 10 + '0');
      ans += (m % 10 + '0');
    }
    string t = ans;
    reverse(t.begin(), t.end());
    if (ans == t) break;
  }
  cout << ans << endl;
  return 0;
}
