#include <bits/stdc++.h>
using namespace std;
int main() {
  string p;
  cin >> p;
  long long n, count = 0, count1 = 0;
  cin >> n;
  if (n == 1) {
    string s;
    cin >> s;
    if ((s[0] == p[0] && s[1] == p[1]) || (s[0] == p[1] && s[1] == p[0])) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    while (n--) {
      string s;
      cin >> s;
      if ((s[0] == p[0] && s[1] == p[1]) || (s[0] == p[1] && s[1] == p[1])) {
        cout << "YES" << endl;
        return 0;
      } else if (s[0] == p[1]) {
        count++;
      } else if (s[1] == p[0]) {
        count1++;
      }
    }
    if (count > 0 && count1 > 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
