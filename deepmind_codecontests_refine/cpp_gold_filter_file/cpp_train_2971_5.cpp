#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << (b * d * f > a * c * e || c == 0 && d > 0 || a == 0 && b * d > 0
               ? "Ron\n"
               : "Hermione\n");
  return 0;
}
