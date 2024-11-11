#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  long long int r;
  while (b != 0) r = a % b, a = b, b = r;
  return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int a, b, x, y;
  cin >> a >> b >> x >> y;
  long long int ans = 0;
  long long int g = gcd(x, y);
  x /= g;
  y /= g;
  long long int l = 1, r = 100000000000ll;
  for (int i = 0; i < 70; i++) {
    long long int m = l + (r - l) / 2;
    if (m == 119) {
    }
    if (x * m <= a && y * m <= b) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << x * ans << " " << y * ans << '\n';
  return 0;
}
