#include <bits/stdc++.h>
using namespace std;
long long con, a, b, m;
int main() {
  con = 0;
  cin >> a >> b >> m;
  if (m == 0) {
    if (a * b > 0) {
      cout << -1 << endl;
      return 0;
    } else {
      cout << 0 << endl;
      return 0;
    };
  } else if (m > 0) {
    if (a > b) swap(a, b);
    if (a <= 0 && b <= 0) {
      cout << -1 << endl;
      return 0;
    };
    if (b >= m) {
      cout << 0 << endl;
      return 0;
    };
    if (a < 0) con = ceil(a * -1.0 / b), a += b * con;
    if (a > b) swap(a, b);
    while (b < m) {
      long long tmp = a + b;
      a = b;
      b = tmp;
      con++;
    }
    cout << con << endl;
  } else if (m > 0) {
    if (a < m && b < m) {
      cout << -1 << endl;
      return 0;
    } else {
      cout << 0 << endl;
      return 0;
    };
  }
}
