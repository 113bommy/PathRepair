#include <bits/stdc++.h>
using namespace std;
bool isPrime[1000005] = {false};
vector<long long> prm;
vector<long long> SPF(1000005);
void sieve() {
  isPrime[1] = isPrime[0] = 0;
  long long i;
  for (i = 2; i < 1000005; ++i) isPrime[i] = 1;
  for (i = 2; i * i < 1000005; ++i) {
    if (isPrime[i]) {
      for (long long j = i * i; j < 1000005; j += i) isPrime[j] = 0;
    }
  }
  if (!prm.empty()) prm.clear();
  for (i = 2; i < 1000005; ++i) {
    if (isPrime[i]) prm.push_back(i);
  }
}
bool flip(bool f) {
  if (f) return 0;
  return 1;
}
long long fastPower(long long a, long long b) {
  if (b == 0) return 1;
  long long prod = 1;
  while (b > 0) {
    if (b & 1) prod = prod * a;
    b = b >> 1;
    a = a * a;
  }
  return prod;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) {
    res *= i;
  }
  return res;
}
long long nCr(long long n, long long r) {
  return (long double)fact(n) / (long double)(fact(r) * fact(n - r));
}
void solve() {
  long long n, i;
  cin >> n;
  vector<long long> a(n);
  for (i = 0; i < n; ++i) cin >> a[i];
  for (i = 0; i < n; ++i) {
    if (a[i] != 1) break;
  }
  string ans = ((i == n) ^ (i & 1)) ? "Second" : "First";
  cout << ans << "\n";
}
int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
