#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5;
long long n, p, d, w;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> p >> w >> d;
  long long l = gcd(w, d);
  if (p % l != 0) {
    cout << -1 << endl;
    return 0;
  } else {
    long long i = 0, sum = p % w;
    while (sum <= p) {
      if (sum % d == 0) {
        long long x = p / w - i;
        long long y = sum / d;
        long long z = n - x - y;
        if (z < 0) {
          cout << -1 << endl;
          return 0;
        }
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
      sum += w;
      i++;
    }
    cout << -1 << endl;
    return 0;
  }
}
