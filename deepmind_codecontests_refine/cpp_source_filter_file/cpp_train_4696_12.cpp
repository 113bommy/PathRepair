#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
const double PI = acos(-1);
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 11;
long long a, b, x, y, ans = 0;
int main(int argc, char const *argv[]) {
  cin >> a >> b >> x >> y;
  long long t = gcd(x, y);
  x /= t;
  y /= t;
  cout << min(a / x, b / x) << endl;
  return 0;
}
