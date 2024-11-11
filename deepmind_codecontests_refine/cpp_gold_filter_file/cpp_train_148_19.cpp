#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, s = 0, c = 5;
  while (c--) {
    cin >> x;
    s += x;
  }
  if (s && s % 5 == 0)
    cout << s / 5;
  else
    cout << "-1";
  return 0;
}
