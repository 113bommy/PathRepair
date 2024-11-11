#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, x = 0, m;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> m;
    x++;
  }
  x = x + ((n - 1) * 10);
  if (x > d)
    cout << -1 << endl;
  else {
    int y;
    y = (n - 1) * 2;
    y = y + ((d - x) / 5);
    cout << y << endl;
  }
  return 0;
}
