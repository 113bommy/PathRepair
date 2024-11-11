#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, bx, m, by;
  cin >> n >> bx;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << endl;
  cin >> m >> by;
  int b[m];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long int x = 0, y = 0, p = 1, p1 = 1;
  for (int i = 0; i < max(n, m); i++) {
    if (i < n) {
      x += a[n - 1 - i] * p;
      p *= bx;
    }
    if (i < m) {
      y += b[n - 1 - i] * p1;
      p1 *= by;
    }
  }
  if (x - y < 0)
    cout << "<";
  else if (x - y > 0)
    cout << ">";
  else
    cout << "=";
  return 0;
}
