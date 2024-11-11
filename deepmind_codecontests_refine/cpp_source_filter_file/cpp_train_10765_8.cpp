#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[10];
  s[0] = "O-|-OOOO";
  s[1] = "O-|O-OOO";
  s[2] = "O-|OO-OO";
  s[3] = "O-|OOO-O";
  s[4] = "O-|OOO-O";
  s[5] = "-O|-OOOO";
  s[6] = "-O|O-OOO";
  s[7] = "-O|OO-OO";
  s[8] = "-O|OOO-O";
  s[9] = "-O|OOOO";
  int n;
  cin >> n;
  if (n == 0) cout << s[0] << endl;
  while (n != 0) {
    int z = n % 10;
    cout << s[z] << endl;
    n /= 10;
  }
  return 0;
}
