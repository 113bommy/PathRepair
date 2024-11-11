#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = a / c;
    if (a % c != 0) x++;
    int y = d / b;
    if (d % b != 0) y++;
    if (x + y <= k)
      cout << x << " " << y << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
