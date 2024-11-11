#include <bits/stdc++.h>
long long power(long long base, long long exp) {
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base);
    base = (base * base);
    exp /= 2;
  }
  return res;
}
long long mod(long long a, long long b) { return (a % b + b) % b; }
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, d;
    cin >> n >> d;
    if (d <= n)
      cout << "YES" << '\n';
    else {
      if (power(n + 1, 2) - 4 * d > 0)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
