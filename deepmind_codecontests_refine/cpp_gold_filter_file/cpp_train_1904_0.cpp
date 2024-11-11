#include <bits/stdc++.h>
using namespace std;
long long int mod1 = 1000000007;
long long int mod2 = 67280421310721;
long long int mod3 = 998244353;
long long int INF = 1e18;
long long int binpow1(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int binpow2(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
map<long long int, long long int> fact(long long int n) {
  map<long long int, long long int> factorization;
  long long int c = 0;
  while (n % 2 == 0) {
    c++;
    n /= 2;
  }
  if (c > 0) {
    factorization.insert({2, c});
  }
  c = 0;
  for (long long int d = 3; d * d <= n; d += 2) {
    while (n % d == 0) {
      c++;
      n /= d;
    }
    if (c > 0) {
      factorization.insert({d, c});
    }
    c = 0;
  }
  if (n > 1) {
    factorization.insert({n, 1});
  }
  return factorization;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    set<long long int> s;
    long long int f = 0;
    long long int sum = 0;
    long long int a[n];
    for (int i = (1); i < (n + 1); i++) {
      s.insert(i);
    }
    for (int i = (0); i < (n); i++) {
      cin >> a[i];
      sum = sum + a[i];
    }
    if (sum != m) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
  return 0;
}
