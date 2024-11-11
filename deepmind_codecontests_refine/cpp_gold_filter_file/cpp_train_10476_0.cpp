#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int c = 0;
  if (s.length() >= 3) {
    for (int i = 0; i <= s.length() - 3; i++) {
      if (s[i] == 'Q') {
        for (int j = i; j < s.length() - 1; j++) {
          if (s[j] == 'A') {
            for (int m = j; m <= s.length(); m++) {
              if (s[m] == 'Q') {
                c++;
              }
            }
          }
        }
      }
    }
  }
  cout << c << endl;
  return 0;
}
