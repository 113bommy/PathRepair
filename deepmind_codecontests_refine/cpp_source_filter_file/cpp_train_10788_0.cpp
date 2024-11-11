#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, k, l, n, m, p, x, y, z, t;
  cin >> t;
  int a1 = 0, a2 = 0;
  while (t--) {
    cin >> x >> y;
    if (x > 0 && y > 0)
      a1++;
    else
      a2++;
  }
  if (a1 <= 1 || a2 <= 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
