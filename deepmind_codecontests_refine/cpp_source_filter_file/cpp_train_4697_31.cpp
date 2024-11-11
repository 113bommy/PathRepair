#include <bits/stdc++.h>
using namespace std;
void rewenie(int b) {
  int c = b / 7;
  if (b % 7 != 0) c++;
  cout << c;
}
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int sum = 0;
  if (a >= b && a >= c) {
    if (a >= b + c)
      cout << (a - b - c) + 1;
    else
      goto A;
  } else if (a <= b && b >= c) {
    if (b >= a + c)
      cout << (b - a - c) + 1;
    else
      goto A;
  } else if (a <= c && b <= c) {
    if (c >= a + c)
      cout << (c - a - b) + 1;
    else
      goto A;
  } else {
  A:
    cout << "0";
  }
}
