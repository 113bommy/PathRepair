#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long n, k, x;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  x = k;
  for (int i = 1, a; i <= n; ++i) cin >> a, x = gcd(a, x);
  cout << (k - 1) / x + 1 << endl;
  for (int i = 0; i * x < k; ++i) cout << i * x << " ";
  cout << endl;
  return 0;
}
