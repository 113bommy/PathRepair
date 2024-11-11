#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
string constructstring(string s, int x) {
  string str;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if ((i - x >= 0 && s[i - x] == '1') || (i + x < n && s[i + x] == '1')) {
      str.push_back('1');
    } else {
      str.push_back('0');
    }
  }
  return str;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, x;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cin >> x;
    string str = s;
    for (auto &c : str) c = '1';
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (i - x >= 0) {
          str[i - x] = '0';
        } else if (i + x < n) {
          str[i + x] = '0';
        }
      }
    }
    if (s == constructstring(str, x)) {
      cout << str << '\n';
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
