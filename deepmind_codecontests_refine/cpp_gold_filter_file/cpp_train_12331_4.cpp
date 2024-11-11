#include <bits/stdc++.h>
using namespace std;
int a1, a2, a3, b1, b2, b3, n, c, m;
int main() {
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
  c = a1 + a2 + a3;
  m = b1 + b2 + b3;
  if (c % 5 != 0) {
    int x = 5 - (c % 5);
    c += x;
  }
  if (m % 10 != 0) {
    int x = 10 - (m % 10);
    m += x;
  }
  if (c / 5 + m / 10 > n) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
