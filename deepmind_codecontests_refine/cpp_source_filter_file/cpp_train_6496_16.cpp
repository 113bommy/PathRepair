#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long int curr = 1, ans = 0, x;
  while (m--) {
    cin >> x;
    if (x >= curr) {
      ans += x - curr;
      curr = x;
    } else {
      ans += n - (curr - x);
      curr = x;
    }
  }
  cout << ans;
  return 0;
}
