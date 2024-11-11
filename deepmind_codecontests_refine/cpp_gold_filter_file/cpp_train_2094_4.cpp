#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, k;
  cin >> n >> m >> k;
  if ((2 * n * m) % k != 0) {
    cout << "NO";
    return 0;
  }
  long long k1 = k;
  if (k % 2 == 0) k /= 2;
  long long g1 = gcd(n, k);
  k /= g1;
  long long g2 = gcd(m, k);
  long long a = n / g1;
  long long b = m / k;
  if (k1 % 2 != 0) {
    if (a < n)
      a = a * 2;
    else
      b *= 2;
  }
  cout << "YES" << endl;
  cout << "0 0" << endl;
  cout << a << " 0" << endl;
  cout << "0 " << b;
  return 0;
}
