#include <bits/stdc++.h>
using namespace std;
void sober() {
  long long int n, x = 0, a = 0, b = 0, y = 0, sum = 0, k = 0, m = 0;
  cin >> n >> k >> m >> x;
  long long int ans = 0;
  string s(n, '1');
  s[k - 1] = '2';
  for (int i = 0; i < x; i++) {
    cin >> a >> b;
    if (a) {
      if (b - 1 >= s.length()) {
        s = s + "1";
      } else if (b == 1) {
        s = "1" + s;
      } else {
        string temp = "", flag = "";
        temp = s.substr(0, b - 1);
        flag = s.substr(b - 1);
        s = temp + "1" + flag;
      }
      long long int foo = 0;
      for (int j = 0; j < s.length(); j++) {
        if (s[j] == '2') foo = j;
      }
      cout << s.length() << " " << foo + 1 << '\n';
    } else {
      long long int cur = b - 1;
      long long int foo = -1;
      for (int j = 0; j < b; j++) {
        if (s[j] == '2') {
          foo = j;
        }
      }
      if (foo != -1) {
        s = s.substr(0, b);
      } else {
        s = s.substr(b);
      }
      foo = 0;
      for (int j = 0; j < s.length(); j++) {
        if (s[j] == '2') foo = j;
      }
      cout << s.length() << " " << foo + 1 << '\n';
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    sober();
  }
}
