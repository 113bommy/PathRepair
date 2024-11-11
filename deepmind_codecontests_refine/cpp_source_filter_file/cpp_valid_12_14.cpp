#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == 1 || b == 1) return 1;
  if (a == b) return a;
  if (a > b)
    return gcd(b, a % b);
  else
    return gcd(a, b % a);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int long long n, m, k;
    cin >> n >> m >> k;
    if (n == 1) {
      if (k == m * n / 2)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
      continue;
    }
    if (m == 1) {
      if (k == 0)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
      continue;
    }
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    } else if (n % 2 == 1 && m % 2 == 0) {
      if (k < m / 2)
        cout << "NO"
             << "\n";
      else if (k > m / 2 && (k - m / 2) % 2 == 0)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    } else {
      if (k > (m - 1) * n / 2)
        cout << "NO"
             << "\n";
      else if (k % 2 == 0 || k == (m - 1) * n / 2)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    }
  }
  return 0;
}
