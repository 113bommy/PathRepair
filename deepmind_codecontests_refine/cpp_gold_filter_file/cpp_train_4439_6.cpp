#include <bits/stdc++.h>
using namespace std;
int N = 86400;
int main() {
  bool b = 0;
  int x = 0, max = 0;
  string s;
  cin >> s;
  if (s.length() < 7) {
    cout << "no";
    return 0;
  }
  for (int i = s.length() - 1; i > 0 && x < 6; --i) {
    if (s[i] != '1') {
      x++;
    }
    max = i;
  }
  for (int i = max - 1; i > -1 && x > 5; --i) {
    if (s[i] != '0') {
      cout << "yes";
      return 0;
    }
  }
  cout << "no";
}
