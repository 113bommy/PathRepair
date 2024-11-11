#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
complex<long long> x[N], m[N];
inline void read(complex<long long> &a) {
  long long x, y;
  cin >> x >> y;
  a = complex<long long>(x, y);
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  read(m[0]);
  for (int i = 0; i < n; i++) read(x[i]);
  for (int i = 1; i < 2 * n; i++) {
    m[i] = x[(i + n - 1) % n] * 2LL - m[i - 1];
  }
  cout << m[q % (2 * n)].real() << " " << m[q % (2 * n)].imag() << endl;
}
