#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, ans = 0, curr = 0, i, a, b;
  cin >> n >> x;
  for (i = 0; i < n && cin >> a >> b; curr = b, i++)
    ans += (a - curr) % x + (b - a + 1) + (int)((a - curr) % x == 0) * x;
  cout << ans << "\n";
  return 0;
}
