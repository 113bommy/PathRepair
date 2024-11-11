#include <bits/stdc++.h>
using namespace std;
long long a, b, p, x;
int main() {
  cin >> a >> b >> p >> x;
  long long ans = 0, r = b, t, t1;
  for (int i = p - 1; i; i--) {
    if (i <= x) {
      t = (i - r + p) % p, t1 = (x - i) / (p - 1);
      ans += t1 / p + t1 % p >= t;
    }
    r = r * a % p;
  }
  cout << ans;
}
