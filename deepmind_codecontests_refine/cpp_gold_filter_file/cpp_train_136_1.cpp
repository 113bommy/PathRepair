#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = (a * c - (c - 1) * b - 1) / b;
  cout << ans << endl;
  return 0;
}
