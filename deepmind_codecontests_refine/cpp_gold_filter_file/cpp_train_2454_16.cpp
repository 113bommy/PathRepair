#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  for (int(i) = 0; (i) < (int)(a + 1); ++(i)) {
    if (i * 2 <= b && i * 4 <= c)
      ans = max(ans, i * 7);
    else
      break;
  }
  cout << ans;
}
