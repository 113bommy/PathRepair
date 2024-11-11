#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  cin >> a >> b;
  long long c = a * b / gcd(a, b), ti = 0;
  for (long long x = a; x <= c; x += a) {
    long long y = max(x - a, (x - 1) / b * b);
    if (x != c)
      ti += x - y;
    else if (a > b)
      ti += x - y;
  }
  if (ti * 2 == c)
    cout << "Equal" << endl;
  else if (ti * 2 < c)
    cout << "Masha" << endl;
  else
    cout << "Dasha" << endl;
  return 0;
}
