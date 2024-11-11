#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, cc, m, ans;
  bool x;
  cin >> a >> b >> c;
  cc = c * 2;
  m = min(a, b) * 2;
  x = a != b;
  ans = cc + m + x;
  cout << ans;
}
