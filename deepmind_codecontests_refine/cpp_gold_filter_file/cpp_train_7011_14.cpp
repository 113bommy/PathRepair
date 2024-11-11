#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, c1 = 0;
  cin >> n >> m;
  for (int a = 0; a <= n; a++) {
    for (int b = 0; b <= m; b++) {
      if ((a * a + b == n) && (a + b * b == m)) {
        c1++;
      }
    }
  }
  cout << c1;
}
