#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x = 0;
  cin >> n >> m;
  for (int a = 0; a < 32; a++) {
    if (a - (2 * pow(a, 2) * n) + pow(a, 4) == m - pow(n, 2) &&
        n - pow(a, 2) >= 0) {
      x++;
    }
  }
  cout << x;
}
