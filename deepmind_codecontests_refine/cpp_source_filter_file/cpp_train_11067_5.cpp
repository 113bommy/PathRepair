#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x0;
  cin >> n >> x0;
  int x = x0;
  int a[n][2];
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
  int c = 0, d = 0;
  for (int i = 0; i < n; i++) {
    if (min(a[i][0], a[i][1]) > x) {
      x = min(a[i][0], a[i][1]);
      c++;
    } else if (max(a[i][0], a[i][1]) < x) {
      d++;
      x = max(a[i][0], a[i][1]);
    }
    if (c > 0 && d > 0) break;
  }
  if (c > 0 && d > 0)
    cout << "-1\n";
  else {
    c = 0;
    for (int i = 0; i < n; i++) {
      if (x0 >= min(a[i][0], a[i][1]) && x0 <= max(a[i][0], a[i][1])) c++;
    }
    if (c == n)
      cout << abs(x - x0) << endl;
    else
      cout << "-1\n";
  }
}
