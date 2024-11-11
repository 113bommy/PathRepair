#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long mod) {
  long long c = 1;
  while (b > 0) {
    if (b % 2) c *= a, c %= mod;
    b /= 2;
    a *= a;
    a %= mod;
  }
  return c;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  if ((n == 1) && (m > 2)) {
    cout << "1\n1 " << m << " 1 1\n";
    for (long long i = 1; i <= m; i++) {
      cout << "1 " << i << "\n";
    }
    cout << "1 1\n";
    return 0;
  } else if ((m == 1) && (n > 2)) {
    cout << "1\n"
         << n << " 1"
         << " 1 1\n";
    for (long long i = 1; i <= n; i++) {
      cout << i << " 1"
           << "\n";
    }
    cout << "1 1\n";
    return 0;
  }
  if ((n * m) % 2 != 0) {
    if (m % 2 == 0)
      cout << "1\n"
           << n << " " << m << " "
           << "1"
           << " " << m << "\n";
    else {
      cout << "1\n"
           << n << " " << m << " " << m << " 1"
           << "\n";
    }
  } else
    cout << "0\n";
  cout << "1 1\n";
  long long c = 1;
  while (1) {
    if ((m & 1) == 0) {
      if (c > m) break;
      for (long long i = 2; i <= n; i++) cout << i << " " << c << "\n";
      c++;
      if (c > m) break;
      for (long long i = n; i >= 2; i--) cout << i << " " << c << "\n";
      c++;
    } else {
      if (c > n) break;
      for (long long i = 2; i <= m; i++) cout << c << " " << i << "\n";
      c++;
      if (c > n) break;
      for (long long i = m; i >= 2; i--) cout << c << " " << i << "\n";
      c++;
    }
  }
  if ((m & 1) == 0) {
    for (long long i = m; i >= 1; i--) cout << "1 " << i << "\n";
  } else {
    for (long long i = n; i >= 1; i--)
      cout << i << " 1"
           << "\n";
  }
}
