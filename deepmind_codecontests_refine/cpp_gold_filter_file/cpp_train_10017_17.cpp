#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, x = 0, y = 0, z = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m;
    z += m;
    if (m % 2 == 0)
      x++;
    else
      y++;
  }
  if (z % 2 == 1)
    cout << y;
  else
    cout << x;
  return 0;
}
