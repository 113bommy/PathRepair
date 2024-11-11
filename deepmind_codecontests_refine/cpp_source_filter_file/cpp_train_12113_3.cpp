#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, t, a, b, da, db, i, j;
  bool isFound = false;
  cin >> x >> t >> a >> b >> da >> db;
  for (i = 0; i <= t; i++) {
    for (j = 0; j <= t - i; j++) {
      if ((a - da * i) + (b - db * j) == x) isFound = true;
      if ((a - da * i) == x) isFound = true;
      if ((b - db * j) == x) isFound = true;
    }
  }
  if (x == 0) isFound = true;
  if (isFound)
    cout << "YES";
  else
    cout << "NO";
}
