#include <bits/stdc++.h>
using namespace std;
int x, y, z, a, b, c;
int main() {
  cin >> x >> y >> z >> a >> b >> c;
  if (a < x) return cout << "NO", 0;
  a -= x;
  if (a + b < y) return cout << "NO", 0;
  int p = a + b + c;
  p -= y;
  if (c < z) return cout << "NO", 0;
  cout << "YES" << endl;
  return 0;
}
