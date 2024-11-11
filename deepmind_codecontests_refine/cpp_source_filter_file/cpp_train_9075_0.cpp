#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k4 = 0, k7 = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '4') k4++;
    if (s[i] == '7') k7++;
  }
  if (k4 == 0 && k7 == 0)
    cout << -1;
  else {
    if (k4 > k7)
      cout << 4;
    else
      cout << 7;
  }
}
