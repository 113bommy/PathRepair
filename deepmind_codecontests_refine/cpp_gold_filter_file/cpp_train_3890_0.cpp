#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-11;
const double PI = 2 * acos(0.0);
using ll = long long;
using ull = unsigned long long;
ll bigmod(ll a, ll n, ll m) {
  if (n == 0) return 1;
  ll first = bigmod(a, n / 2, m);
  first = (first % m * first % m) % m;
  if (n & 1) first = (a % m * first % m) % m;
  return first;
}
int main() {
  ll n, m;
  cin >> n >> m;
  ll ans = bigmod(3, n, m);
  cout << ((ans - 1) + m) % m << endl;
  return 0;
}
