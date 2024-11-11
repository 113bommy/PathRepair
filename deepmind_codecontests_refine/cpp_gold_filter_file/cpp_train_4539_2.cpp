#include <bits/stdc++.h>
using namespace std;
int l, k, mx, n;
bool OK;
int main() {
  string s;
  cin >> s;
  char c;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'V') {
      if (c != 'V') {
        n = 1;
        c = 'V';
      } else if (OK == false)
        if (s[i + 1] != 'K') {
          OK = true;
          ++l;
        }
    } else {
      if (c != 'K') {
        if (n == 1) ++l;
        c = 'K';
      } else if (OK == false)
        if (s[i - 2] != 'V') {
          OK = true;
          ++l;
        }
    }
  }
  cout << l;
}
