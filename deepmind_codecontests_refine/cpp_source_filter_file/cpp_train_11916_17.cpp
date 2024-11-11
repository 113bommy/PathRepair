#include <bits/stdc++.h>
using namespace std;
long long a, b, r, x;
int main() {
  cin >> a;
  b = 45 * 18 * 100000000000000000LL;
  r = 100000000000000000LL - 1;
  x = b % a;
  cout << a - x + 1 << " " << a - x + r;
  return 0;
}
