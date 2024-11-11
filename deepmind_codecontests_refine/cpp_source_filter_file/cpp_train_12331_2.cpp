#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a1, a2, a3, b1, b2, b3, a, b;
  cin >> a1 >> a2 >> a3;
  cin >> b1 >> b2 >> b3;
  cin >> n;
  a = a1 + a2 + a3;
  b = b1 + b2 + b3;
  a = (a * 1.0 / 5);
  b = (b * 1.0 / 10);
  if ((a + b) <= n)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
