#include <bits/stdc++.h>
using namespace std;
int main() {
  char l;
  int s, e, t, n, ans, mn = 0, flag = 0;
  ;
  string str;
  cin >> t;
  for (int q = 0; q < t; q++) {
    cin >> n;
    cin >> str;
    mn = 100000;
    for (int i = 0; i < 26; i++) {
      ans = 0;
      l = 'a' + i;
      s = 0;
      e = n - 1;
      flag = 0;
      while (e - s > 1) {
        if (str[s] == str[e]) {
          s++;
          e--;
        } else if (str[s] == l) {
          s++;
          ans++;
        } else if (str[e] == l) {
          e--;
          ans++;
        } else {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        if (ans < mn) {
          mn = ans;
        }
      }
    }
    if (mn != 100000) {
      cout << mn << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
