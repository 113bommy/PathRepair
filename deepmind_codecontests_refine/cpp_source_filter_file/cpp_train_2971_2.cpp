#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << (b * d * f > a * c * e || e == 0 && f > 0 || c == 0 && d * f > 0
               ? "Ron\n"
               : "Hermione\n");
  return 0;
}
