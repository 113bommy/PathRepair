#include <bits/stdc++.h>
long long pi = acos(-1);
long long z = 1000000007;
long long inf = 100000000000000000;
long long p1 = 37;
long long p2 = 53;
long long mod1 = 202976689;
long long mod2 = 203034253;
long long gcd(long long a, long long b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long c = power(a, b / 2, p);
  if (b % 2 == 0)
    return ((c * c) % p);
  else
    return ((((c * c) % p) * a) % p);
}
long long inverse(long long a, long long n) { return power(a, n - 2, n); }
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long left(long long i) { return ((2 * i) + 1); }
long long right(long long i) { return (2 * (i + 1)); }
using namespace std;
long long cnt[200005], pre[200005];
void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  if ((a / b) <= 1) {
    cout << "Marsel" << '\n';
    return;
  }
  if (n % 2 == 0) {
    cout << "Marsel" << '\n';
  } else {
    long long fact = 0;
    for (long long i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        fact = a / i;
        break;
      }
    }
    if (fact >= b || b == 1)
      cout << "Timur" << '\n';
    else
      cout << "Marsel" << '\n';
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
