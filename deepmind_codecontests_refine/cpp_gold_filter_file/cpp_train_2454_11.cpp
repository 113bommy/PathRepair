#include <bits/stdc++.h>
using namespace std;
int a, b, c, x;
int main() {
  cin >> a >> b >> c;
  x = 1;
  while (x * 2 <= b && x * 4 <= c && x <= a) x++;
  cout << 7 * (x - 1) << endl;
  return 0;
}
