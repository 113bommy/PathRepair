#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, cnt, j, k;
  int c4, c7;
  c4 == 0;
  c7 == 0;
  string s, d;
  cin >> s;
  t = s.size();
  j = 0;
  for (int i = 0; i < t; i++) {
    if (s[i] == '4') {
      c4++;
    } else if (s[i] == '7') {
      c7++;
    }
  }
  if (c4 > c7)
    cout << "4";
  else if (c7 > c4)
    cout << "7";
  else if (c4 == c7 && c4 != 0)
    cout << "4";
  else
    cout << "-1";
}
