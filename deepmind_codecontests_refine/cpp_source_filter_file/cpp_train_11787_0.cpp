#include <bits/stdc++.h>
using namespace std;
double PI = (acos(-1));
long long md = 1000000007;
long long pw(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m);
    m = (m * m);
    b /= 2;
  }
  return c;
}
long long pwmd(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = ((c * m)) % md;
    m = (m * m) % md;
    b /= 2;
  }
  return c;
}
long long modinv(long long n) { return pwmd(n, md - 2); }
long long nc2(long long n) { return (1ll * n * (n - 1)) / 2; }
bool prime(long long a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) return false;
  }
  return true;
}
long long ceel(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
void Sieve(vector<int> &primes) {
  bool IsPrime[1000005];
  memset(IsPrime, true, sizeof(IsPrime));
  for (int p = 2; p * p < 1000005; p++) {
    if (IsPrime[p] == true) {
      for (int i = p * p; i < 1000005; i += p) IsPrime[i] = false;
    }
  }
  for (int p = 2; p < 1000005; p++)
    if (IsPrime[p]) primes.push_back(p);
}
void solve() {
  long long n;
  cin >> n;
  long long l[n];
  for (long long i = 0; i < n; i++) cin >> l[i];
  vector<long long> v(n + 2, 0), p(n + 2, 0);
  for (long long i = 0; i < n; i++) v[l[i]]++, p[l[i]]++;
  long long cur = 0, ans = 0;
  for (long long i = 1; i < n + 1; i++) {
    if (v[i] == 0) {
      if (v[i + 1]) v[i]++, v[i + 1]--, cur++;
    } else if (v[i] == 1)
      cur++;
    else
      v[i + 1]++, cur++;
  }
  for (long long i = 1; i < n + 1; i++) {
    if (p[i]) ans++, i += 2;
  }
  cout << ans << " " << cur;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  while (tests--) {
    solve();
  }
  return 0;
}
