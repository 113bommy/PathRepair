#include <bits/stdc++.h>
const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
using namespace std;
int popcount(int n) {
  bitset<32> b(n);
  return b.count();
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int r, x, y, xd, yd;
  cin >> r >> x >> y >> xd >> yd;
  long double dis = sqrt((xd - x) * (xd - x) + (yd - y) * (yd - y));
  cout << ceil(dis / (2 * r)) << endl;
  return 0;
}
