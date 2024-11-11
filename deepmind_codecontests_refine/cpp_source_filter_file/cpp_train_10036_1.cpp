#include <bits/stdc++.h>
using namespace std;
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int main() {
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  int s;
  s = gcd(x, y);
  long long t = x * y / s;
  cout << (b / s) - (a - 1) / s << endl;
}
