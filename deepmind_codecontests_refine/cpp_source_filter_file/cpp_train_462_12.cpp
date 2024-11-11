#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int r, x1, y1, x2, y2;
  cin >> r >> x1 >> y1 >> x2 >> y2;
  long double dis = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  int a = (dis / r) / 2;
  if (int(dis) % r == 0 && int(dis) == dis)
    cout << a << '\n';
  else
    cout << a + 1 << '\n';
  return 0;
}
