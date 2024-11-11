#include <bits/stdc++.h>
using namespace std;
int main() {
  int c1, c2, c3, c4, n, m;
  cin >> c1 >> c2 >> c3 >> c4;
  cin >> n >> m;
  int a[1000], b[1000];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 0; j < m; j++) cin >> b[j];
  int min;
  min = c4;
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] * c1 < c2)
      x += a[i] * c1;
    else
      x += c2;
  }
  int y = 0;
  for (int i = 0; i < 3; i++) {
    if (b[i] * c1 < c2)
      y += a[i] * c1;
    else
      y += c2;
  }
  if (x > c3) x = c3;
  if (y > c3) y = c3;
  if ((x + y) < min) min = x + y;
  cout << min;
  return 0;
}
