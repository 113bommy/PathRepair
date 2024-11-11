#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long x;
  cin >> x;
  vector<long long> primes;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      while (x % i == 0) {
        x /= i;
        primes.push_back(i);
      }
    }
  }
  if (x != 1) primes.push_back(x);
  if ((long long)primes.size() <= 1) {
    cout << "1\n0\n";
    return 0;
  }
  if ((long long)primes.size() == 2) {
    cout << "2\n";
    return 0;
  }
  cout << "1\n";
  long long ans = primes[0] * primes[1];
  ;
  cout << ans << '\n';
}
