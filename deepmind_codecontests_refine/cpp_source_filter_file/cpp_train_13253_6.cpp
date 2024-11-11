#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int exp(int x, int y) {
  int res = 1;
  while (y) {
    if (y % 2) res = 1LL * res * x % MOD;
    x = 1LL * x * x % MOD;
    y /= 2;
  }
  return res;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  if (k == 1) {
    cout << exp(m, n) << endl;
  } else if (k == n) {
    cout << exp(m, (1 + n) / 2) << endl;
  } else {
    if (k % 2)
      cout << exp(m, 2) << endl;
    else
      cout << m << endl;
  }
  return 0;
}
