#include <bits/stdc++.h>
using namespace std;
const long long N = 500;
const long long INF = 1e17;
const long long mod = 1e9 + 7;
long long a[6];
int main() {
  long long n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  a[4] = 2, a[5] = 4;
  if (n == 1) return cout << m / 6 * 6 + a[m % 6], 0;
  if (n == 2 && m <= 2) return cout << 0, 0;
  if (n == 2 && m == 3 || n == 2 && m == 7) return cout << n * m - 2, 0;
  if (n == 2) return cout << n * m, 0;
  if (n % 2 == 1 && m % 2 == 1) return cout << n * m - 1, 0;
  cout << n * m;
}
