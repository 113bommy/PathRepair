#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, ans = 3;
  cin >> n >> m >> a >> b;
  a--;
  b--;
  if (a / m == b / m || !a % m && (b % m == m - 1 || b == n - 1))
    ans = 1;
  else if (b / m - a / m == 1 || !a % m || b % m == m - 1 || b == n - 1 ||
           a % m - b % m == 1)
    ans = 2;
  cout << ans;
  return 0;
}
