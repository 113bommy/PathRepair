#include <bits/stdc++.h>
using namespace std;
int c[10000005];
long long prime[664580];
long long factorial(int n) {
  if (n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}
int GCD(int a, int b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
int main() {
  int r1, r2, c1, c2, rook = 0, bishop = 0, king = 0, t1, t2;
  cin >> r1 >> c1 >> r2 >> c2;
  t1 = fabs(r1 - c1);
  t2 = fabs(r2 - c2);
  king = max(fabs(r1 - r2), fabs(c1 - c2));
  if (t1 % 2 == 0 && t2 % 2 == 1 || t2 % 2 == 0 && t1 % 2 == 1)
    bishop = 0;
  else if ((r1 - c1) == (r2 - c2) || (r1 + c1) == (r2 + c2))
    bishop = 1;
  else
    bishop = 2;
  if ((r1 == r2 && c1 != c2) || (c1 == c2 && r1 != r2))
    rook = 1;
  else
    rook = 2;
  cout << rook << " " << bishop << " " << king;
  return 0;
}
