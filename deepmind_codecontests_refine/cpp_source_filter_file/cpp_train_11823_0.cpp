#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n = 0;
  cin >> a >> b >> c;
  if (a > b && b > c)
    n = (a - b) + (b - c);
  else if (a > c && c > b)
    n = a - c + c - b;
  else if (b > a && a > c)
    n = b - a + a - c;
  else if (b > c && c > a)
    n = b - c + c - a;
  else if (c > a && a > b)
    n = c - a && a - b;
  else
    n = c - b + b - a;
  cout << n;
}
