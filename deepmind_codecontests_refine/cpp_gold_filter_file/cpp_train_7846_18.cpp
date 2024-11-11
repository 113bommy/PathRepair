#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  if (n % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  n /= 3;
  if (n % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<long long> divisors;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) divisors.push_back(i);
  }
  long long c = 0;
  for (long long r = 1; r * r * r <= n; r++) {
    if (n % r != 0) continue;
    auto it = divisors.begin();
    long long l = *it;
    while (it != divisors.end() && r * l * l <= n) {
      if (l < r) {
        advance(it, 1);
        l = *it;
        continue;
      }
      if (n % (r * l) != 0) {
        advance(it, 1);
        l = *it;
        continue;
      }
      long long t = n / (r * l);
      if (r > l || l > t) {
        advance(it, 1);
        l = *it;
        continue;
      }
      if ((r + l + t) % 2 != 0) {
        advance(it, 1);
        l = *it;
        continue;
      }
      long long u = (r + l + t) / 2;
      long long x = u - t;
      long long y = u - l;
      long long z = u - r;
      if (x > 0 && y > 0 && z > 0) {
        if (x != y && y != z)
          c += 6;
        else if ((x == y && y != z) || (x != y && y == z))
          c += 3;
        else
          c++;
      }
      advance(it, 1);
      l = *it;
    }
  }
  cout << c << endl;
}
