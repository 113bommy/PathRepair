#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
ll mod = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  ll sum = 0LL;
  ll prod = 1LL;
  for (ll i = n; i > 1; i--) {
    prod *= i;
    sum += prod;
    prod %= mod;
    sum %= mod;
  }
  cout << ((prod * n) % mod - sum) % mod;
}
