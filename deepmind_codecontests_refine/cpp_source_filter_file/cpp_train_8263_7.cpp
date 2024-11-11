#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000009;
int main() {
  int n, m, a;
  scanf("%d", &n);
  m = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (a == 1) {
      ++m;
    }
  }
  long long x = 1, y = 1;
  for (int i = 0; i < m; ++i) {
    long long z = y + (i + 1) * x % MOD;
    x = y;
    y = z;
  }
  for (int i = m + 1; i <= n; ++i) {
    x = x * i % MOD;
  }
  cout << x << endl;
  return 0;
}
