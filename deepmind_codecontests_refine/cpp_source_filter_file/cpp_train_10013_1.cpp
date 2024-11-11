#include <bits/stdc++.h>
using namespace std;
int n, b, g, ans;
int main() {
  cin >> n >> b >> g;
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
