#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14;
void solution();
int main() {
  int t;
  cin >> t;
  for (int x = 0; x < t; x++) {
    solution();
  }
  return 0;
}
void solution() {
  long long int a, b, c, d;
  long long int x, y, x1, y1, x2, y2;
  cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
  x = x - a + b;
  y = y - a + b;
  if (x >= x1 && x <= x2 && y >= y1 && y <= y2 && (x2 > x1 || a + b == 0) &&
      (y2 > y1 || c + d == 0)) {
    cout << "Yes"
         << "\n";
  } else {
    cout << "No"
         << "\n";
  }
}
