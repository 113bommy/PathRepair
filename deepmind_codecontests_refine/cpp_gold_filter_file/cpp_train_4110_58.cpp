#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c, d, x, y;
  cin >> a >> b >> c >> d;
  x = max(3 * a / 10, ((250 * a) - (a * c)) / 250);
  y = max(3 * b / 10, ((250 * b) - (b * d)) / 250);
  if (x == y) {
    cout << "Tie\n";
  } else if (x > y) {
    cout << "Misha\n";
  } else {
    cout << "Vasya\n";
  }
  return 0;
}
