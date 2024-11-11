#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "0000";
  for (int i = 0; i < 4; i++) {
    int z = 0, c;
    for (int j = 0; j <= 9; j++) {
      s[i] = j + '0';
      cout << s << endl;
      cout.flush();
      int x, y;
      cin >> x >> y;
      if (x >= z) z = x, c = j;
      if (x == 4) return 0;
    }
    s[i] = c + '0';
  }
  return 0;
}
