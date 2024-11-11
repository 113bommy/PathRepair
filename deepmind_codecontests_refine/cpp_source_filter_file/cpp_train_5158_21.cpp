#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0, a, b, c, d, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    a = i + m;
    a /= 5;
    b = i / 5;
    x += (a - b);
  }
  cout << x;
  return 0;
}
