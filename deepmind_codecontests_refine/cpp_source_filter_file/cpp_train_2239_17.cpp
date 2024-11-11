#include <bits/stdc++.h>
using namespace std;
int main() {
  int d1, d2, d3;
  int x, y, z, o;
  cin >> d1;
  cin >> d2;
  cin >> d3;
  x = d1 * 2 + d2 * 2;
  y = d1 + d3 + d2;
  z = d1 * 2 + d3 * 2;
  o = d2 * 2 + d3 * 2;
  min(x, y);
  min(z, o);
  min(min(x, y), min(z, o));
}
