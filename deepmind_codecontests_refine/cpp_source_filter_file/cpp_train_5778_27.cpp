#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f, nb = 0;
  cin >> a >> b >> c >> d >> e >> f;
  nb += a * b * 2;
  nb += c * d * 2;
  nb += e * f * 2;
  nb += abs((b - a) * (d - c));
  cout << nb << endl;
}
