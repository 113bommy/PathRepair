#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int res =
      min(a + b + c, min(2 * a + 2 * b, min(2 * a + 2 * c, 2 * c + 2 * b)));
  cout << res << '\n';
  return 0;
}
