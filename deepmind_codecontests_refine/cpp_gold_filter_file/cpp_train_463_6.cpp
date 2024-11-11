#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  cout << ceil((double(sqrt((b - d) * (b - d) + (c - e) * (c - e))) / (2 * a)));
  return 0;
}
