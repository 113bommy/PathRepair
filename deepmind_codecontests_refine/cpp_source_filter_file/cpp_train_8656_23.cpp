#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int t, pos, flag = 0;
    string s;
    cin >> t >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '8') {
        flag = 1;
        pos = i + 1;
        break;
      }
    }
    if (flag == 1 && t - pos >= 11)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
