#include <bits/stdc++.h>
using namespace std;
bool IsPrime(long long x) {
  bool isPrime = true;
  for (long long a = 2; a * a <= x; a++) {
    if (x % a == 0) return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, s, k;
  cin >> n >> m;
  s = m + n;
  string a;
  if (n > m + 1) {
    cout << "-1";
    return 0;
  }
  if (2 * n + 2 <= m) {
    cout << "-1";
    return 0;
  }
  for (long long i = 0; i < s; i++) {
    k = 0;
    if (n <= m) {
      if (i == 0 || i == 1 && m > 0) {
        a += '1';
        m--;
      }
      if (i > 1)
        if (a[i - 1] != '1' || a[i - 2] != '1' && m > 0) {
          a += '1';
          m--;
        } else if (n > 0) {
          a += '0';
          n--;
        }
    } else if (n > 0) {
      a += '0';
      n--;
    }
  }
  cout << a;
}
