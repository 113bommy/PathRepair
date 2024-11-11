#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  if ((a % m == 1) && (b % m == 0 || b == n) || ((a - 1) / m == (b - 1) / m) ||
      m == 1)
    cout << 1;
  else if (a % m == 1 || b % m == 0 || b == n ||
           (a - 1) / m == (b - 1) / m - 1 || a % m == (b % m + 1) % m)
    cout << 2;
  else
    cout << 3;
  return 0;
}
