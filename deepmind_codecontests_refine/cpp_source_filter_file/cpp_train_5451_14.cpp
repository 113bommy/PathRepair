#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long ans = 0, x, y, z, x1, y1, z1, a1, a2, a3, a4, a5, a6;
  cin >> x >> y >> z;
  cin >> x1 >> y1 >> z1;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  if (x < 0) {
    ans += a5;
  }
  if (x >= x1) {
    ans += a6;
  }
  if (y < 0) {
    ans += a1;
  }
  if (y >= y1) {
    ans += a2;
  }
  if (z < 0) {
    ans += a3;
  }
  if (z >= z1) {
    ans += a4;
  }
  cout << ans;
  return 0;
}
