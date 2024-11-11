#include <bits/stdc++.h>
using namespace std;
int modInverse(int a, int m) {
  int m0 = m;
  int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  m = 2 * m;
  long int M = 1000000007;
  long long int ans = 1;
  int i, j;
  for (i = 1; i <= m; i++) {
    ans = ((ans * (n - 1 + i)) % M * modInverse(i, M)) % M;
  }
  cout << ans << "\n";
  return 0;
}
