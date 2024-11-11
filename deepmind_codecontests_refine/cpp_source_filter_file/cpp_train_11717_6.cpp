#include <bits/stdc++.h>
using namespace std;
long long put(long long x, long long p);
int main() {
  int n;
  cin >> n;
  long long a, p = 2, invmod3, invmod2;
  invmod3 = put(3, 1000000009 - 2);
  invmod2 = put(2, 1000000009 - 2);
  bool par = 0;
  while (n--) {
    cin >> a;
    if (!(a & 1)) par = 1;
    p = put(p, a);
    p %= 1000000009;
  }
  p *= invmod2;
  p %= 1000000009;
  long long sus = p, jos = p;
  if (par)
    sus += 1;
  else
    sus -= 1;
  sus *= invmod3;
  sus %= 1000000009;
  cout << sus << '/' << jos;
  return 0;
}
long long put(long long x, long long p) {
  if (p == 0) return 1;
  long long a = put(x, p / 2);
  a *= a;
  a %= 1000000009;
  if (p & 1) a *= x;
  return (a % 1000000009);
}
