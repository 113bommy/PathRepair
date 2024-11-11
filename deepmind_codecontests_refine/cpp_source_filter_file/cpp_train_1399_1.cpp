#include <bits/stdc++.h>
using namespace std;
int main() {
  long double x, y;
  cin >> x >> y;
  long double dist = sqrt(x * x + y * y);
  dist = fmod(dist, 2);
  if ((x >= 0 && y >= 0) || (x <= 0 && y <= 0)) {
    if (dist >= 0 && dist <= 1)
      cout << "black";
    else
      cout << "white";
  } else {
    if (dist >= 0 && dist <= 1)
      cout << "white";
    else
      cout << "black";
  }
  return 0;
}
