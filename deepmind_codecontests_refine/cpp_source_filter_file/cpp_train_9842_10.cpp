#include <bits/stdc++.h>
using namespace std;
int main() {
  double d, h, v, e, pi = 3.14159265359;
  cin >> d >> h >> v >> e;
  d /= (double)2;
  if ((double)1 / (pi * d * d) <= e)
    return cout << "NO", 0;
  else
    return printf("YES\n%0.11lf", h / (1 / (pi * d * d) - e)), 0;
}
