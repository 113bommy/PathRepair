#include <bits/stdc++.h>
using namespace std;
int main() {
  double d, h, v, e;
  cin >> d >> h >> v >> e;
  if (4 * v / ((long double)atan(1.0) * 4 * d * d) - e <= 0)
    printf("NO");
  else {
    printf("YES\n");
    cout << h * ((long double)atan(1.0) * 4 * d * d /
                 (4 * v - (long double)atan(1.0) * 4 * e * d * d));
  }
}
