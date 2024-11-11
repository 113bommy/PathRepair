#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long int k;
  cin >> k;
  int x;
  x = 0;
  int y;
  y = 0;
  for (int i = 1; i <= n; i++) {
    if (k > (i - 1) * 2 * m && k <= i * 2 * m) {
      x = i;
      break;
    }
  }
  for (int j = 0; j < n; j++) {
    for (int d = 1; d <= m; d++) {
      if (k == 2 * j * m + 2 * d or k == 2 * j * m + 2 * d - 1) {
        y = d;
        break;
      }
    }
  }
  string s;
  if (k % 2 == 0) {
    s = "R";
  } else {
    s = "L";
  }
  cout << x << " " << y << " " << s;
  return 0;
}
