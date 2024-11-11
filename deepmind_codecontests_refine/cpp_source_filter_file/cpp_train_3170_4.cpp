#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, b = 0;
  string x, y, z;
  cin >> n;
  cin >> x;
  a++;
  for (int i = 1; i < n; i++) {
    cin >> y;
    if (x == y)
      a++;
    else {
      b++;
      z = y;
    }
  }
  if (a > b)
    cout << x;
  else
    cout << y;
}
