#include <bits/stdc++.h>
using namespace std;
long long int n, fv[100002], fv2[100002], i, x, y;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed;
  cin >> n;
  n = n * n;
  for (i = 1; i <= n; ++i) {
    cin >> x >> y;
    if (!fv[x] && !fv2[y]) {
      cout << i << " ";
      fv[x] = 1;
      fv2[y] = 1;
    }
  }
  return 0;
}
