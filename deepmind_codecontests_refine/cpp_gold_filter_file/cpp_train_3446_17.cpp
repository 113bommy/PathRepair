#include <bits/stdc++.h>
using namespace std;
const long double sqr5 = sqrt(5), p_ = (1 + sqr5) / 2;
long double tavan(long double a, long long b) {
  return b ? (tavan(a * a, b >> 1) * (b & 1 ? a : 1)) : 1;
}
long double fib(long long x) {
  return (tavan(p_, x) - tavan(1 - p_, x)) / sqr5;
}
long long gcd(long long a, long long b) {
  return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));
}
bool isprime(long long x) {
  for (long long i = 2; i <= sqrt(x); i++)
    if (!(x % i)) return false;
  return true;
}
ifstream fin("input.txt");
ofstream fout("output.txt");
long long n, cow[(301 * 1000)], p, dp[(301 * 1000)], ans[(301 * 1000)];
pair<pair<long long, long long>, long long> pir[(301 * 1000)];
const long long sqr = sqrt((301 * 1000));
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> cow[i];
  cin >> p;
  for (int i = 0; i < p; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    pir[i].first.second = a;
    pir[i].first.first = b;
    pir[i].second = i;
  }
  sort(pir, pir + p);
  for (int i = 0; i < p; i++) {
    long long a = pir[i].first.second, b = pir[i].first.first,
              j = pir[i].second;
    if (b >= sqr)
      for (int k = a; k < n; k += b) ans[j] += cow[k];
    else {
      if (i == 0 || b != pir[i - 1].first.first)
        for (int k = n - 1; k >= 0; k--) {
          if (b + k >= n)
            dp[k] = cow[k];
          else
            dp[k] = cow[k] + dp[b + k];
        }
      ans[j] = dp[a];
    }
  }
  for (int i = 0; i < p; i++) cout << ans[i] << "\n";
  return 0;
}
