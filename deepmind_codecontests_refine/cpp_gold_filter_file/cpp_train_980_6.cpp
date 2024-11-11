#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int beat(char a, char b) {
  if (a == b) return 0;
  if (a == '8') {
    if (b == '[')
      return 1;
    else
      return -1;
  }
  if (a == '[') {
    if (b == '(')
      return 1;
    else
      return -1;
  }
  if (a == '(') {
    if (b == '8')
      return 1;
    else
      return -1;
  }
  return -10000;
}
int main() {
  string s[2];
  cin >> s[0] >> s[1];
  int n = s[0].size();
  int dif = 0;
  for (int i = 0; i < n; i += 2) {
    dif += beat(s[0][i], s[1][i]);
  }
  if (dif == 0)
    cout << "TIE" << endl;
  else if (dif > 0)
    cout << "TEAM 1 WINS" << endl;
  else
    cout << "TEAM 2 WINS" << endl;
  return 0;
}
