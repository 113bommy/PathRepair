#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int binarymul(long long int a, long long int n, long long int m) {
  long long int res = 1;
  while (n) {
    if (n % 2) {
      res = (res * a) % m;
      n--;
    }
    a = (a * a) % m;
    n /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    long long int min = n * (a - b);
    long long int max = n * (a + b);
    if (max < (c - d) || min > (c + d))
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}
