#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  string s;
  cin >> s;
  while (y--) {
    for (int i = 0; i < x - 1; i++) {
      if (s[i] == 'B' && s[i + 1] == 'G') {
        s[i] = 'G';
        s[i + 1] = 'B';
        i = i + 2;
      }
    }
  }
  cout << s;
  return 0;
}
