#include <bits/stdc++.h>
static const int INF = 1e9 + 7;
using namespace std;
bool strong(string s) {
  long long u = 0, d = 0, l = 0;
  for (int i = 0; i < s.length(); i++) {
    if (isdigit(s[i]) == true) {
      d = 1;
    } else if (isupper(s[i]) == true) {
      u = 1;
    } else {
      l = 1;
    }
  }
  if (u == 1 && l == 1 && d == 1) {
    return true;
  } else {
    return false;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long x;
  cin >> x;
  while (x--) {
    string s;
    cin >> s;
    if (strong(s) == true) {
      cout << s;
    } else {
      bool d = false;
      for (int i = 0; i < s.length(); i++) {
        string t = s;
        t[i] = '1';
        if (strong(t)) {
          cout << t << endl;
          d = true;
          break;
        }
        t[i] = 'a';
        if (strong(t)) {
          cout << t << endl;
          d = true;
          break;
        }
        t[i] = 'A';
        if (strong(t)) {
          cout << t << endl;
          d = true;
          break;
        }
      }
      if (d == true) {
        continue;
      }
      if (isupper(s[2])) {
        s[0] = 'a';
        s[1] = '1';
        cout << s << endl;
        continue;
      }
      if (islower(s[2])) {
        s[0] = 'A';
        s[1] = '1';
        cout << s << endl;
        continue;
      }
      if (isdigit(s[2])) {
        s[0] = 'a';
        s[1] = 'A';
        cout << s << endl;
        continue;
      }
    }
  }
  return 0;
}
