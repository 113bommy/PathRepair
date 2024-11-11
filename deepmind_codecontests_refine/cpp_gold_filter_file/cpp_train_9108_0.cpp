#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int l1 = 0, l2 = 0;
  int x1, y1;
  cin >> x1 >> y1;
  for (int i = 1; i < n; i++) {
    int x2, y2;
    cin >> x2 >> y2;
    if (x2 != x1) l1 = abs(x1 - x2);
    if (y2 != y1) l2 = abs(y1 - y2);
  }
  int a = l1 * l2;
  if (a != 0)
    cout << a;
  else
    cout << -1;
  return 0;
}
