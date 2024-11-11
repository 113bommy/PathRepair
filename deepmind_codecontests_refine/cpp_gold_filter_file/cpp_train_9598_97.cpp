#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, t, k, x, y, m, maxer = 0;
  char s;
  cin >> n >> x >> y;
  n = n - x;
  if (n <= y)
    cout << n;
  else
    cout << y + 1;
  return 0;
}
