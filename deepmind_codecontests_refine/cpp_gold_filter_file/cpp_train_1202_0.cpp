#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  cin >> x;
  int X = 0, Y = 0;
  for (int i = 0; i < x.size(); i++) {
    if (x[i] == 'L')
      X--;
    else if (x[i] == 'D')
      Y--;
    else if (x[i] == 'U')
      Y++;
    else
      X++;
  }
  if (x.size() % 2 == 0)
    cout << (abs(X) + abs(Y)) / 2;
  else
    cout << "-1";
  return 0;
}
