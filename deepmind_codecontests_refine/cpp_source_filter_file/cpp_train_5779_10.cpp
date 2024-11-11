#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 100, N = 1e6 + 5;
const long long INF = 1e18 + 100, MOD = 1e9 + 7;
long long powmod(long long a, long long b, long long m = MOD) {
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = r * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return r;
}
long long power(long long a, long long b) {
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = r * a;
    a = a * a;
    b >>= 1;
  }
  return r;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long inv(long long a, long long m = MOD) { return powmod(a, m - 2, m); }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
int n;
bool pr[N];
vector<int> ans, prime;
void seive() {
  for (long long i = 2; i < N; ++i) {
    if (pr[i] == 0) {
      prime.push_back(i);
      for (long long j = i * i; j < N; j += i) {
        pr[i] = 1;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0),
      cout << setprecision(10) << fixed;
  ;
  cin >> n;
  seive();
  int rt = sqrt(n);
  for (int i = n; i >= rt; --i) {
    bool ok = 1;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      ans.push_back(i);
      n -= i;
      break;
    }
  }
  for (auto x : prime) {
    if (x <= n) {
      if (n - x == 0 || binary_search(prime.begin(), prime.end(), n - x)) {
        ans.push_back(x);
        if (n - x) ans.push_back(n - x);
        break;
      }
    }
  }
  cout << (int)ans.size() << "\n";
  for (auto x : ans) cout << x << " ";
}
