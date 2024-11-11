#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  int x, y, z, w;
  int a[4];
  cin >> n;
  if (n == 0) {
    cout << "YES\n";
    cout << "1\n1\n3\n3\n";
  }
  if (n == 1) {
    cin >> x;
    cout << "YES\n" << x << "\n" << x << "\n" << 3 * x << "\n";
  }
  if (n == 4) {
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    if ((a[3] == 3 * a[0]) && ((a[3] + a[0]) == (a[1] + a[2]))) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  if (n == 2) {
    cin >> x >> y;
    if (x > y) {
      int temp = x;
      x = y;
      y = temp;
    }
    if ((3 * x) < y) {
      cout << "NO\n";
    } else {
      cout << "YES\n" << 3 * x << "\n" << 4 * x - y << "\n";
    }
  }
  if (n == 3) {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if ((3 * a[0]) < (a[2])) {
      cout << "NO\n";
    } else {
      a[3] = 3 * a[0];
      if ((a[3] == 3 * a[0]) && ((a[3] + a[0]) == (a[1] + a[2]))) {
        cout << "YES\n";
        cout << a[3] << "\n";
        return 0;
      }
      a[3] = a[2] / 3;
      if ((a[2] == 3 * a[3]) && ((a[3] + a[2]) == (a[1] + a[0]))) {
        cout << "YES\n";
        cout << a[3] << "\n";
        return 0;
      }
      a[3] = a[0] + a[2] - a[1];
      if ((a[2] == 3 * a[0]) && ((a[0] + a[2]) == (a[1] + a[3]))) {
        cout << "YES\n";
        cout << a[3] << "\n";
        return 0;
      } else {
        cout << "NO\n";
      }
    }
  }
}
