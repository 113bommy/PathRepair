#include <bits/stdc++.h>
using namespace std;
long long DBD(long long sk1, long long sk2) {
  if (sk2 == 0)
    return sk1;
  else
    return DBD(sk2, sk1 % sk2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long ans = 0, x, y, m, g, op, q, tmp, i;
  cin >> x >> y;
  vector<long long> primes;
  tmp = x;
  for (i = 2; i * i <= x; i++) {
    if (tmp % i == 0) primes.push_back(i);
    while (tmp % i == 0) {
      tmp /= i;
    }
  }
  if (tmp != 1) primes.push_back(tmp);
  if (x == 1) {
    cout << y;
    return 0;
  }
  while (true) {
    g = DBD(x, y);
    m = 1e13;
    for (auto k : primes) {
      op = y;
      q = y / (k * g);
      q *= (k * g);
      op -= q;
      op /= g;
      if (x % (k * g) == 0 && op < m) {
        m = op;
      }
    }
    if (m != 1e13) {
      ans += m;
      y -= m * g;
    } else {
      ans += (y / g);
      break;
    }
    if (y == 0) break;
  }
  cout << ans;
  return 0;
}
