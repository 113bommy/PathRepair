#include <bits/stdc++.h>
using namespace std;
uint64_t P = 10e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  uint64_t n, m, k;
  cin >> n >> m >> k;
  uint64_t r = 1;
  if (k == 1 || k > n) {
    while (n-- > 0) {
      r = (r * m) % P;
    }
  } else if (k == n) {
    n = (n + 1) / 2;
    while (n-- > 0) {
      r = (r * m) % P;
    }
  } else if (k % 2) {
    r = m * m;
  } else {
    r = m;
  }
  cout << r;
  return 0;
}
