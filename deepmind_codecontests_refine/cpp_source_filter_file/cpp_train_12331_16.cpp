#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, a3, b1, b2, b3, n, p, q;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
  int c = a1 + a2 + a3;
  int m = b1 + b2 + b3;
  if (c % 5 == 0)
    p = c / 5;
  else
    p = c / 5 + 1;
  if (m % 10 == 0)
    q = m / 10;
  else
    q = m / 10 + 1;
  if (p + q < n)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
