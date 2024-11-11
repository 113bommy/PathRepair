#include <bits/stdc++.h>
using namespace std;
long long a, pax = 1e18 + 1;
int main() {
  cin >> a;
  long long l = a - pax % a * 9 % a * 9 % a, r = pax + l - 1;
  cout << l << r;
  return 0;
}
