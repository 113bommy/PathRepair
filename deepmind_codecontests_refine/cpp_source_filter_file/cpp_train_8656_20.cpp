#include <bits/stdc++.h>
using namespace std;
int main() {
  short t;
  cin >> t;
  while (t--) {
    short n;
    cin >> n;
    string s;
    cin >> s;
    short l = s.length();
    if (l == 11 && s[0] == '8')
      cout << "YES" << endl;
    else if (l < 11)
      cout << "NO" << endl;
    else if (l == 11 && s[0] != '8')
      cout << "NO" << endl;
    else {
      short i, k = n - 11;
      if (s[k + 1] == '8')
        cout << "YES" << endl;
      else {
        for (i = 0; i < k; i++)
          if (s[i] == '8') {
            cout << "YES" << endl;
            break;
          }
        if (i == k) cout << "NO" << endl;
      }
    }
  }
  return 0;
}
