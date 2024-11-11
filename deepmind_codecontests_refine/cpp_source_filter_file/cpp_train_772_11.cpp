#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k;
  getline(cin, s);
  cin >> k;
  int max = 0;
  bool c;
  for (int i = 0; i < s.size() + k; i++) {
    for (int j = i + 2; j <= s.size() + k; j += 2) {
      c = false;
      for (int l = i; l < (j - i) / 2; l++) {
        if ((l + (j - i) / 2 < s.size()) && s[l] != s[l + (j - i) / 2]) {
          c = true;
        }
      }
      if (!c && j - i > max) {
        max = j - i;
      }
    }
  }
  cout << max;
  return 0;
}
