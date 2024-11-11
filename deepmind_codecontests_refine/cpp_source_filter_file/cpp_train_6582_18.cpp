#include <bits/stdc++.h>
using namespace std;
long long nCr(int n, int r) {
  if (r == 1) return 1;
  return n * nCr(n - 1, r - 1) / r;
}
int main() {
  long long b, g, t, i = 4, ans = 0;
  cin >> b >> g >> t;
  while (i < t) ans += nCr(b, i) * nCr(g, (t - i)), i++;
  cout << ans << endl;
  return 0;
}
