#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, a3, b1, b2, b3, n, k, s;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
  k = (a1 + a2 + a3 + 5 - 1) / 5;
  s = (b1 + b2 + b3 + 9) / 10;
  if (k + s <= n)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
