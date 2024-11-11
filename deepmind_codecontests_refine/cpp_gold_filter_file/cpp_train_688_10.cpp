#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, t, x;
  string s = "";
  cin >> t;
  for (i = 0; i < t; i++) {
    s += 'o';
  }
  int ara[t + 5];
  ara[0] = 1;
  ara[1] = 1;
  s[0] = 'O';
  s[1] = 'O';
  for (i = 2; i <= t; i++) {
    ara[i] = ara[i - 1] + ara[i - 2];
    if (ara[i] <= t) s[ara[i] - 1] = 'O';
    if (ara[i] > t)
      break;
    else
      continue;
  }
  cout << s << "\n";
  return 0;
}
