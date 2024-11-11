#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, t, sum, y, x;
  cin >> n;
  int a[n], p[n];
  sum = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    cin >> p[i];
  }
  for (i = 0; i < n;) {
    x = 1;
    y = a[i];
    t = i;
    while (p[t] < p[t + 1] && t + 1 < n) {
      x++;
      y += a[t + 1];
      t++;
    }
    sum += y * p[i];
    i += x;
  }
  cout << sum << "\n";
  return 0;
}
