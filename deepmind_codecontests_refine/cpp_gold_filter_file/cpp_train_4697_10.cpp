#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, s = 0;
  cin >> a >> b >> c;
  while (a + b <= c) {
    if (a < b)
      a++;
    else
      b++;
    s++;
  }
  while (a + c <= b) {
    if (a < c)
      a++;
    else
      c++;
    s++;
  }
  while (c + b <= a) {
    if (c < b)
      c++;
    else
      b++;
    s++;
  }
  cout << s;
}
