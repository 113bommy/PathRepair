#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, i = 0, j = 0, k = 0, l = 0, m = 0, a = 0, b = 0, sum = 0, x = 0,
               y = 0, z = 0, c, p;
  cin >> n >> k;
  int d[5], fac[5];
  d[0] = 1;
  d[1] = 0;
  d[2] = 1;
  d[3] = 2;
  d[4] = 9;
  fac[0] = fac[1] = 1;
  fac[2] = (n * (n - 1)) / 2;
  fac[3] = (n * (n - 1) * (n - 2)) / 6;
  fac[4] = (n * (n - 1) * (n - 2) * (n - 3)) / 24;
  for (i = 0; i <= k; i++) {
    sum += fac[i] * d[i];
  }
  cout << sum;
  return 0;
}
