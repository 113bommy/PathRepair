#include <bits/stdc++.h>
using namespace std;
int conversion(string p) {
  int o;
  o = atoi(p.c_str());
  return o;
}
string toString(int h) {
  stringstream ss;
  ss << h;
  return ss.str();
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
long long toi(string p) {
  long long x;
  istringstream in(p);
  in >> x;
  return x;
}
int main() {
  int a, b, c, d, x, y, ab;
  cin >> a >> b >> c >> d >> x >> y;
  ab = min(a, min(b, min(c, d)));
  if (x <= ab && y <= ab)
    cout << abs(x - y) + 1 << endl;
  else if (x > ab)
    cout << 0 << endl;
  else
    cout << abs(x - ab) << endl;
}
