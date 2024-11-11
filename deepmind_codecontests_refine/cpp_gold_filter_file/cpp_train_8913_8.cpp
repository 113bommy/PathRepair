#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  cin >> n;
  int a[n];
  x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1)
      x++;
    else
      y++;
  }
  if (x == 0)
    cout << 0 << endl;
  else if (y == 0)
    cout << x / 3 << endl;
  else if (y >= x)
    cout << x << endl;
  else
    cout << y + (x - y) / 3 << endl;
  return 0;
}
