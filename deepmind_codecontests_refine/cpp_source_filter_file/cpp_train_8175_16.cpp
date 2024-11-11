#include <bits/stdc++.h>
using namespace std;
const int sss = 1E6;
bool hole[2000005];
int main() {
  int l, k = 0, d = 0;
  char c[15] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V',
                'W', 'X', 'o', 'v', 'x', 'Y', 'w'};
  string s;
  cin >> s;
  if (s.length() == 1) {
    for (int i = 0; i < 15; i++) {
      if (s[0] == c[i]) {
        d++;
      }
    }
    if (d == 1) {
      cout << "TAK";
      return 0;
    } else {
      cout << "NIE";
      return 0;
    }
  }
  if (s.length() % 2 != 0) {
    for (int i = 0; i < 15; i++) {
      if (s[s.length() / 2] == c[i]) {
        d++;
      }
    }
    if (d == 1) {
      k = 0;
    } else {
      k = 1;
    }
    s.erase(s.begin() + s.length() / 2);
  }
  for (int i = 0; i < s.length() / 2; i++) {
    l = 0;
    for (int j = 0; j < 15; j++) {
      if (s[i] == c[j]) {
        l++;
      }
    }
    if (s[i] == s[s.length() - i - 1] && l == 1) {
      k++;
    } else if ((s[i] == 'b' && s[s.length() - i - 1] == 'd') ||
               (s[i] == 'p' && s[s.length() - i - 1] == 'q') ||
               (s[s.length() - i - 1] == 'p' && s[i] == 'q') ||
               (s[s.length() - i - 1] == 'b' && s[i] == 'd')) {
      k++;
    }
  }
  if (k == s.length() / 2) {
    cout << "TAK";
  } else {
    cout << "NIE";
  }
}
