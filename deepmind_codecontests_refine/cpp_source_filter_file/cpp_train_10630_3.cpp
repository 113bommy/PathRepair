#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
long long int n, m, k, b[200009];
void Inp() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
}
long long int poww(long long int p, long long int q) {
  if (q == 0) {
    return 0;
  }
  if (q == 1) {
    return p;
  }
  long long int t = poww(p, q / 2);
  if (q % 2 == 0) {
    return (t * t) % mod;
  } else {
    return (((t * t) % mod) * p) % mod;
  }
}
void Solve() {
  long long int kq = poww(k, n - 2 * b[m]);
  for (int i = m; i >= 1; i--) {
    long long int l = (b[i] - b[i - 1]);
    kq = (kq * ((poww(k, l) * (poww(k, l) - 1) / 2) % mod + poww(k, l))) % mod;
  }
  cout << kq;
}
int main() {
  Inp();
  Solve();
}
