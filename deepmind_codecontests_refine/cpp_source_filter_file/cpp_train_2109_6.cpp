#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, a = "";
    cin >> s;
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (s[i] > s[i + 1]) flag = false;
    }
    if (flag) {
      cout << s << '\n';
      continue;
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') break;
      a += '0';
      if (s[i] > s[i + 1]) flag = false;
    }
    a += '0';
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') break;
      a += '1';
    }
    cout << a << '\n';
  }
}
