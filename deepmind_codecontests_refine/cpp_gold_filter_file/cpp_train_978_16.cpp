#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  if (a >= mod) a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= mod) res %= mod;
    a = a * a;
    if (a >= mod) a %= mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int c[9000 + 5];
long long a[1000000 + 5];
vector<long long> d;
int main() {
  srand(time(NULL));
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  long long ans = 1;
  for (int ii = 0; ii < min(n, 12); ii++) {
    long long x = a[rand() * rand() % n];
    d.clear();
    for (long long j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        d.push_back(j);
        if (j * j != x) d.push_back(x / j);
      }
    }
    sort(d.begin(), d.end());
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; i++)
      c[lower_bound(d.begin(), d.end(), gcd(a[i], x)) - d.begin()]++;
    for (int i = 0; i < d.size(); i++)
      for (int j = 0; j < i; j++) {
        if (d[i] % d[j] == 0) c[j] += c[i];
      }
    for (int i = 0; i < d.size(); i++) {
      if (c[i] * 2 >= n) ans = max(ans, d[i]);
    }
  }
  cout << ans << '\n';
  cin.get();
  cin.get();
  return 0;
}
