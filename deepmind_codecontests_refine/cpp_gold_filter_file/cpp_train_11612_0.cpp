#include <bits/stdc++.h>
using namespace std;
int main() {
  int h1, h2, a, b;
  cin >> h1 >> h2;
  cin >> a >> b;
  h1 += 8 * a;
  if (h1 >= h2) {
    cout << 0;
    return 0;
  }
  if (b >= a) {
    cout << -1;
    return 0;
  }
  int ans = 0;
  while (1) {
    ans++;
    h1 -= 12 * b;
    h1 += 12 * a;
    if (h1 >= h2) {
      cout << ans;
      return 0;
    }
  }
  return 0;
}
