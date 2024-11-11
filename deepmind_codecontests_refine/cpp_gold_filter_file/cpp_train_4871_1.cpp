#include <bits/stdc++.h>
using namespace std;
long long x, y;
int main() {
  cin >> x >> y;
  if (x == 1 || y == 1) cout << 1 << endl;
  else cout << x * y / 2 + (x * y & 1) << endl;
}
