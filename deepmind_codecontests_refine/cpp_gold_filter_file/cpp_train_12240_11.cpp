#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, i, j, x, y;
  cin >> n >> m >> k;
  x = (k - 1) / (2 * m) + 1;
  y = ((k - 1) % (2 * m)) / 2 + 1;
  cout << x << " " << y;
  if (k % 2 == 0)
    cout << " R";
  else
    cout << " L";
  return 0;
}
