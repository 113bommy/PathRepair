#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef std::vector<pll> vpll;
void boost() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
template <class T>
bool is_prime(T n) {
  if ((n % 2 == 0 and n > 2) or n < 2) return false;
  for (T i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  ll n, i, val1 = 0, val2 = 0;
  cin >> n;
  vector<ll> a(n), b(n);
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  i = 0, val1 = 0, val2 = 0;
  vector<char> v;
  for (i = 0; i < n; i++) {
    if (abs(a[i] + val1 - val2) <= 500) {
      val1 += a[i];
      v.push_back('A');
    } else if (abs(b[i] + val2 - val1) <= 500) {
      val2 += b[i];
      v.push_back('G');
    }
  }
  for (i = 0; i < n; i++) {
    cout << v[i] << ' ';
  }
}
int main() {
  boost();
  ll t;
  t = 1;
  while (t--) solve();
  return 0;
}
