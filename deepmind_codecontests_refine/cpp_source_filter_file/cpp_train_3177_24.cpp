#include <bits/stdc++.h>
using namespace std;
int i, z, n, m, j, maxi = 0, start, final, mini = 100000000, x, b, a, y,
                   total = 1, c;
char v[1001];
queue<int> q;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed;
  cin >> a >> b >> c;
  cin >> x >> y >> z;
  a -= x;
  b -= y;
  c -= y;
  if (a < 0) {
    x = a * -1;
    a = 0;
  } else
    a /= 2, x = 0;
  if (b < 0) {
    y = b * -1;
    b = 0;
  } else
    b /= 2, y = 0;
  if (c < 0) {
    z = c * -1;
    c = 0;
  } else
    c /= 2, z = 0;
  if (a + b + c < z + x + y) {
    cout << "No";
    return 0;
  }
  cout << "Yes";
  return 0;
}
