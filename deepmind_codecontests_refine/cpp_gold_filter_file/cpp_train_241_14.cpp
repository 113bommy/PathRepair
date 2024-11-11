#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, ans = LLONG_MAX;
  cin >> a >> b >> c;
  if ((a - b) % 2 == 0) ans = min(ans, max(a, b));
  if ((a - c) % 2 == 0) ans = min(ans, max(a, c));
  if ((c - b) % 2 == 0) ans = min(ans, max(b, c));
  if (ans == INT_MAX) ans = -1;
  cout << ans;
  return 0;
}
