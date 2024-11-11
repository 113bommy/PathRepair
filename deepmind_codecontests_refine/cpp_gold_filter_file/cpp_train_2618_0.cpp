#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int d = 0;
  if (b % a != 0) {
    cout << "-1";
    return 0;
  }
  int c = b / a;
  if (c == 1) {
    cout << "0";
    return 0;
  }
  while (c != 0) {
    if (c % 2 == 0) {
      c = c / 2;
      d++;
    } else
      break;
  }
  while (c != 0) {
    if (c % 3 == 0) {
      c = c / 3;
      d++;
    } else
      break;
  }
  if (c == 1)
    cout << d;
  else
    cout << "-1";
  return 0;
}
