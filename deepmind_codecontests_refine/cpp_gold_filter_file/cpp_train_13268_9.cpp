#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, p, q, x = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> p >> q;
    if (q - p >= 2) x++;
  }
  cout << x;
  return 0;
}
