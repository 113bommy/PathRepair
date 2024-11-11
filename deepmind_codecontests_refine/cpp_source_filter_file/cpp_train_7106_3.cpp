#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b > a) return gcd(b, a);
  return b == 0 ? a : gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long s[n];
  for (long long i = 0; i < n; i++) cin >> s[i];
  long long a[m];
  for (long long i = 0; i < m; i++) cin >> a[i];
  long long em = pow(2, 9) - 1;
  for (long long k = 0; k < em; k++) {
    long long f = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if ((k | (s[i] & a[j])) == k) {
          f++;
          break;
        }
      }
    }
    if (f == n) {
      cout << k << endl;
      break;
    }
  }
  return 0;
}
