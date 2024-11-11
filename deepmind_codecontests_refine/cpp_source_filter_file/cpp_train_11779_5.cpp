#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x, y, z;
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b + c >= x + y + z) {
    if (a >= x && (a - x + b) >= y)
      cout << "YES";
    else
      cout << "NO";
  } else
    cout << "NO";
}
