#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  if (n == 1) {
    cout << "1 1"
         << "\n";
  } else {
    long long int minn = n;
    vector<long long int> v;
    vector<long long int> vv;
    long long int a = 1, b = n;
    for (long long int i = 1; i <= sqrt(n); i++) {
      if (n % i == 0) {
        long long int x = n / i;
        if (gcd(i, x) == 1) {
          long long int k = max(i, x);
          if (k < minn) {
            a = min(i, x);
            b = max(i, x);
            minn = k;
          }
        }
      }
    }
    cout << a << " " << b << "\n";
  }
  return 0;
}
