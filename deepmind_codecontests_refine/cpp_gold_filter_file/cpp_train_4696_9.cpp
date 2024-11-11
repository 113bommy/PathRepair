#include <bits/stdc++.h>
using namespace std;
const int N = 0;
int n, k, x, t;
string s;
vector<int> v;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long gd = gcd(c, d);
  c /= gd;
  d /= gd;
  cout << min(a / c, b / d);
  return 0;
}
