#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265359;
inline long long add(long long a, long long b, long long m) {
  if ((a + b) >= m) return (a + b) % m;
  return a + b;
}
inline long long mul(long long a, long long b, long long m) {
  if ((a * b) < m) return a * b;
  return (a * b) % m;
}
long long power(long long x, long long y, long long m) {
  long long res = 1;
  x = x % m;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % m;
    y = y >> 1;
    x = (x * x) % m;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio;
  cin.tie(0);
  cout.tie(0);
  int t = 1, n, a, b, x, y;
  while (t--) {
    cin >> n >> a >> b;
    int l = 0, r = 0, u = 0, d = 0;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      if (x < a) {
        l++;
      }
      if (x > a) {
        r++;
      }
      if (y < b) {
        d++;
      }
      if (y > b) {
        u++;
      }
    }
    int ans = 0, ans1 = 0, ans2 = 0;
    if (ans < l && a > 0) {
      ans = l;
      ans1 = a - 1;
      ans2 = b;
    }
    if (ans < r && a < 1000000000) {
      ans = r;
      ans1 = a + 1;
      ans2 = b;
    }
    if (ans < u && b < 1000000000) {
      ans = u;
      ans1 = a;
      ans = b + 1;
    }
    if (ans < d && b > 0) {
      ans = d;
      ans1 = a;
      ans2 = b - 1;
    }
    cout << ans << endl << ans1 << " " << ans2 << endl;
  }
  return 0;
}
