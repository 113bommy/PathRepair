#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int ans;
int main() {
  cin >> n >> m >> a >> b;
  int a1 = (a % m == 0) ? a / m : a / m + 1;
  int a2 = (a % m == 0) ? m : a % m;
  int b1 = (b % m == 0) ? b / m : b / m + 1;
  int b2 = (b % m == 0) ? m : b % m;
  if (a1 == b1)
    ans = 1;
  else if (a2 == 1 && b2 == m)
    ans = 1;
  else if (a2 == 1 && b == n)
    ans = 1;
  else if (b1 - a1 == 1)
    ans = 2;
  else if (a2 == 1)
    ans = 2;
  else if (b2 == m)
    ans = 2;
  else if (a2 - b2 == 1)
    ans = 2;
  else if (b == n)
    ans = 2;
  cout << ans << endl;
  return 0;
}
