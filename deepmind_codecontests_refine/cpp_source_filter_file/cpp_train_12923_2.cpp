#include <bits/stdc++.h>
using namespace std;
const long long N = 300005;
long long a[N];
long long n, m;
string s;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long i, j, k, T, u, v, p, q, r, d;
  cin >> n >> m;
  long long ans = 9223372036854775807;
  i = 2;
  while (i <= m) {
    if (i * i > m) i = m;
    long long count = 0;
    while (m % i == 0) {
      m /= i;
      ++count;
    }
    if (count > 0) {
      long long power = 0;
      long long base = 1;
      while (n / base > i) {
        base *= i;
        power += n / base;
      }
      ans = min(ans, power / count);
    }
    ++i;
  }
  cout << ans;
}
