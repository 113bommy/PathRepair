#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  float p;
  cin >> a >> b;
  if (a >= b)
    c = 7 - a;
  else
    c = 7 - b;
  if (c == 0)
    cout << "0";
  else if (c == 1)
    cout << "1/6";
  else if (c == 2)
    cout << "1/3";
  else if (c == 3)
    cout << "1/2";
  else if (c == 4)
    cout << "2/3";
  else if (c == 5)
    cout << "5/6";
  else
    cout << "6/6";
  return 0;
}
