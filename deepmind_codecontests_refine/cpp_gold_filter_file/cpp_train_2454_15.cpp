#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  for (int i = 1; i <= a; ++i) {
    if (2 * i <= b and 4 * i <= c) ans = i + 2 * i + 4 * i;
  }
  cout << ans << "\n";
  return 0;
}
