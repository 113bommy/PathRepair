#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long a, x;
  unsigned long long b = 45 * 17 * 10000000000000000LL;
  unsigned long long r = 100000000000000000LL - 1;
  cin >> a;
  x = b % a;
  cout << a + x + 1 << " " << a + x + r << endl;
  return 0;
}
