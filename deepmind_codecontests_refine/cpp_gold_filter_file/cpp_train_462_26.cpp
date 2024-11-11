#include <bits/stdc++.h>
using namespace std;
double r, x, y, c, d, dist;
int main() {
  srand(time(NULL));
  cin >> r >> x >> y >> c >> d;
  double dist = sqrt((x - c) * (x - c) + (y - d) * (y - d)) / (2. * r) * 1.;
  if (dist - (int)(dist) == 0)
    cout << (int)(dist);
  else
    cout << (int)(dist) + int(1);
}
