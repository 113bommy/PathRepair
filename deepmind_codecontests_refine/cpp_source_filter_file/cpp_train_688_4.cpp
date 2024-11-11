#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, x, i;
  string s = "";
  cin >> n;
  for (i = 0; i < n; i++) s = s + "o";
  a = 1, b = 1;
  if (n == 1)
    cout << 'O';
  else if (n == 2)
    cout << 'O';
  else {
    s[0] = 'O';
    s[1] = 'O';
    x = 0;
    while (x < n) {
      x = a + b;
      s[x - 1] = 'O';
      a = b;
      b = x;
    }
    cout << s;
  }
}
