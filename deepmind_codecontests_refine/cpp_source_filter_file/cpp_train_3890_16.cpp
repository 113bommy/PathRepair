#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long power(long long x) {
  if (x == 0) return 1;
  if (x == 1) return 3;
  long long tmp = power(x >> 1);
  if (x & 1) return 3 * tmp * tmp;
  return tmp * tmp;
}
int main() {
  cin >> n >> m;
  cout << (power(n) + m - 1) % m << endl;
  return 0;
}
