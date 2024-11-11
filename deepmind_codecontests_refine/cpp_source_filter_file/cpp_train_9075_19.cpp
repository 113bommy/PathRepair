#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int s4 = 0, s7 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '4') s4++;
    if (s[i] == '7') s7++;
  }
  (!s4 && !s7) ? cout << -1 : (s4 <= s7) ? cout << 4 : cout << 7;
}
