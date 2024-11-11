#include <bits/stdc++.h>
using namespace std;
vector<long long int> getPrimes(long long int n) {
  bool prime[n + 1];
  vector<long long int> primes;
  for (long long int p = 2; p * p <= n; p++)
    if (!prime[p])
      for (long long int i = p * p; i <= n; i += p) prime[i] = true;
  for (long long int p = 2; p <= n; p++)
    if (!prime[p]) primes.push_back(p);
  return primes;
}
int main() {
  long long int t, i, j, temp, last, ans, en = 1000000000000000000, g;
  vector<long long int> primes = getPrimes(100);
  long long int l = primes.size();
  vector<pair<long long int, pair<long long int, long long int>>> elem;
  cin >> t;
  while (t--) {
    ans = 1;
    i = 22;
    j = 0;
    temp = last = 1;
    while (i--) {
      while (j < l && (en / temp) >= primes[j]) temp *= primes[j++];
      cout << "? " << temp << "\n" << flush;
      cin >> g;
      if (g == last)
        ans *= g, temp = 1;
      else
        temp = g * g;
      last = g;
      g = 1;
    }
    g *= ans;
    ans = 1;
    for (i = 0; i < j; i++) {
      temp = 1;
      while ((g % primes[i]) == 0) temp++, g /= primes[i];
      ans *= temp;
    }
    ans *= 2ll;
    cout << "! " << ans << "\n" << flush;
  }
  return 0;
}
