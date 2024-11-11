#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, z, x;
  scanf("%lld%lld", &n, &m);
  long long s = abs(n - m);
  if (s % 2 == 0) {
    x = s / 2;
    z = 2 * ((x * x - 1) / 2);
  } else {
    x = s / 2;
    z = (2 * ((x * x - 1) / 2)) + x + 1;
  }
  cout << z << endl;
  return 0;
}
