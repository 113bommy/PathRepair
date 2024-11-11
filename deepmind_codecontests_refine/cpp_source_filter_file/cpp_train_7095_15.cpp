#include <bits/stdc++.h>
using namespace std;
int n, a, b, x, y;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a >> x >> b >> y;
  while (a != x && b != y) {
    ++a;
    if (a == n + 1) {
      a = 1;
    }
    --b;
    if (b == n - 1) {
      b = n;
    }
    if (a == b) {
      return 0 * puts("YES");
    }
  }
  return 0 * puts("NO");
}
