#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d, x[5], y[5];
  cin >> n;
  if (n == 1) {
    cin >> a >> b;
    cout << -1;
  } else if (n == 2) {
    cin >> a >> b >> c >> d;
    if (a == c || b == d)
      cout << -1;
    else
      cout << abs(a - c) * abs(b - d);
  } else {
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++)
      for (int j = i + 1; i < n; i++)
        if (x[i] != x[j] && y[i] != y[j]) {
          cout << abs(x[i] - x[j]) * abs(y[i] - y[j]);
          return 0;
        }
  }
}
