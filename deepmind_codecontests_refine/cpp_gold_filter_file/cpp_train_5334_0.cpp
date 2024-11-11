#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t, n, i, j;
  cin >> t;
  while (t--) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int u, v, x1, y1, x2, y2;
    cin >> u >> v >> x1 >> y1 >> x2 >> y2;
    long long int d1 = a - b, d2 = c - d;
    if (d1 >= 0) {
      if (((u - d1) < x1)) {
        cout << "NO\n";
        continue;
      }
    }
    if (d1 < 0) {
      if (x2 < (u - d1)) {
        {
          cout << "NO\n";
          continue;
        }
      }
    }
    if (d2 >= 0) {
      if (y1 > (v - d2)) {
        cout << "NO\n";
        continue;
      }
    }
    if (d2 < 0) {
      if ((y2 < (v - d2))) {
        cout << "NO\n";
        continue;
      }
    }
    if ((x1 == x2) && (a || b)) {
      cout << "NO\n";
      continue;
    }
    if ((y1 == y2) && (c || d)) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
}
