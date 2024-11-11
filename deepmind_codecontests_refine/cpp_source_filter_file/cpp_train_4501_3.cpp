#include <bits/stdc++.h>
using namespace std;
int dt[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0}};
long long quickPower(long long a, long long b) {
  long long res = 1;
  a %= 998244353;
  while (b) {
    if (b & 1) res = (res % 998244353) * (a % 998244353) % 998244353;
    a = (a % 998244353) * (a % 998244353) % 998244353;
    b >>= 1;
  }
  return res;
}
long long inv(long long x) { return quickPower(x, 998244353 - 2); }
long long C(long long n, long long m) {
  if (m > n) return 0;
  long long up = 1, down = 1;
  for (int i = n - m + 1; i <= n; i++) up = up * i % 998244353;
  for (int i = 1; i <= m; i++) down = down * i % 998244353;
  return up * inv(down) % 998244353;
}
long long Lucas(long long n, long long m) {
  if (m == 0) return 1;
  return C(n % 998244353, m % 998244353) * Lucas(n / 998244353, m / 998244353) %
         998244353;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  if (n == 2) {
    cout << 1;
    return 0;
  }
  cout << (Lucas(m, n - 1) % 998244353 * (n - 2) % 998244353 *
           quickPower(2, n - 3) % 998244353) %
              998244353;
}
