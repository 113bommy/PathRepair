#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;
using ld = long double;
const int N = 1e5 + 5, inf = 2e9;
ll q, x;
vector<ll> v;
bool isPrime(ll n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (ll i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void primeFactors(int n) {
  while (n % 2 == 0) {
    v.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      v.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) v.push_back(n);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  if (q == 1 || isPrime(q)) return cout << 1 << "\n" << 0 << "\n", 0;
  primeFactors(q);
  if (v.size() > 2)
    cout << 1 << "\n" << v[0] * v[1] << "\n";
  else
    cout << 2 << "\n";
  return 0;
}
