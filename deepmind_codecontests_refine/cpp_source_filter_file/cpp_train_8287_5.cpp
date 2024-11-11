#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, x;
  cin >> n >> a >> b >> c;
  if (a <= b && a <= c)
    x = (n - 1) * a;
  else if (b <= a && b <= c)
    x = (n - 1) * b;
  else if (c <= b && c <= a) {
    if (a <= b)
      x = ((n - 2) * c) + a;
    else
      x = ((n - 2) * c) + b;
  }
  if (n == 1) x = 0;
  cout << x << "/n";
  return 0;
}
