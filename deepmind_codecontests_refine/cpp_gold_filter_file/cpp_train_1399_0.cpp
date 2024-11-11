#include <bits/stdc++.h>
using namespace std;
int x, y;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> y;
  double dist = sqrt((x * x + y * y));
  if ((y >= 0 && x >= 0) || (y < 0 && x < 0)) {
    if (int(dist) % 2 && int(dist) != dist)
      return cout << "white", 0;
    else
      return cout << "black", 0;
  } else {
    if (int(dist) % 2 || int(dist) == dist)
      return cout << "black", 0;
    else
      return cout << "white", 0;
  }
  return 0;
}
