#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, t, k, x, y, m, maxer = 0;
  char s;
  cin >> n >> x >> y;
  n = n - x - y;
  if (n <= 0)
    cout << y;
  else
    cout << x + 1;
  return 0;
}
