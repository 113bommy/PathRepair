#include <bits/stdc++.h>
using namespace std;
int n, b, g, ans;
int main() {
  cin >> b >> g >> n;
  ans = n + 1;
  if (n >= b) {
    ans -= (n - b);
  }
  if (n >= g) {
    ans -= (n - g);
  }
  cout << ans << endl;
  return 0;
}
