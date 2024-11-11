#include <bits/stdc++.h>
using namespace std;
const long long maxN = 1e6 + 5;
const long long inf = 1e10;
const long long mod = 1e9 + 7;
long long n, x;
vector<long long> v;
bool isPrime(long long n) {
  if (n == 0 || n == 1) return false;
  if (n == 2 || n == 3) return true;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long check(long long base, long long p, long long mod) {
  long long res = 1;
  long long p2 = base;
  for (long long i = 0; i <= 22; i++) {
    if (p & (1 << i)) res = (res * p2) % mod;
    p2 = (p2 * p2) % mod;
  }
  return res;
}
bool solve(long long base) {
  for (long long i = 0; i <= v.size() - 1; i++) {
    if (check(base, v[i], n + 1) == 1) return false;
  }
  return (check(base, n, n + 1) == 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> x;
  if (n == 1) {
    if (x == 2) {
      cout << -1;
      return 0;
    }
    cout << x - 1;
    return 0;
  }
  if (!isPrime(n + 1)) {
    cout << -1;
    return 0;
  }
  for (long long i = 1; i <= n - 1; i++) {
    if (x % i == 0) v.push_back(i);
  }
  for (long long i = x - 1; i >= 2; i--) {
    if (solve(i)) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
