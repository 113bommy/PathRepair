#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (a == 0 ? b : gcd(b % a, a)); }
long long phi(long long n) {
  long long ans = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans -= (ans / i);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) ans -= ans / n;
  return ans;
}
const int INF = 1e9 + 7;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    long long a, m;
    cin >> a >> m;
    cout << (phi(m / gcd(a, m))) << '\n';
  }
  return 0;
}
