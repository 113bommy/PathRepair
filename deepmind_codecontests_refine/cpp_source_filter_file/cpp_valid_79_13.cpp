#include <bits/stdc++.h>
using namespace std;
int t, n, i, j, x;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> m;
    int f = 0;
    m.clear();
    int num = -1;
    for (i = 0; i < n; i++) {
      m[s[i]]++;
      if (s[i] == '7') {
        if (m['2'] >= 1)
          num = 27;
        else if (m['5'] >= 1)
          num = 57;
        else if (m['8'] >= 1)
          num = 87;
      }
    }
    if (m['1'] >= 1) {
      cout << 1 << "\n";
      cout << 1 << "\n";
    } else if (m['4'] >= 1) {
      cout << 1 << "\n";
      cout << 4 << "\n";
    } else if (m['6'] >= 1) {
      cout << 1 << "\n";
      cout << 6 << "\n";
    } else if (m['8'] >= 1) {
      cout << 1 << "\n";
      cout << 8 << "\n";
    } else if (m['9'] >= 1) {
      cout << 1 << "\n";
      cout << 9 << "\n";
    } else if ((m['2'] == 1 && s[0] != '2') || (m['5'] == 1 && s[0] != '5')) {
      if (m['2'] == 1 && s[0] != '2') {
        cout << 2 << "\n";
        cout << s[0] << 2 << "\n";
      } else if (m['5'] == 1 && s[0] != '5') {
        cout << 2 << "\n";
        cout << s[0] << 5 << "\n";
      }
    } else if (m['2'] == 2) {
      cout << 2 << "\n";
      cout << 22 << "\n";
    } else if (m['3'] == 2) {
      cout << 2 << "\n";
      cout << 33 << "\n";
    } else if (m['5'] == 2) {
      cout << 2 << "\n";
      cout << 55 << "\n";
    } else if (m['7'] == 2) {
      cout << 2 << "\n";
      cout << 77 << "\n";
    } else {
      cout << 2 << "\n";
      cout << num << "\n";
    }
  }
}
