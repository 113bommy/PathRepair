#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tst = 0;
  cin >> tst;
  while (tst--) {
    int n = 0;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    while (s[i] == '?' && i < n && i++)
      ;
    while (i >= 0 && i--) {
      if (s[i] == '?') {
        if (s[i + 1] == 'B')
          s[i] = 'R';
        else
          s[i] = 'B';
      }
    }
    for (int i = 1; i < n; i++) {
      if (s[i] == '?') {
        if (s[i - 1] == 'B')
          s[i] = 'R';
        else
          s[i] = 'B';
      }
    }
    cout << s << endl;
  }
  return 0;
}
