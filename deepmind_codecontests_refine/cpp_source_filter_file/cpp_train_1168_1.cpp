#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, i, p = 0;
    cin >> a >> b >> c;
    string s;
    cin >> s;
    for (i = 0; i < s.size() - 1; i++) {
      if (s[i] == 'A') {
        p += a;
        while (s[i + 1] == 'A') {
          i++;
        }
      }
      if (s[i] == 'B') {
        p += b;
        while (s[i + 1] == 'B') i++;
      }
    }
    if (p <= c)
      cout << "1" << endl;
    else {
      for (i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'A') {
          p = p - a;
          while (s[i + 1] == 'A' && i + 1 < s.size() - 1) i++;
        } else if (s[i] == 'B') {
          p = p - b;
          while (s[i + 1] == 'B' && i + 1 < s.size() - 1) i++;
        } else
          ;
        if (c >= p) {
          i++;
          break;
        }
      }
      cout << i + 1 << endl;
    }
  }
  return 0;
}
