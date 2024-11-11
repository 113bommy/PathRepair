#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, c1 = 0;
  char s;
  cin >> a >> s >> b >> c;
  while (c - 60 >= 0) {
    c1++;
    c -= 60;
  }
  a += c1;
  while (a > 24) a -= 24;
  b += c;
  while (b > 60) {
    a++;
    b -= 60;
  }
  while (a > 24) a -= 24;
  a < 10 ? cout << 0 : cout << "";
  cout << a;
  cout << ":";
  b < 10 ? cout << 0 : cout << "";
  cout << b;
}
