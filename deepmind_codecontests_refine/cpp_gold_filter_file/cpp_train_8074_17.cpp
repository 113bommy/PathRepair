#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, inf = 1e9;
  cin >> n;
  x = n;
  y = n + 1;
  if (x * y > inf || n == 1)
    cout << -1;
  else {
    cout << x << " " << y << " " << x * y;
  }
  return 0;
}
