#include <bits/stdc++.h>
using namespace std;
int main() {
#pragma warning(disable : 4996)
  int x = 0, y = 0, co = 0;
  char c;
  while (cin >> c) {
    if (c == 'U')
      y++;
    else if (c == 'D')
      y--;
    else if (c == 'L')
      x--;
    else
      x++;
    co++;
  }
  if (co % 2 == 1) {
    cout << -1;
  } else
    cout << (abs(x) + abs(x)) / 2;
}
