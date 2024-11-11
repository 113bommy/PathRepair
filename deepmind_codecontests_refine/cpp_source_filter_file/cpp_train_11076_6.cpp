#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  int m = 0, res = 0;
  cin >> s;
  for (int i = s.length() - 5; i >= 0; i--) {
    if (s.substr(i, 5) == "metal")
      m++;
    else if (s.substr(i, 5) == "heavy")
      res += m;
  }
  cout << res << endl;
}
