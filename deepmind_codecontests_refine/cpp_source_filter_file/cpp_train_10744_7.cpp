#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int x, long long int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long exp(long long a, long long b) {
  if (b == 0) return 1;
  long long res = exp(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t, a, b, c, k, l;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    k = max(a, b);
    l = max(k, c);
    if (2 * l > a + b + c + 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
