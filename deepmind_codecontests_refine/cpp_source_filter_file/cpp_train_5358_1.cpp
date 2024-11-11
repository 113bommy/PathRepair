#include <bits/stdc++.h>
using namespace std;
int n, x, y, i;
int main() {
  cin >> x >> y;
  n = x + 1;
  for (i = 1; i <= n; i++) {
    cout << y + i << " ";
  }
  for (i = y; i > 0; i--) {
    cout << y << " ";
  }
}
