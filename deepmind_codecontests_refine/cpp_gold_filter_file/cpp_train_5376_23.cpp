#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t m, n, res, pow_n;
  cin >> n >> m;
  if (log2(m) >= n) {
    pow_n = exp2(n);
    res = m % pow_n;
  } else {
    res = m;
  }
  cout << res;
}
