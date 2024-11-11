#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int x = 0, X = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    if (s[i] == 'x')
      ++x;
    else
      ++X;
  }
  int diff = abs((X - x) / 2);
  cout << diff << endl;
  if (diff > 0) {
    for (int i = 0, j = 0; i < diff; ++j) {
      if (s[j] == 'x') {
        ++i;
        s[j] = 'X';
      }
    }
  } else {
    for (int i = 0, j = 0; i < diff; ++j) {
      if (s[j] == 'X') {
        ++i;
        s[j] = 'x';
      }
    }
  }
  cout << s << endl;
  return 0;
}
