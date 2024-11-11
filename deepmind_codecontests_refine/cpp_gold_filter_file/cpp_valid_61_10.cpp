#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
      if (s[0] == '?') {
        cout << "B\n";
      } else {
        cout << s[0] << "\n";
      }
    } else {
      if (s[0] == '?') {
        int in = -1;
        string res = "";
        for (int i = 0; i < s.length(); i++) {
          res.push_back(s[i]);
          if (s[i] != '?') {
            in = i;
            break;
          }
        }
        if (in == -1) {
          string res1 = "";
          for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
              res1.push_back('B');
            } else {
              res1.push_back('R');
            }
          }
          cout << res1 << "\n";
        } else {
          for (int i = in - 1; i >= 0; i--) {
            if (res[i + 1] == 'B') {
              res[i] = 'R';
            } else {
              res[i] = 'B';
            }
          }
          for (int i = in + 1; i < s.length(); i++) {
            if (s[i] == '?') {
              if (res[i - 1] == 'B') {
                res.push_back('R');
              } else {
                res.push_back('B');
              }
            } else {
              res.push_back(s[i]);
            }
          }
          cout << res << "\n";
        }
      } else {
        string res = "";
        res.push_back(s[0]);
        for (int i = 1; i < s.length(); i++) {
          if (s[i] == '?') {
            if (res[i - 1] == 'B') {
              res.push_back('R');
            } else {
              res.push_back('B');
            }
          } else {
            res.push_back(s[i]);
          }
        }
        cout << res << "\n";
      }
    }
  }
  return 0;
}
