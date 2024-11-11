#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int temp;
  int one = 0, two = 0, three = 0;
  for (int i = 0; i < s.size(); i = i + 2) {
    temp = (int)s[i] - 48;
    if (temp == 1)
      one++;
    else if (temp == 2)
      two++;
    else
      three++;
  }
  for (int i = 0; i < one; i++) {
    cout << 1;
    if (i != one - 1) cout << "+";
  }
  if (two > 0 && one > 0) cout << "+";
  for (int i = 0; i < two; i++) {
    cout << 2;
    if (i != two - 1) cout << "+";
  }
  if (three > 0 && (one > 0 || two > 0)) cout << "+";
  for (int i = 0; i < three; i++) {
    cout << 3;
    if (i != three - 1) cout << "+";
  }
  return 0;
}
