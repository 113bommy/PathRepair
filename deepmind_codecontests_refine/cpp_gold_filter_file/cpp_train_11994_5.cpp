#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int mod = 998244353;
int main() {
  long long t;
  cin >> t;
  while (t) {
    t--;
    string s;
    cin >> s;
    long long n = s.size();
    reverse(s.begin(), s.end());
    s += '$';
    reverse(s.begin(), s.end());
    s += '$';
    bool f = 1;
    for (int i = (1); i < (n + 1); i++) {
      if (s[i] == s[i - 1]) f = 0;
      if (s[i] == '?') {
        if (s[i - 1] == 'a') {
          if (s[i + 1] == 'b')
            s[i] = 'c';
          else
            s[i] = 'b';
        } else if (s[i - 1] == 'b') {
          if (s[i + 1] == 'a')
            s[i] = 'c';
          else
            s[i] = 'a';
        } else if (s[i - 1] == 'c') {
          if (s[i + 1] == 'a')
            s[i] = 'b';
          else
            s[i] = 'a';
        } else {
          if (s[i + 1] != 'a') s[i] = 'a';
          if (s[i + 1] != 'b') s[i] = 'b';
          if (s[i + 1] != 'c') s[i] = 'c';
        }
      }
    }
    if (f) {
      for (int i = (1); i < (n + 1); i++) cout << s[i];
      cout << endl;
    } else
      cout << -1 << endl;
  }
}
