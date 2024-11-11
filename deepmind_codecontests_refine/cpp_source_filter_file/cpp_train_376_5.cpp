#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
  cin >> a >> b;
  int i, ans;
  int z = max(a, b);
  int x = min(a, b);
  i = 1;
  while (1) {
    x++;
    ans = ans + i;
    if (z == x) {
      cout << ans - 1;
      return 0;
    }
    z--;
    ans += i;
    if (z == x) {
      cout << ans - 1;
      return 0;
    }
    i++;
  }
  return 0;
}
