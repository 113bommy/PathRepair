#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, k, sum = 0;
  cin >> x >> y >> z >> z;
  if (x == y || x == z || x == k) sum++;
  if (y == z || y == k) sum++;
  if (z == k) sum++;
  cout << sum;
  return 0;
}
