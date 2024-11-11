#include <bits/stdc++.h>
using namespace std;
long long a, b, r, x;
int main() {
  cin >> a;
  b = 45 * 17 * 1000000000000000LL;
  r = 10000000000000000LL - 1;
  x = b % a;
  cout << a - x << " " << a - x + r;
  return 0;
}
