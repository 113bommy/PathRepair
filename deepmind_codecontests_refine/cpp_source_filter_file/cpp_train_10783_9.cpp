#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000, MAXM = 1000, MAXK = 1000000;
uint64_t n, m;
uint64_t double_solve() { return ceil((sqrt(4 + (n << 1)) - 1) / 2); }
uint64_t bin_solve() {
  uint64_t l, r, c, sqr, n2 = 2 * (n - m);
  l = 0;
  r = sqrt(2 * n);
  while (r - l > 1) {
    c = (l + r) / 2;
    sqr = c * c;
    if (sqr + c > n2) {
      r = c;
    } else {
      l = c;
    }
  }
  return l * l + l >= n2 ? l : r;
}
int main(int argc, char *argv[]) {
  cin >> n >> m;
  if (n <= m) {
    cout << n << endl;
    return 0;
  }
  cout << m + bin_solve() << endl;
  return 0;
}
