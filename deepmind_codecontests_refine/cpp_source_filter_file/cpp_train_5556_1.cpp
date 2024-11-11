#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  int L(0), R(0);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '+')
      if (R == 0)
        L++;
      else {
        L++;
        R--;
      }
    if (s[i] == '-')
      if (L == 0)
        R++;
      else {
        R++;
        L--;
      }
  }
  cout << abs(L - R);
  return 0;
}
