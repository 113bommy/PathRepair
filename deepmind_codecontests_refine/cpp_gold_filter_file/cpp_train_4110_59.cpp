#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int N = 1001000;
int a, b, c, d;
int main() {
  cin >> a >> b >> c >> d;
  int k1 = max(3 * a / 10, a - a * c / 250);
  int k2 = max(3 * b / 10, b - b * d / 250);
  if (k1 > k2)
    cout << "Misha";
  else if (k1 == k2)
    cout << "Tie";
  else
    cout << "Vasya";
  return 0;
}
