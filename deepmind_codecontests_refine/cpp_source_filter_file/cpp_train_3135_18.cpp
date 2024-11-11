#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a, b;
  cin >> n >> m;
  a = min(n, m);
  b = max(n, m);
  if (a == 1 && b < 4)
    cout << 0;
  else if (a == 1 && b % 6 < 4)
    cout << 6 * (b / 6);
  else if (a == 1 && b % 6 == 4)
    cout << 6 * (b / 6) + 2;
  else if (a == 1 && b % 6 == 5)
    cout << 6 * (b / 6) + 5;
  else if (a == 2 && b == 2)
    cout << 0;
  else if (a == 2 && b % 2 == 1)
    if (b == 3)
      cout << a * b - 2;
    else if (b == 7)
      cout << a * b - 2;
    else
      cout << a * b;
  else if (a == 2 && b % 2 == 0)
    cout << a * b;
  else if (a % 2 == 0)
    cout << a * b;
  else if (b % 2 == 0)
    cout << a * b;
  else if (a % 2 == 1 && b % 2 == 1)
    cout << a * b - 1;
}
