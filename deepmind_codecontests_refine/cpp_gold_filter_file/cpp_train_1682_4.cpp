#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
long long int GCD(long long int x, long long int y) {
  if (x < y) swap(x, y);
  if (y == 0) {
    return x;
  } else {
    return GCD(y, x % y);
  }
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> x(n);
  for (long long int i = 0; i < n; i++) cin >> x[i];
  for (long long int i = 1; i < n; i++) {
    x[i] -= x[0];
  }
  vector<long long int> p(m);
  for (long long int i = 0; i < m; i++) cin >> p[i];
  long long int gcd = x[1];
  for (long long int i = 2; i < n; i++) {
    gcd = GCD(gcd, x[i]);
  }
  for (long long int i = 0; i < m; i++) {
    if (gcd % p[i] == 0) {
      cout << "YES" << endl;
      cout << x[0] << " " << i + 1 << endl;
      return;
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int t = 1;
  while (t--) solve();
  return 0;
}
