#include <bits/stdc++.h>
using namespace std;
long long lastnb(string s) {
  int i = s.size() - 1, n = 0;
  while (isdigit(s[i])) i--;
  i++;
  while (i < s.size()) {
    n = n * 10 + s[i] - '0';
    i++;
  }
  return n;
}
int main() {
  string s;
  getline(cin, s);
  long long n = lastnb(s);
  long long cntminus = 0, cntplus = 1;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '+')
      cntplus++;
    else if (s[i] == '-')
      cntminus++;
  }
  if (cntplus * n - cntminus < n || cntplus - n * cntminus > n) {
    cout << "Impossible";
  } else {
    cout << "Possible\n";
    if (cntplus - cntminus >= n) {
      long long target = cntplus - n;
      for (long long i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
          if (i == 0 || s[i - 2] == '+')
            cout << 1;
          else {
            cout << min(n, target - cntminus + 1);
            target -= min(n, target - cntminus + 1);
            cntminus--;
          }
        } else {
          cout << s[i];
        }
      }
    } else {
      long long target = cntminus + n;
      for (long long i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
          if (i != 0 && s[i - 2] == '-')
            cout << 1;
          else {
            cout << min(n, target - cntplus + 1);
            target -= min(n, target - cntplus + 1);
            cntplus--;
          }
        } else {
          cout << s[i];
        }
      }
    }
  }
  return 0;
}
