#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, f = 0, s = 0;
  cin >> n;
  while (n > 0) {
    if (n % 2 == 0)
      f++, n -= 4;
    else
      s++, n -= 7;
  }
  if (n < 0)
    cout << "-1";
  else {
    string last = "";
    for (int i = 0; i < f; i++) last += '4';
    for (int i = 0; i < s; i++) last += '7';
    cout << last;
  }
  return 0;
}
