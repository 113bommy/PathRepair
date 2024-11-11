#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == 1 && c == 1)
    cout << a + b + c;
  else if (a == 1 && b == 1 || a == 1 || b == 1 && a <= c)
    cout << (a + b) * c;
  else if (b == 1 && c == 1 || c == 1 || b == 1 && a > c)
    cout << a * (b + c);
  else
    cout << a * b * c;
}
