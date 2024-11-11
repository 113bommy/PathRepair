#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if ((2 * n * m) % k != 0) {
    cout << "NO" << endl;
    return;
  } else {
    cout << "YES" << endl;
  }
  long long flag = 0;
  if (k % 2 == 0) {
    flag = 1;
    k /= 2;
  }
  long long g = gcd(n, k);
  long long n1 = n / g;
  k = k / g;
  long long m1 = m / k;
  if (!flag) {
    if (n1 < n) {
      n1 *= 2;
    } else {
      m1 *= 2;
    }
  }
  cout << "0 0" << '\n' << "0 " << m1 << '\n' << n1 << " 0" << endl;
}
int main() {
  long long t = 1;
  while (t--) {
    solve();
  }
}
