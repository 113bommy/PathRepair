#include <bits/stdc++.h>
using namespace std;
int n, m;
long long pow(int x) {
  if (x == 0)
    return 1;
  else if (x & 1)
    return (3 * pow(x - 1)) % m;
  else {
    long long y = pow(x / 2);
    return (y * y) % m;
  }
}
int main() {
  cin >> n >> m;
  long long x = pow(n) - 1;
  if (x == -1) x = m;
  cout << x;
  return 0;
}
